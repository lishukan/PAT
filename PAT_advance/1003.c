#include<cstdio>
#include<algorithm>//典型Dijkstra算法
using namespace std;
const int inf = 9999999;
const int maxv = 510;
int main(){
int n,m,c1,c2;
int i,j,u,v,min;
int g[maxv][maxv];
int we[maxv];
int d[maxv];
int w[maxv]={0};
int  num[maxv]={0};
bool flag[maxv]={false};
fill(g[0],g[0]+maxv*maxv,inf);//定义完全部初始化，有长度的都初始为inf，此处是uv间路径长度
fill(d,d+maxv,inf);// 起点到每个点的最短路径长度
fill(num,num+maxv,0);//是量不是长度的，都初始为0
fill(w,w+maxv,0);//起点到每个点的最大权重和
scanf("%d%d%d%d",&n,&m,&c1,&c2);
for(i=0;i<n;i++)
scanf("%d",&we[i]);//每个点的权重
for(i=0;i<m;i++)
{
scanf("%d%d",&u,&v);
scanf("%d",&g[u][v]);
g[v][u]=g[u][v];
}

    num[c1]=1;     // 出发时，初始化
w[c1]=we[c1];
d[c1]=0;
for(i=0;i<n;i++)
{ u=-1;
   min=inf;
        for(j=0;j<n;j++)
{
if(flag[j]==false&&d[j]<min) //  此点未访问且路径小于min
{
u=j;
min=d[j];
}
}
if(u==-1) continue;
flag[u]=true;// 将此点标记


for(v=0;v<n;v++)
{
if(flag[v]==false&&g[u][v]!=inf)// v未被访问，且能从U到达V
{
if(d[u]+g[u][v]<d[v]) //如果以U为中介到V的距离，比其他方法短
{ d[v]=d[u]+g[u][v];    //更新
 w[v]=w[u]+we[v];
                                 num[v]=num[u];   //
}
else if(d[u]+g[u][v]==d[v]) //以U为中介和其他方法一样近，即多条最短路径
{
if(w[u]+we[v]>w[v])// 而此条路径上权重和更大
{
                                        w[v]=w[u]+we[v];  //更新
}
                                         num[v]+=num[u];
}
}

}
}
printf("%d %d",num[c2],w[c2]);
return 0;

}
