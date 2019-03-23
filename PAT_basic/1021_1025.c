/*  1021 个数统计 Number Statistics
#include<stdio.h>
int main(){
  char s[1001];
  int result[10]={0};
  int i,j;
  scanf("%s",&s);
  for(i=0;s[i]!='\0';i++)
  {  
     j=s[i]-'0';
     result[j]++;
  }
  for(i=0;i<10;i++)
      if(result[i]!=0) printf("%d:%d\n",i,result[i]);
  return 0;
}*/


/*  1022   D进制的A+B 
#include<stdio.h>
int main(){
    long int a,b,c,sum;//20^30-1,还是用长整形吧
int s[1001];
   int i,j;//必须先定义完才能开始执行输入输出等
scanf("%ld %ld %d",&a,&b,&c);
   sum=a+b;
   if (sum==0) printf("0");//测试点3.题目只说输入不为负（可以输入0+0） 
   else
   {   for(i=0;sum!=0;i++)
  {   
  s[i]=sum%c;
  sum/=c;


  }
  while(i--)
  {
  printf("%d",s[i]);
  }


   }


 return 0;
}*/


/*1023  组个最小数   
#include<stdio.h>




int main(){
    int s[51];
int i,j,k,flag=0;
for(i=0;i<10;i++)
{ scanf("%d",&k);
        for(j=0;j<k;j++)
s[flag++]=i;//从小到大排列相应数字

}

s[flag]=-1;
if(s[0]!=0) //没有0就按照原数组输出
{ for(i=0;s[i]!=-1;i++)
printf("%d",s[i]);
}
else 
{for(i=0;s[i]!=-1;i++)//挑出最小的不为0数放在第一位
if(s[i]!=0)  {printf("%d",s[i]); s[i]=0;break;}
for(i=1;s[i]!=-1;i++)
printf("%d",s[i]);
}
return 0;
}*/




/*1024  科学计数法 scientific notation
#include<stdio.h>
int main(){
  char s[10000];
  int flag=9999;//flag用来区分数组中的数字属于前面的常数还是后面的指数（是否大于flag）
  int zhishu[5];    //存放指数位
  int last=0;//表示指数
  int i,j,k=0,n;
  char temp;
  gets(s);
  for(i=1;s[i]!='\0';i++)
  { 


if(s[i]=='+'||s[i]=='-') flag=i;//flag就是指数的符号位
if(i>flag) zhishu[k++]=s[i]-'0';//大于flag就是指数
  }
  for(i=0;i<k;i++)
  { 
  last=last*10+zhishu[i];
  }
//  printf("%d %d//",flag,last);
  n=flag-4;//n表示前面数字的位数，因为有‘E’‘+/-’‘x’‘.’，所以要-4
  if(s[0]=='-') printf("-");


  if(s[flag]=='+')
  {
 if(last==0)//指数可能为0
 { for(i=1;i<flag-1;i++)
printf("%c",s[i]);

 }  
 else if(n>=last)//指数小于（E前面）位数
 {
 for(i=0;i<last;i++)//将小数点后移
 {
 temp=s[2+i];
 s[2+i]=s[3+i];
 s[3+i]=temp;
 }
 if(n>last)
 for(i=1;i<n+3;i++)//测试点4，-12.3456789E+5
 printf("%c",s[i]);
 if(n==last)//测试点3？ -1.23456E+5
 for(i=1;i<n+2;i++)
 printf("%c",s[i]);

 }


 


 else//指数大于位数
 {
         for(i=0;i<last-n;i++)//将不够的位数置0
{ 
s[3+n+i]='0';
}
for(i=0;i<last;i++)//小数点后移
{   temp=s[2+i];
s[2+i]=s[i+3];
s[i+3]=temp;
}
for(i=1;i<last+2;i++)
 printf("%c",s[i]);

 }
   


  }
  else//flag=='-'
  {
 if(last==0)
 for(i=1;i,flag-1;i++)
 printf("%c",s[i]);
    else 
{
printf("0.");//指数为负数时，结果一定是    -0.*（指数-1个0）*常数
for(i=0;i<last-1;i++)
printf("0");//
for(i=1;i<flag-1;i++)
if(s[i]!='.') printf("%c",s[i]);
}
 
  }
  
  
}*/




//1025 反转链表 reverse chain table
/*                    反正最多也不超过10000，干脆将原本的是s【i】.add直接变成s[add].add,大量减少下一次排序的寻找时间。
#include<stdio.h>   //一开始直接用s【i】存，再用循环一个个将数据往前排，结果倒数第二个测试点过不去，运行超时
#include<malloc.h>


struct list{
    int add;//一开始用的char数组，反正用int也行，何必呢
int data;
int next;
};
int main(){
struct list *s=malloc(100000*sizeof(struct list));
struct list temp;
struct list *ans=malloc(100000*sizeof(struct list));
int i,j,g=0,i2=0;//g用来第一次排序且，i2用于第二次
int first,n,k;//第一行的三个数
int flag;
int next;
int add;
     scanf("%d %d %d",&first,&n,&k);
     for(i=0;i<n;i++)
{   scanf("%d",&add);//直接以add作为为下标，将scnaf数据存入s【add】
scanf("%d %d",&s[add].data,&s[add].next);//注意，要先确定add的值，所以要等scanf-add语句结束后再输入s【add】.datad。
s[add].add=add;//不要忘记了，此时我们真正的S[add].add还没赋值
   if(add==first) flag=add;//看哪一个是首地址
}
     ans[0]=s[flag];
i=0;
next=ans[0].next;
     // printf("%d %d %d第一个\n",ans[0].add,ans[0].data,ans[0].next);
while(next!=-1) 
{
       ans[i+1]=s[next];
  next=ans[i+1].next;
  i++;//计数器，有效个数（未加一）。 有些输入根本就不在链表里
}
g=i+1;//有效个shu
     // printf("%d",g);
 
   flag=g/k;//链表反转的次数
                           // 先用S存scanf输入的数据，再用ans存顺序排序的，再次用赋值的方式给S存放最终排序结果
   for(i=0;i<g;i++)
s[i]=ans[i];
    for(i=0;i<flag;i++)//反转链表
for(j=k-1;j>=0;j--)
{s[i2++]=ans[i*k+j];}


for(i=0;i<g;i++)
   { if(i<g-1)  printf("%05d %d %05d\n",s[i].add,s[i].data,s[i+1].add);//%05d   显示五位，不够补零
        if(i==g-1) printf("%05d %d -1",s[i].add,s[i].data);
   } 
  
return 0;
}*/
