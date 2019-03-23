1051 复数乘法 
/*
#include<stdio.h>
#include<math.h>
int main(){
  double a,b,c,d;
  double s1,s2,x1,x2;
  double flag;
  double first;
  scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
  s1=a*cos(b);
  s2=c*cos(d);
  x1=a*sin(b);
  x2=c*sin(d);
  first=s1*s2-x1*x2;
  flag=s1*x2+s2*x1;
 // first=a*c*cos(b+d);
 // flag=a*c*sin(b+d);
  if(fabs(first)<0.01) first=0;       //这里要当心，保留两位小数，要小于0.01才当成0
  if(fabs(flag)<0.01) flag=0;
   printf("%.2lf",first);
   if(flag>=0) printf("+%.2lfi",flag);   
   else printf("%.2lfi",flag);
    
  return 0;
}*/


// 1052 卖个萌
/*
#include<iostream>
using namespace std;
int read(char s[][6]){
    char c;
int i=0,j=0;
    while((c=getchar())!='\n')
{
char temp;
if(c=='[')  //等于【时开始存入表情
{
while((temp=getchar())!=']')
{
s[i][j]=temp;j++;
}
if(temp==']')  { s[i][j]='\0';i++;j=0;}//存完后，j要置零，末尾s【i】【j】记得加‘\0’
}
}
return i;//表情长度
}
int main(){
char hand[12][6];
char eye[12][6];
char mouth[12][6];
    char ch,temp;
int i=0,j=0;
int k;
int fh,fe,fm;
    fh=read(hand);
fe=read(eye);
fm=read(mouth);
    scanf("%d",&k);
int a,b,c,d,e;
    for(i=0;i<k;i++)
{ scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
if(a>fh||b>fe||c>fm||d>fe||e>fh||a<1||b<1||c<1||d<1||e<1) printf("Are you kidding me? @\\/@\n");//每次打印完要换行，以免防止格式错误（第三个测试点）
else//      注意，既要abcde是否大于表情长度，又要考虑，是否小于1？（第二个测试点）
{
           printf("%s(%s%s%s)%s\n",hand[a-1],eye[b-1],mouth[c-1],eye[d-1],hand[e-1]);
}
    }
return 0;


}*/






//1053 住房空置率
/*
#include<iostream>
using namespace std;
int main(){
int n;
double e;
int d;
char c;
double temp,maybe=0.0,sure=0.0,num;
scanf("%d %lf %d",&n,&e,&d);
int flag;
int i,j,k;
//    n=5;e=0.5;d=10;
for(i=0;i<n;i++)
{   flag=0;
num=0.0;
scanf("%d",&k);
j=0;
while(j<k)
{
scanf("%lf",&temp);
if(temp<e) num++;
j++;
}
if(num>(j*1.0/2)) flag=1;
if(flag==1) 
{     if(j>d)  sure++; // printf("!!!!!%d!!!",i+1);}
else  maybe++;//printf("*****%d***",i+1);}
} 
}
  //  printf("%f %f\n",maybe,sure);
printf("%.1f%% %.1f%%\n",(maybe*100.0/n),(sure*100.0/n));//输出百分号要用两个%%

return 0;
}*/






//1054 求平均值
/*


#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int k;
  int i,j;
  char temp[10];
  int flag1;//正负号
  int flag2;//小数点
  int num1,num2;//小数点后位数
  int err=0;//非法输入个数
  scanf("%d",&k);
  int sure;//标记是否为正常数
    double sum=0.0,gg=0.0;
  int fuhao;
  for(i=0;i<k;i++)
  {   sure=0;
        num1=0;//小数点前位数
     num2=0;//小数点后
      flag1=0;//负号
      flag2=0;//小数点
      gg=0.0;//值
      fuhao=0;//负号位置
      scanf("%s",&temp);
  //    printf("   %d--",strlen(temp));
       for(j=0;j<strlen(temp);j++)
       {   
         if(temp[j]=='-')  
         {   flag1++;
            fuhao=j;
            if(j!=0||flag1>1)    {sure=1;break;} //负号只能在第一位,且只能有一个
         }
         else if(temp[j]=='.')    
         { flag2++;
          if(j==0||flag2>1)   {sure=1;break;}//小数点不能在第一位且最多一个
        else if(flag1==1&&j==fuhao+1)  {sure=1;break;} //小数点不能是负号下一位>>    -.38
         }
        else if(temp[j]>'9'||temp[j]<'0')  {sure=1;break;}
        else 
        {   
          if(flag2==0)    {gg=gg*10.0+(temp[j]-'0');num1++;}
           else if(flag2==1) { gg+=(temp[j]-'0')/(pow(10,num2+1));num2++;}
            
        }  
        
       }//for j 到此为止
        if(num2>2)    sure=1; //是数字，但是小数点后比两位多
     //  else if(num2==0&&flag2==1) sure=1;  //是数字，但是小数点后没有数，错误数字
      //  这题目很坑，这里竟然不能 考虑，考虑的话第四个测试点无法通过 》》》  1000.  
    //    else if(num1>1&&gg<pow(10,num1-1)) sure=1;  //  小数点前不止一位，但是0在第一位     000.38 
              else if(gg<-1000||gg>1000) sure=1;
    //    else if(flag1==1&&gg==0) sure=1;//   -0
       if(sure)//这个输入不是正常数字
       {
                printf("ERROR: %s is not a legal number\n",temp);
        err++;
       }
       else 
       {
         if(flag1==1) gg*=-1;
          sum+=gg;
       }
  //     printf("gg=%f sum=%f err=%d\n",gg,sum,err);
  //     printf("%d %d  num=%d,err=%d",flag1,flag2,num,err);
   
  }
 //  printf("%f %f\n",sum,err);


if(err==k) printf("The average of 0 numbers is Undefined\n");
 else  if(k-err==1) printf("The average of 1 number is %.2f",sum);//注意注意，这里是number不是numbers
     else printf("The average of %d numbers is %.2f",k-err,sum/(double)(k-err));
  return 0;
}*/




//1055 集体照
/*
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>
*/


#include<iostream>
#include<cstdlib>
#include<cstring>


using namespace std;
struct student{
   char name[10];
   int high;
};
int cmp(const void *f,const void *g)//重点重点，以后无论怎样都用const void *a当括号里的参数，
{
struct student *a=(student *)f;// 然后再新建所需类型的指针
struct student *b=(student *)g;
if(a->high!=b->high)  return b->high-a->high;  //   结构体排序！！！！！！！！！
else  
{
if(strcmp(a->name,b->name)<0)    return -1;//字符串排序用strcmp
else return 1;
}


}
int main(){
int n,k,i,j;
struct student s[10000];
    char temp[10000][10];//最后一个测试点，考虑到一万个只站一行呢，下标必须足够大
//struct student *s=malloc(sizeof(struct student)*10000); 这种格式只能在.C文件里，c++里似乎不能这样
scanf("%d %d",&n,&k);
for(i=0;i<n;i++)
scanf("%s %d",&s[i].name,&s[i].high);
qsort(s,n,sizeof(s[0]),cmp);
// printf("************\n");
// for(i=0;i<n;i++)
// printf("%s %d\n",s[i].name,s[i].high);
 int hang,mid;//行人数，中间位置
 int left=1,right=1,num=0,flag=0;
 for(i=0;i<k;i++)//k行
 {   
 left=1;
 right=1;
          if(i==0)  hang=n/k+n%k;//第一行（最上排）要加n%k
 else      hang=n/k;  
          mid=hang/2;//这里按下标，不是题目说的hang/2+1
// printf("%d-%d",hang,mid+1);
for(j=0;j<hang;j++)
{  //   printf("%s",s[num].name);
if(j==0) { strcpy(temp[mid],s[num++].name);//字符数组赋值不能用=，要strcpy
          //  printf("%s ",temp[mid]);
}
  else if(j%2==1)   {strcpy(temp[mid-left],s[num++].name);//printf("%s ",temp[mid-left]);
  left++;}
  else  { strcpy(temp[mid+right],s[num++].name);//printf("%s ",temp[mid+right]);
  right++;}

}
// printf("*******");
for(j=0;j<hang-1;j++)//打印每一行的人
   printf("%s ",temp[j]);
printf("%s\n",temp[hang-1]);


 }
return 0;
}
