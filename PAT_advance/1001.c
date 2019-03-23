/*
#include<cstdio>
#include<cmath>
int main(){
 long a,b,c;
 int x[10],i=0,j=0;
 scanf("%ld%ld",&a,&b);
 c=a+b;
 if(c<1000&&c>-1000)
printf("%ld",c);
 else 
 {
if(c<0) {printf("-");c*=-1;}
while(c>0)
{
 x[i]=c%1000;//每三位截取一次
 i++;
 c/=1000;
}
 
  i--;
 printf("%d,",x[i]);
 i--;
 while(i>0)
 {
printf("%03d,",x[i]);//除了第一个打印的数，之后的数都要03d
i--;
 }
printf("%03d",x[0]);
}
 return 0;
}*/
