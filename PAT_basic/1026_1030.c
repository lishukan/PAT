/*1026  程序运行时间  Program run time
#include<stdio.h>


int main(){
float start ,end;
float time;
int t,h,m,s;
scanf("%f %f",&start,&end);
time=(end-start)/100;
time+=0.5;//四舍五入
t=(int)time;
h=t/3600;
m=(t%3600)/60;
s=t%60;
printf("%02d:%02d:%02d",h,m,s);
return 0;
}*/




//1027 打印沙漏 print hourglass
/*
#include<stdio.h>
int main(){
int n,i=0,j=0,sum=0,k=0;
char c;
int s[1000];
    int left,count=0,flag;
//scanf("%d",&n);
scanf("%d %c",&n,&c);
if(n==1) printf("%c\n0",c);//测试点2


else 
{   
s[0]=1;
sum=1;
for(i=1;sum<=n;i++)
{
s[i]=s[i-1]+2;//   s  0  1   2  3  4
sum+=2*s[i];  // sum  
}
        sum-=2*s[i-1];
left=n-sum;


// left=n-(sum-2*(s[i-1]));//19-(31-(2*7)),还剩多少个
i-=2;//回到sum小于n时的i
while(i>=0)
{      
  for(flag=0;flag<count;flag++)
  printf(" ");
  for(j=0;j<s[i];j++)
    printf("%c",c);
//   for(flag=0;flag<count;flag++)//一开始我以为一行的两边都要打空格，wwmxd，竟然只有一边，还算格式错误
//   printf(" ");
  printf("\n");
  count++;//用于计数，每行打印的空格个数
  i--;


}
i=1;
count-=2;
while(count>=0)
{
 
  for(flag=0;flag<count;flag++)
  printf(" ");
  for(j=0;j<s[i];j++)
    printf("%c",c);
//   for(flag=0;flag<count;flag++)//一开始
//   printf(" ");
  printf("\n");
  count--;
  i++;
      
}

     printf("%d\n",left);
}
return 0;
}
*/




/* 1028 人口普查  Census
#include<stdio.h>
#include<malloc.h>
struct list{
   char s[6];
   int y;
   int m;
   int d;
};
int main(){
struct list *k=malloc(100000*sizeof(struct list));
struct list temp,old,you;
    int n;
int i,j,count=0;


scanf("%d",&n);
for(i=0;i<n;i++)
{ scanf("%s %d/%d/%d",&temp.s,&temp.y,&temp.m,&temp.d);
if(temp.y>1814&&temp.y<2014)        {      k[count++]=temp;continue;}
  else if(temp.y==1814&&temp.m>9)  {      k[count++]=temp;continue;}
  else if(temp.y==2014&&temp.m<9)  {      k[count++]=temp;continue;}
  else if(temp.y==1814&&temp.m==9)
  {
  if(temp.d>=6)                {      k[count++]=temp;continue;}
  }
  else if(temp.y==2014&&temp.m==9)
  {
  if(temp.d<=6)                {      k[count++]=temp;continue;}
  }
}

    old=k[0];
you=k[0];
    for(i=0;i<count;i++)//挑出最大最小的日子
{
             if(k[i].y>you.y)   you=k[i];
else if(k[i].y<old.y)  old=k[i];
else 
{
    if(k[i].y==you.y&&k[i].m>you.m)  you=k[i];
else if(k[i].y==old.y&&k[i].m<old.m)  old=k[i];
else 
{
    if(k[i].y==you.y&&k[i].m==you.m&&k[i].d>you.d) you=k[i];
else if(k[i].y==old.y&&k[i].m==old.m&&k[i].d<old.d) old=k[i];

}


}


}


if(count==0) printf("0");
    else if(count==1) printf("1 %s %s",old.s,old.s);//只有一个人也要输出两个名字
else 
{
     printf("%d",count);
 //  for(i=0;i<count;i++) printf("%s %d %d %d\n",k[i].s,k[i].y,k[i].m,k[i].d);
for(i=0;i<count;i++)//打印和最大的人生日相同的人的信息
if(k[i].y==old.y&&k[i].m==old.m&&k[i].d==old.d) printf(" %s",k[i].s);
for(i=0;i<count;i++)//打印最小的生日相同的人的信息
if(k[i].y==you.y&&k[i].m==you.m&&k[i].d==you.d) printf(" %s",k[i].s);
}
return 0;


}*/








//1029  旧键盘 old keyboard
/*
#include<stdio.h>
int main(){
      int s1[81],s2[80],r[80];
 char c;
 int i=0,j=0,k=0;
 int flag1,flag2;
      while((c=getchar())!='\n')//先将getchar值赋值给c再判断，不是getchar（C）；
 {
           if(c>='a'&&c<='z')  s1[i++]=c-32;
  else s1[i++]=c;



 }
   
 while((c=getchar())!='\n')
 {
if(c>='a'&&c<='z')  s2[j++]=c-32;
  else s2[j++]=c;

 }
   flag1=i;
   flag2=j;
// for(k=0;k<i;k++)
//  printf("%d ",s1[k]);
//  printf("\n");
//  for(k=0;k<j;k++)
//  printf("%d ",s2[k]);
     i=0;
     j=0;
     for(k=0;k<flag1;k++)
{
         if(s1[k]==s2[i]) i++;//一一比对是否一样，一样比对下一对（k，i都加一），不一样s1键存入R，再用下一个s1比对s2（k++，i不变）.
else   r[j++]=s1[k];     continue;
}
//  R【k】是存放没有的键的地址，（有重复）
   // for(k=0;k<j;k++)
    // printf("%d ",r[k]);
      
for(i=0;i<j;i++)
for(k=i+1;k<j;k++)
if(r[i]==r[k]) r[k]=0;//将重复的键除第一个外都置零
for(i=0;i<j;i++)//打印结果
 if(r[i]==0) continue;
 else
 {
 if(r[i]>='a'&&r[i]<='z') printf("%c",r[i]-32);  //小写变大写
 else printf("%c",r[i]);
 }
   


     return 0;




}*/




//1030   完美数列 perfect series




/*
#include<stdio.h>//此题一在找max的算法，二是对数据类型位数的掌握
#include<stdlib.h>//                     10^9 超过int，long了 只能用long long （int）
int cmp(int *a,int *b){// 返回大于0，1在2后，小于01在2前
   return *a-*b;//a>b==+>0   b(小),a(大)     b>a==-<0  a(小)b（大）   总之就是从小到大排列
}                       
int main(){
   int n;
   long long int p;//P可能大于int范围，要用此类型
   int i,j,k;
   long long int s[100001];//VC++6.0内表示2^64位只能用_int64 ,尽量不用6.0编译此题
   int sum=0;
   int max=0;//max小于n 属于int范围
   long long m;
   scanf("%d %lld",&n,&p);
   for(i=0;i<n;i++)
   { scanf("%lld",&s[i]);
      if(s[i]>sum) sum=s[i];//记录最大数
   }
   if(sum<=p) printf("%d",n);//如果最大数还小于P，肯定所有数都小于，直接输出N
   else
   {


     qsort(s,n,sizeof(s[0]),cmp);//从小到大排序
     //for(i=0;i<n;i++)
     //  printf("%d ",s[i]);printf("\n");
     for(i=0,max=1;i<n;i++)
     {   if(s[i]==s[i-1]) continue;//相邻一样的数就不用算了
      else
      {     
           m=p*s[i];//                                                                    10 8     123456789 20
         for(j=i+max;j<n;j++)//倒数第二测试点，考验算法。
         { if(s[j]<=m)   max++;//         设i有max个满足条件数，下一次计算i+1的满足数目，只需看i+1后面max位是不是还满足。
           else break;   //                     满足，max++，继续往i+1+max后看是否满足。不满足，跳出循环，不考虑之后的数（排序后后面一定大于等于前面）。再回来来看i+2的
         }                                       //这就省略了从i到i+max的判断你是否满足条件的步骤，一开始用这种，而且还没加break，导致倒数第二测试点一直超时
      //   if(k>max) max=k;     //测试点1   n个都是一样的
      }
     }
  
     printf("%d",max);
   }
 return 0;
}
*/
