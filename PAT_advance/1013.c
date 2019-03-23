#include<cstdio>
#include<algorithm>
#include<iostream> 
using namespace std;
bool flag[1010]={false};
int g[1010][1010]={0};
int n;
void dfs(int node){    // 深度遍历 
flag[node]=true;
         for(int i=1;i<=n;i++) 
{
if(flag[i]==false&&g[node][i]==1) dfs(i); //这个节点没有被访问过且有路径通向外部 
  }                                       

}
int main(){
int m,k,i,j,q,p;
scanf("%d%d%d",&n,&m,&k);
for(i=0;i<m;i++)
{
scanf("%d%d",&q,&p);
 g[q][p]=1;
 g[p][q]=1;
  }
  int temp,num=0;
  for(i=0;i<k;i++)
  {
  fill(flag,flag+1010,false); //每次开始都要将状态设置为未访问 
  num=0;  // 计数器清零 
    scanf("%d",&temp);
    flag[temp]=true;
    for(j=1;j<=n;j++)  //城市从1开始编号，所以这里是1 
      if(flag[j]==false) {   // 假设遍历了两次才遍历完，那么肯定有两个不连通的   块，不然一次就遍历完了 
 dfs(j);                //   修路只需修遍历次数减一   ，   3个点两条路，4个点三条路，250没活路 
 num++;
 }
 printf("%d\n",num-1);
 
}
 
return 0;
} 
