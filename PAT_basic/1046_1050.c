//1046 划拳 
/* 
#include<stdio.h>
int main(){
int n,a,b,c,d;
int i;
int flag1=0,flag2=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d %d %d %d",&a,&b,&c,&d);
if(a+c==b&&a+c!=d)  flag1++;
else if(a+c==d&&a+c!=b) flag2++;
} 
printf("%d %d",flag2,flag1);
return 0;
 
} */


// 1047 编程团体赛
/*
#include<stdio.h>
int main(){
   int n,s[1000]={0};
   int i,a,b,c,max=0;
   int flag;
   scanf("%d",&n);
   for(i=0;i<n;i++)
  {
    scanf("%d-%d",&a,&b);
   scanf("%d",&c);
   s[a]+=c;
   if(max<s[a])
    {
      max=s[a];
 flag=a;
     }
}
 printf("%d %d",flag,max);
 return 0;
}*/


//1048 数字加密 
 //这题目真tm坑！ 题目根本没说结果是多少位，按理说既然A只是加密用的数，B才是 需要加密的数，应该按照B的位数来输出， 
 /* 
#include<stdio.h>//但题目是------按照最多位的输出，。 
#include<string.h>
int main(){
char num[10]={'0','1','2','3','4','5','6','7','8','9'};
char a[101];
char b[101];
char c;
int i=0,aaa,bbb,flag=1;
int temp;
int max;
    while((c=getchar())!=' ')
    {
     a[i]=c;
 i++; 
}
aaa=i;//A的长度 
//getchar();
i=0;
while((c=getchar())!='\n')
{
b[i]=c;
i++; 
}
bbb=i;//B的长度 
//A或B比较短的一方，需要将每位数后移，不够补零，达到长度一样。1234567-123456789》》》00123456789-123546789 
if(aaa>bbb) {//如果A长度大于B                      //   123456789-123456》》》123456789-000123456 
for(i=0;i<=bbb;i++)
    b[aaa-i]=b[bbb-i];
for(i=0;i<aaa-bbb;i++)
 b[i]='0'; 
max=aaa;
    
}
else{//B>A 
for(i=0;i<=aaa;i++)
    a[bbb-i]=a[aaa-i];
for(i=0;i<bbb-aaa;i++)
 a[i]='0'; 
max=bbb;
 
}
   
    for(i=max-1;i>=0;i--)
    {
    if(flag)//奇数 
      {  temp=a[i]-'0'+b[i]-'0';
     flag=0;
     temp%=13;
     if(temp==10) b[i]='J';
     else if(temp==11) b[i]='Q';
     else if(temp==12) b[i]='K';//这里一定注意别写错了，大小写K好难区分啊。。。 
     else b[i]=num[temp];  
  }
    else  {//偶数 
    temp=b[i]-'0'-(a[i]-'0');
    if(temp<0) temp+=10;
    b[i]=num[temp];
    flag=1;
} 
 }


for(i=0;i<max;i++)//直接用%s打印会出错，乱码。可能是数组长度确定，打印可能将没有值得位打印出来 
 printf("%c",b[i]);
 //printf("\n%s \n%s",a,b);
return 0;

}*/ 




//1049 数列的片段和
 /* 
#include<stdio.h>
int main(){
int n;
int i;
double temp,sum=0.0,flag=1.0;//必须用double，否则过不去最后两个测试点 
scanf("%d",&n);


while(n>0){
scanf("%lf",&temp);//用了double，这里就要用%lf，不然输入的数据只会保存到float长度，造成答案错误 
sum+=temp*n*flag;
flag+=1.0;
n--;
}
printf("%.2f",sum);
return 0;
} */ 




//1050 螺旋矩阵
//这题好难啊。。。 想想还是用C++吧，C++起码可以一边写一边初始化，不用把所有变量都先定义好 
#include<iostream>
#include <algorithm> 
#include<cmath>
using namespace std; 
/*int cmp(const void *i,const void *j){
return *(int *)j-*(int *)i;
}*/


bool compare(int a,int b){
  return a>b;// 从大到小。大于号从大到小，小于号从小到大 
}


int main(){
int N;
int i;
int yes=1;//用于判断是不是质数 
scanf("%d",&N);
if(N<4) yes=1;//小于4不用看就是质数 
    else
  {
for(i=2;i<=sqrt(N);i++)
 if(N%i==0) yes=0;}//被小于平方根的数整除就不是质数 
int a[N]; 
for(i=0;i<N;i++)
scanf("%d",&a[i]);
// qsort(a,N,sizeof(a[0]),cmp);
     sort (a,a+N,compare);
  //   for(i=0;i<N;i++)
// printf("%d ",a[i]);
if(yes) {
for(i=0;i<N;i++)
    printf("%d\n",a[i]);
}
 else{//不是质数 
   int hang,lie;
lie=sqrt(N);//向下取整---sqrt（17）=4 
if(lie*lie==N) hang=lie;//被整除行列相等 
else {
hang=lie+1; 
while(hang*lie!=N){
if(hang*lie>N) lie--;
else if(hang*lie<N) hang++; 
}
}
int s[hang][lie];
i=0;
int x=0,k=0,y=0,flag=0;
while(i<N){//这里就是核心===怎么螺旋排列。解释不清楚，我是先设置四个flag用来拐弯 
if(flag==0&&y<lie-k) {
 s[x][y]=a[i];
 y++;
if(y==lie-k-1)  {flag=1;i++;}//拐弯，这时要i++;避免下一次输入的时候仍然是输入这一次的a[i]值 

    }
if(flag==1&&x<hang-k){
s[x][y]=a[i];
x++;
if(x==hang-k-1) {flag=2;i++;}

}
if(flag==2&&y>=k){
s[x][y]=a[i];
y--;
if(y==k) { flag=3;k++;i++;}
  


}
if(flag==3&&x>=k){
s[x][y]=a[i];
x--;
if(x==k) {flag=0;}//最后一次不用 


}i++;
 
}
for(i=0;i<hang;i++)
  for(k=0;k<lie;k++)
   if(k<lie-1) printf("%d ",s[i][k]);
   else printf("%d\n",s[i][k]);
}
return 0;
} 
