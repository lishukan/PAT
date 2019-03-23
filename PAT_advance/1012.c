#include<iostream>  //给自己增加了点难度 
#include<map>   
#include<cstdio>
#include<string>  //主要思路是，利用map映射存在的学生id，开4个数组存放每个分数在相应科目能得到的排名 
#include<vector>      //     输入id，先看map中是否有。有的话，找出这个map键对应的序号（注意，是序号i，被记录成绩的学生的序号，不是id，是先后顺序） 
#include<algorithm>   //     然后利用序号把这个学生找出来，分别看他的每科成绩的最高排名  
using namespace std;//    map映射序号 ，序号找到成绩，通过成绩挑选排名 
struct student{     //这样就避免开非常非常大的数组来存放每一个id的行为 ，题目说6位，真要开1000000也可以，见仁见智 
  int score[4];  //数组形式存放便于之后计算和排序 
}stu[2010];
bool cmp(int a,int b){
return a>b;
}
int main(){
int   ff[2010]; // 这四个数组用来存放所有学生成绩，并且排序 
int  uu[2010];
int cc[2010];
int kk[2010];
int flag=0;
map<string,int>mp;//srting 映射到int --stu【i】 ,对应顺序第多少输入的学生 
   int n,m,i,j,k,num;
   string temp;  //这里所有string 必须cin，不能scanf ，因为有map键是string，所以定义要按照c++string来 
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++) {
     cin>>temp;   //其实题目的学生id确实只是6位int整数，这里强迫症，给自己加难度，也是想好好学学stl--map 
scanf("%d%d%d",&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);  //输入每个学生的成绩 
stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3;  //平均成绩 
ff[i]=stu[i].score[0];
uu[i]=stu[i].score[1];
cc[i]=stu[i].score[2];
kk[i]=stu[i].score[3];
mp[temp]=i; // 添加映射 
   }
  sort(ff,ff+n,cmp); //排序 
   sort(uu,uu+n,cmp);   //是对存在的分数进行排序，和学生无关 
   sort(cc,cc+n,cmp);    //建立好分数的排序后，只需要看学生的分数就能找到对应这科排名 
   sort(kk,kk+n,cmp);   //假设A-10分，B-20分,C-30.得到分数排序是 30，20，10 开数组记录rank【30】=1 查询时，只要知道学生A成绩是30，直接看rank【30】是多少就为A排名 
   int rank[4][102];// 开个二维数组，分别存放每科的分数榜 
rank[0][ff[0]]=1;    //这里都是各种分数能取得的最好排名，只对应【0-100】的分数
 rank[1][uu[0]]=1;    // 每个最高分都是第一名 
  rank[2][cc[0]]=1;
   rank[3][kk[0]]=1;    
   for(i=1;i<n;i++)   ///           有并列情况时，注意    98 95 95 94 92是 1 2 2 4 5  而不是 1 2 2 3 4 
      if(ff[i]==ff[i-1])  continue;     //和上一 个分数一样不用考虑，因为这个分数已经有排名了 
      else rank[0][ff[i]]=i+1;     //和上一个分数不一样，产生新排名 
    for(i=1;i<n;i++)
      if(uu[i]==uu[i-1])  continue;
      else rank[1][uu[i]]=i+1;
    for(i=1;i<n;i++)
      if(cc[i]==cc[i-1])  continue;
      else rank[2][cc[i]]=i+1;
    for(i=1;i<n;i++)
      if(kk[i]==kk[i-1])  continue;
      else rank[3][kk[i]]=i+1; 
   int best=0;
   char ans[4]={'A','C','M','E'};         
   for(i=0;i<m;i++)  {                                 
      cin>>temp;               
     if( mp.find(temp)!=mp.end()) //这个map键是否存在---这个学生id是否存在 ，不等于就存在 
      {   best=9999;                
  j=mp[temp]; //获得这个学生的序号，输入时的序号不是学号 
  for(k=0;k<4;k++) {
           num=stu[j].score[k];   //  获得这个学生的各科分数 ，看各科目分数的最高排名 
if( rank [k] [ num ] <best ) {
best= rank [k] [ num ];
 flag=k;  //记录此时flag  
 }
}
printf("%d %c\n",best,ans[flag]);
}
else printf("N/A\n");
   }
return 0;
} 
