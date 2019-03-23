#include<iostream>
#include<cstdio>
struct node{
   int x;
   double y;
};
int main(){
   struct node one[20];
   double ans[2001]={0.0};
   int flag[2001]={0};
   int k1,k2,i,j;
   scanf("%d",&k1);
   for(i=0;i<k1;i++)
      scanf("%d%lf",&one[i].x,&one[i].y);


   
   
   scanf("%d",&k2);
   int te;
   double mp;
 for(i=0;i<k2;i++)
 {
scanf("%d%lf",&te,&mp);  
for(j=0;j<k1;j++)
   
// if(flag[one[j].x+te]==0) flag[one[j].x+te]=1;
ans[one[j].x+te]+=(one[j].y*mp);
 }


 int num=0;
  for(i=2000;i>=0;i--)
 if(ans[i]!=0.0)  num+=1;   //有坑  NK---X的幂nk   aN1--- 前面的系数  ，题目只说NK大于0，但是系数可能为负
    //这里判断要判断非零，我一开始只判断是否大于零 
 printf("%d",num);
 if(num==0) return 0;
  for(i=2000;i>=0;i--)
 if(ans[i]!=0.0) //只需要输出非零项
 printf(" %d %.1lf",i,ans[i]);
 
    


return 0;
}
