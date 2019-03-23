// 1066 图像过滤
/*
#include<cstdio>


int main(){
int n,m,l,h,k,i,j,temp;
int a[500][500];
scanf("%d%d%d%d%d",&n,&m,&l,&h,&k);
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{ scanf("%d",&temp);
   if(temp>=l&&temp<=h) temp=k;
if(j>0) printf(" ");
printf("%03d",temp);
if(j==m-1) printf("\n");

}
return 0;
}*/


// 1067 试密码
/*
#include<cstdio>
#include<cstring>
int main(){
    int n,i,num=0;
char ans[21];
char temp[100];
scanf("%s",&ans);
scanf("%d",&n);
getchar();//后面要用gets就要先清楚上次输入的回车字符
while(1)
{ gets(temp);//考虑到可能会输入带空格的字符串密码，测试点2，5
     num++;
  if(strcmp(temp,"#")==0) return 0;
   if(num<=n)
  {
 
if(strcmp(temp,ans)==0) //相等
{  printf("Welcome in\n");return 0;}
 else printf("Wrong password: %s\n",&temp);
  
  if(num==n) printf("Account locked\n");//注意注意，假设n=3，这里是输入完第三次后直接打印这一句，不是在第四次输入完打印
}
}




return 0;
}*/




// 1068 万绿丛中一点红
//too diffcult ! 几乎是抄袭别人来的，用map结构会很简单，可是我不会
/*
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int m ,n,i,j,k;
long tol;
long a[1000][1000];//VC里不能【1000】【1000】，这里要足够大，倒数第二个测试点
long num=0,flagx,flagy;
long maybe[4096][4096]={0};
// long maybe[100];
long number,temp,last=0,flag=0;
struct node{
long x;
long y;
long no;
}ss[1000];


int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
    int real(int i,int j)//检查用于和a【i】【j】相减的数是否存在，比如a[-1][-1] or a[m+1][n+1]
{
if(i<0||j<0||i>=n||j>=m) return 0;
return 1;
}
    int main()
{
scanf("%d%d%ld",&m,&n,&tol);
for(i=0;i<n;i++)
for(j=0;j<m;j++)
scanf("%ld",&a[i][j]);
for(i=0;i<n;i++)
for(j=0;j<m;j++)
                {    maybe[a[i][j]/4096][a[i][j]%4096]++;//  用于记录这个数出现的次数，由于数太大，所以前后拆开当下标
if(maybe[a[i][j]/4096][a[i][j]%4096]>1) continue;//已经出现的数不用考虑了，题目说这个像素必须是唯一的
 for(k=0;k<8;k++)
{ if(real(i+dx[k],j+dy[k]) ==1  && fabs(a[i][j]-a[i+dx[k]][j+dy[k]])<=tol   )   break;//存在且小于tol就肯定不符合
else if(k<7) continue;
else if(k==7)  //（包括检测不存在的）和周边所有存在的数比较，所有差都大于tol
{               //放入ss中
ss[num].x=j+1;
ss[num].y=i+1;
ss[num].no=a[i][j];
// maybe[a[i][j]/4096][a[i][j]%4096]++;//  用于记录这个数出现的次数，由于数太大，所以前后拆开当下标
//   测试点3 ---一个数大于周边所有的数，但是还有一个和这个相同的数却不满足条件。即一个数无论如何只要出现两次就不考虑
// printf("(%ld,%ld): %ld\n",ss[num].x,ss[num].y,ss[num].no);
num++;
}
}
        }
for(i=0;i<num;i++)
{
temp=ss[i].no;
if(maybe[temp/4096][temp%4096]>1) continue;//这个数出现过两次或以上
else 
{
last=i;
flag++;
if(flag==2) {printf("Not Unique\n"); return 0;}
}
}
   if(flag==1)  printf("(%ld, %ld): %ld\n",ss[last].x,ss[last].y,ss[last].no);//这里打印的括号里还有个空格
   else {printf("Not Exist\n");return 0;}
return 0;
}*/


// 1069 微博转发抽奖
/*
#include<cstdio>
#include<cstring>
#include<cstdlib>
int main(){
int m,n,s,i,j=0,k,flag=0;
char name[1000][20];
char temp[20];
scanf("%d%d%d",&m,&n,&s);


for(i=0;i<m;i++)
{ scanf("%s",temp);
    if(i+1-s<0) continue;//在第一个中奖人前就不用考虑
  if(flag)// 上一个输入是中奖但是重复了
  {
  for(k=0;k<j;k++)
  {  if(strcmp(temp,name[k])==0)//相等
  {  flag=k+1; break ;}
     if(k==j-1)   //当遍历到最后依然没有退出才能说明这个数是中奖了
  {  printf("%s\n",temp);strcpy(name[j++],temp);flag=0;
  s=i+1;//这时，要重新赋值给s，下一次中奖是以这次中奖的下标为起点的。（由于下面的判断是用i+1-s ，所以这里的s是s+1）
  break;}


           }




  }
  else 
  {   if(i+1==s||(i+1-s)%n==0) 
  {    
  if(j==0)  {printf("%s\n",temp);strcpy(name[j++],temp);continue;}
  for(k=0;k<j;k++)
  {  if(strcmp(temp,name[k])==0)//相等
  {  flag=k+1; break;}
     if(k==j-1)   
  {  printf("%s\n",temp);strcpy(name[j++],temp);flag=0;break;}


  }
  }
  }
}
  
if(m<s) 
      printf("Keep going...\n");
return 0;
}*/


// 1070 结绳 
// 最长的都留在最后结就行，所以要从小到大先排序再结
// 因为越早结的那段绳子最后长度越小，所以大头留在后面
/*
#include<cstdio>
#include<iostream>
#include<algorithm>


using namespace std;
int main(){
int n,i;
scanf("%d",&n);
double temp,a[10001];
int max;// 一开始我把max定义成double，最后输出%.lf 最后一个测试点过不去
for(i=0;i<n;i++)
scanf("%lf",&a[i]);
  sort(a,a+n);
  max=a[0];
  for(i=1;i<n;i++)
 max=(a[i]+max)/2;
  printf("%d",max);//  换成int再试就可以，那这题目的意思绳子长度每次结绳都先向下取整，而不是最后double的结果取整
  return 0;
}*/
