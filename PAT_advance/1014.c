#include<cstdio>
#include<algorithm>
#include<iostream> 
#include<queue>
using namespace std;
int n,m,k,q,i,j;
int hour,minute;
long ans[1010];//结束时间 
long need[2010];// 服务需要时间 
struct windows{
  int endtime;//窗口队伍的最后服务时间 
  int poptime; // 队首客户的服务结束时间 
  queue<int > serve; // 窗口前的黄线内排队队列 
}win[21];

int main(){
  scanf("%d%d%d%d",&n,&m,&k,&q);
    for(i=0;i<k;i++)
     scanf("%d",&need[i]); // 读入每个人服务需要时间 
  for(i=0;i<n;i++)
    {
        win[i].endtime=0;
      win[i].poptime=0; 
    }
    for(i=0;i<min(n*m,k);i++)  //  取n*m和K最小的一个，如果K最小，说明所有客户都可在黄线内 
    {
       win[i%n].serve.push(i);  // 将客户入队，这里i是客户序号 
       win[i%n].endtime+=need[i]; // 更新窗口服务结束时间 
       if(i<n) win[i].poptime=need[i]; // 第一批被服务的人结束服务的时间 
       ans[i]=win[i%n].endtime;  //当前入队的客户服务结束时间直接就是窗口最新的服务结束时间  
    }
  for(;i<k;i++) //黄线外的客户，轮到他们选窗口了 
  {
     int number=-1;
     int mintime=9999999;
     for(j=0;j<n;j++)  // 先找到所有窗口中，最早有客户服务完退出的那个 （poptime最小的那个） 
    
          if(win[j].poptime<mintime)
       {
           number=j;   //记录下这个窗口 
           mintime=win[j].poptime;
      } 
    win[number].serve.pop();//将这个客户出队 
    win[number].serve.push(i) ;// 新来客户入队 
    win[number].endtime+=need[i];  //更新窗口的结束时间 
    win[number].poptime+=need[win[number].serve.front()];  //更新窗口的poptime 
    ans[i]=win[number].endtime;// 这个客户的服务结束时间就是这个窗口当前的结束时间 
       
   } 

    
    
    
   int temp;
   for(i=0;i<q;i++)
   {
   
    scanf("%d",&temp);
     hour=ans[temp-1]/60+8; //这里输入的temp是客户序号（从1开始），对应下标从0开始，所以要减一 
     minute=ans[temp-1]%60;
  //    hour=ans[i]/60+8;
   //  minute=ans[i]%60;
  //     printf("%02d:%02d\n",hour,minute);
  //   if(hour>=17&&minute>0) printf("Sorry\n");
     if(ans[temp-1]-need[temp-1]>=((17-8)*60)) printf("Sorry\n");//服务开始的时间要早于下班时间
     else  printf("%02d:%02d\n",hour,minute);
   }
  return 0;
} 
