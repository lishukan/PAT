#include<cstdio>      //   n 如果是素数，且N转化为D进制后的颠倒数在10进制中也是负数 就yes 
#include<iostream>   //  23（10）=10111（2）-颠倒--》11101（2）=29   而23 和29都是素数    
using namespace std;
int n,m,d;
int isprime(int n){
int i;
if(n==1) return 0; //规定1不是素数  ，第二个测试点 
for(i=2;i*i<=n;i++)
 if(n%i==0) return 0;
return 1;
}
int main(){


   while(1)
   {
scanf("%d",&n);
    if(n<0) return 0; 
    else {
scanf("%d",&d);
if(isprime(n)==0)  {
  printf("No\n");continue;
  }
  int temp=0;
  for( ;n!=0;n/=d)  //进制转换，自己打草稿 
   {
       temp=n%d+temp*d;
} 

if(isprime(temp)==1) 
printf("Yes\n");
else printf("No\n");
    }
    } 


} 
