#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
char n1[20],n2[20],n3[20];
int tag,radix;
long long num1=0,num2=0;
scanf("%s%s%d%d",&n1,&n2,&tag,&radix);
  long long i=0,temp=0;
 if(tag==2) {strcpy(n3,n2);strcpy(n2,n1);strcpy(n1,n3);}  //始终让n1为已知进制
  for(i=0;n1[i]!='\0';i++)
  {
 if(n1[i]>='0'&&n1[i]<='9') temp=n1[i]-'0';
     else temp=n1[i]-'a'+10;
        num1=num1*radix+temp;    //计算出N1数组的值 
  }
 // printf("\n%d",num1);
// printf("\n%s",n1);
 // printf("\n%s",n2);
int max=0;
   for(i=0;n2[i]!='\0';i++)  //找出N2中最大的位max，说明n2起码是max+1进制 
  {   if(n2[i]>='0'&&n2[i]<='9')    // 
       temp=n2[i]-'0';
else temp=n2[i]-'a'+10;
if(temp>max) max=temp;
  }
  
  long long left=max+1; 
  long long right=num1+1;//最大进制肯定不超过num1+1，why？因为只要有一位数a（不为零），a*（num1+1）就肯定大于num1，就不用比较了 
  long long mid=0;       //  一开始我把右边界设置为2的63次方-1，因为这是最大longlong数，但是这样，会有测试点通不过（结果偏大），例如，n1=1，n2=1，应该输出2 
  while(left<=right)//二分查找 
  {
  mid=(left+right)/2;
 
num2=0;
 for(i=0;n2[i]!='\0';i++)
 { if(n2[i]>='0'&&n2[i]<='9')  
       temp=n2[i]-'0';
else temp=n2[i]-'a'+10;
    num2=num2*mid+temp;
if(num2>num1) break;
//   printf("**%d**",num2);
 }
 if(num2==num1) 
 //  printf("\n%d\n",num2); 
{
   printf("%lld",mid);return 0;}
      if(num2>num1||num2<0) right=mid-1;
      else left=mid+1;
  } 
  
  printf("Impossible");
return 0;
}
