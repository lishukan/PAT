// 1056 组合数的和
//只要认清形势---
/*
#include<stdio.h>
int main(){
int n,i,j,a[11],sum=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{ scanf("%d",&a[i]);
       sum+=(n-1)*a[i]*11;//这就是形势！1！，无论输入什么，最后肯定要加上n-1个这个数的十倍，和n-1个这个数。
  }                       //   假设 A ,B,C   无论如何 ，一定有2*A*10+2*A (B,C同理)，A*10+B   A*10+C  B*10+A B*10+C C*10+A C*10+B
printf("%d",sum);
return 0;
}*/




// 1057 数零壹
/*   只要认清形势--
#include<stdio.h>
int main(){
char c;
long sum=0;
int flag0=0,flag1=0;
while((c=getchar())!='\n')
{
if(c>='A'&&c<='Z') sum+=c-'A'+1;
else if(c<='z'&&c>='a') sum+=c-'a'+1;
else continue;
}
while(sum!=0)
{
if(sum%2==1) flag1++;    //形势很简单吧，进制转换的除法
else flag0++;
        sum/=2;
}
printf("%d %d",flag0,flag1);
return 0;
}*/


// 1057 选择题 


//  注意注意，，最后一行输出的2 2 34 ，我以为是2（次数）-2（序号） 3（次数）-4（序号） ，我说那这题目不是错了吗，原来是2 （次数）  2 3 4 （序号） 
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ans{
   int score;
   int choice;
   int right;
   char s[15];//我的方法没有考虑去除空格，所以答案是带空格的字符串，因此字符串长度要很大（最后一个测试点，答案很多很长的情况）
};
struct wrong{// 有错的题目
     int number; // 题目序号
int sum; // 错误次数
};
int cmp(const void *a,const void *b){
struct wrong *c=(wrong *)a;
struct wrong *d=(wrong *)b;
if(c->sum>d->sum) return -1;
else if(c->sum<d->sum) return 1;
else 
{
if(c->number<d->number) return -1;
else return 1;
}
}
 int main(){
int n,m,best,i,j;
struct ans gg[100];
char c;
    struct wrong shit[1001];//错误信息
int student[1001]={0};//每个学生的成绩
int tempi,k=0;
char temps[15];//我的方法没有考虑去除空格，所以答案是带空格的字符串，因此字符串长度要很大（最后一个测试点，答案很多很长的情况）
scanf("%d %d",&n,&m);
for(i=0;i<m;i++)// m个题目
    {   shit[i].number=i;
   shit[i].sum=0;
scanf("%d %d %d",&gg[i].score,&gg[i].choice,&gg[i].right);
     gets(gg[i].s);// 将之后的输入直接当成一个带空格的字符串，也就是答案还包括空格 
}
// for(i=0;i<m;i++)
// { printf("%d %d %d\n",i,gg[i].score,gg[i].choice,gg[i].right);
//  printf("---%s\n",gg[i].s);
// }
for(i=0;i<n;i++)// n个学生
{
for(j=0;j<m;j++)// 每个学生的答案
{  scanf("(%d",&tempi);
    // if(tempi!=gg[j].choice) wrong[j]++;
 k=0;
 while((c=getchar())!=')')
 {
              temps[k++]=c;
 }
 temps[k]='\0';
//  printf("\n*****%s****\n",temps);
 if(strcmp(temps,gg[j].s)==0) //  两个字符串相等 ，答案相同
 {
 student[i]+=gg[j].score;
 }
 else shit[j].sum++;
 c=getchar();//仔细比较输出结果，发现要加个getchar ，不然 ）会被存进下一个输入
 if(c==')') continue;
}
}
// 结算
for(i=0;i<n;i++)
printf("%d\n",student[i]);
// printf("*********");
// for(i=0;i<m;i++)
// printf("%d %d *** ",shit[i].sum,shit[i].number+1);
// printf("\n");
qsort(shit,m,sizeof(shit[0]),cmp);//排序
    if(shit[0].sum==0) printf("Too simple");//  错的最多的竟然只是0
else 
{printf("%d %d",shit[0].sum,shit[0].number+1);   // 题目顺序是从1开始，这里要加1
// printf("\ndsdfsffgdggdafakjsafjhdkasdja\n");
// for(i=0;i<m;i++)
// printf("%d %d--",shit[i].sum,shit[i].number+1);
// printf("\n");
i=1;
while(shit[i].sum==shit[i-1].sum&&i<m)
{  printf(" ");
printf("%d",shit[i].number+1);
i++;
}
}
return 0;
}
 
*/


// 1059 C语言竞赛
/*
#include<cstdio>
#include<cmath>
#include<iostream>
#include<string.h>
using namespace std;
int judge(int& x){
     int i;
for(i=2;i<=sqrt(x);i++)
if(x%i==0) return 1; //不是素数
return 0; //是素数
}
int main(){
int n,k,i,j;
int number[10001][2]={0};   // number【】【0】存放排名，【】【1】存放查询次数
int temp;
scanf("%d",&n);
for(i=0;i<n;i++)
{ scanf("%d",&temp);
  number[temp][0]=i+1;//存放第几名,如果为零说明这参赛者号码不存在
  }
     scanf("%d",&k);
for(i=0;i<k;i++)
{
scanf("%d",&temp);
   printf("%04d:",temp); 
        if(number[temp][0]==0) //没有
printf(" Are you kidding?\n");
  else //有
{
  if(number[temp][1]==0) //一次也没查过
  { 
 if(number[temp][0]==1)  //第一名
 {  
 printf(" Mystery Award\n");
      
 }
  else  
  {if(judge(number[temp][0])==0) //素数
 printf(" Minion\n");
  else printf(" Chocolate\n");
  }
  }
  else printf(" Checked\n"); // 已经查过
   number[temp][1]++;// 查完就加一次


}

}


return 0;
}*/


// 1060 爱丁顿数
/* 发生了一个段错误，我一直找不出，原来是数组还不够大，题目明明说N《=10^5,我一开始定义A【100001】,竟然还不够，非要定义到10的6次方，这太坑了啊·
#include<stdio.h>
int main(){
long n,i,temp;//担心数据太大相加可能超过int范围，其实我多虑了
long  max=0,e=0;//都是那坑爹 的题目，明明说小于等于10的五次方，实际要定义到6次方才行，wtf！！！
long  sum=0;//    
long a[1000000]={0};  // 更可气的是，VC里根本无法定义到10的6次方，运行崩溃
scanf("%d",&n);         //  本省考点里只有VC和devc，能怎么办呢
for(i=0;i<n;i++)
{ scanf("%ld",&temp);
      a[temp]++;//这个数出现的次数
 if(temp>max) max=temp;//里程里的最大值
}
for(;max>=0;max--)//从最大值开始
{    
// printf("a[%d]=%d***",max,a[max]);
  if(a[max]>0) //说明这个值存在
{ sum+=a[max];// sum为大于max-1的数的个数
// printf("%d --%d\n",sum,max);
}
    else continue;
if(sum>=(max-1))    {e=max-1;break;}//如果满足条件，注意，e=此时的max的下一位
}
printf("%ld",e);
return 0;
}


*/
