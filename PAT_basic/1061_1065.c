// 1061 判断题
/*
#include<cstdio>


int main(){
int n,m,i;
int stu[100]={0};
int ans[100];
int score[100];
int temp,j;
scanf("%d%d",&n,&m);
for(i=0;i<m;i++)
scanf("%d",&score[i]);
    for(i=0;i<m;i++)
scanf("%d",&ans[i]);
for(i=0;i<n;i++)
{ for(j=0;j<m;j++)
{ scanf("%d",&temp);
   if(temp==ans[j]) stu[i]+=score[j];
}
printf("%d\n",stu[i]);
}
return 0;
}


*/




// 1062 最简分数
/*
#include<cstdio>
int istrue(int& i, int &k){//判断是否为最简分数，我
  int j=1;
  if(i==1) return 1;
  else {
    for(j=2;j<=i;j++)
      if(i%j==0&&k%j==0) return 0;//如果分子分母都能除断一个数，必不是最简
  
  }
  return 1;// 最简
  }
  


int main(){
  int n1,n2,m1,m2,k,i,j;
  double s1,s2,temp;
  scanf("%d/%d%d/%d%d",&n1,&m1,&n2,&m2,&k);
  s1=(double)n1/(double)m1;
  s2=(double)n2/(double)m2;
  if(s1>s2) {temp=s1;s1=s2;s2=temp;}
  temp=0.0;
  j=0;
  i=1;
  while(temp<s2)
  {
    temp=(double)i/(double)k;
    if(temp>s1&&temp<s2) //一开始我以为外圈设置了temp<s2就够了，没想到啊没想到，这题目算的分毫不差
    {
       if(istrue(i,k)==1)
       {
         if(j>0) printf(" ");
         printf("%d/%d",i,k);
         j++;
       }          
    }
    i++;
  }
  return 0;
}*/


// 1063 
/*
#include<cstdio>
#include<cmath>
int main(){
  int n,i;
  double  temp1,temp2,max=0.0,pp;
  scanf("%d",&n);
    for(i=0;i<n;i++)
  {  scanf("%lf %lf",&temp1,&temp2);
     pp=sqrt(temp1*temp1+temp2*temp2);
  
     if(pp>max) max=pp;
  }
  printf("%.2f",max);
  return 0;
}*/


// 1064 朋友数
/*
#include<cstdio>
int main(){
 
int n,i,j,temp,num=0,f[1001]={0},ans[1000];

char c;
scanf("%d",&n);
getchar();//scanf后接getchar要先用个getchar清空缓冲区
for(i=0;i<n;i++)
{ temp=0;
while((c=getchar())>='0'&&c<='9')
{
temp+=(c-'0');
}
     f[temp]++; 
// printf("**%d**",temp);
  
}
for(i=0;i<=1000;i++) 
 if(f[i]>0) ans[num++]=i;
printf("%d\n",num);
printf("%d",ans[0]);
for(i=1;i<num;i++)
printf(" %d",ans[i]);
return 0;
}*/




//1065


#include<cstdio>
#include<malloc.h>
#include<algorithm>
using namespace std;
int main(){
struct node {
  int sp;// 配偶信息
  int flag;  //双方总共出现次数
};
struct node *p=(struct node *)malloc(1000000*sizeof(struct node));
int n,i,num=0,a1,a2,temp;
// int *p=(int *)malloc(1000000*sizeof(int));
int *ans=(int *)malloc(1000000*sizeof(int));//存最后输出
     
int k;
scanf("%d",&n);
for(i=0;i<n;i++)
{ scanf("%d%d",&a1,&a2);
   p[a1].sp=a2;  //确定关系 
p[a2].sp=a1;
p[a1].flag=0;  //有配偶就让双方flag置零
p[a2].flag=0;


}  
scanf("%d",&k);
for(i=0;i<k;i++)
{ scanf("%d",&ans[i]);
  if(p[ans[i]].sp>=0)//如果这个人有配偶
  { p[ans[i]].flag+=1;  //老王的状态加一
temp=p[ans[i]].sp;
p[temp].flag+=1;  // 老王的伴侣的flag加一，两人都在的状态是 ，两人的flag都为2
  }
 
}
    
    for(i=0;i<k;i++)
      if (p[ans[i]].flag!=2) num++; 
 else ans[i]=0;//不是单身狗都置零
 sort(ans,ans+k);
printf("%d\n",num);
if(num!=0)
{
for(i=k-num;i<k-1;i++)//前面几个都是0，要从k-num开始
printf("%05d ",ans[i]);
printf("%05d",ans[k-1]); //一开始这里是i，想想万一num=1这里就会出错，（测试点1），
}                          //   只要写成k-1绝对没错，因为k-1是最后一个的下标。
return 0;


}
