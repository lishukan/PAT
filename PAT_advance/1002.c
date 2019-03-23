#include<cstdio>//  注意，只计算系数和不为零的项
#include<cmath>
int main(){
   int k1,k2,i,temp,num=0,last=1001;
   double x[10001]={0.0},m;
   scanf("%d",&k1);
   for(i=0;i<k1;i++)
   {   scanf("%d%lf",&temp,&m);
         x[temp]+=m;
   }
    scanf("%d",&k2);
   for(i=0;i<k2;i++)
   {   scanf("%d%lf",&temp,&m);
      x[temp]+=m;


   }
   for(i=1001;i>=0;i--)
   {
  if(x[i]!=0.0) 
  num++;        
   }
 printf("%d",num);//  首先输出num
 if(num>0) printf(" "); //num不为零
 else return 0;//最后一个测试点，num为0，即当没有任何一项系数和不为零时，直接结束
    for(i=1001;i>=0&&num>0;i--)
{
if(x[i]!=0.0) 
{   
printf("%d %.1lf",i,x[i]);
if(num>1) printf(" ");
num--;
}
}


  return 0;
 


}
