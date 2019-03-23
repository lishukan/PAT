#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 110;
vector<int> v[N];
int maxh=1;
int leaf[N]={0};//记录每一层叶子节点数目
void dfs(int index ,int h){    //深度遍历
   if(h>maxh) maxh=h;           //更新深度
   if(v[index].size()==0) //发现叶子节点
   {leaf[h]++;return;}
   for(int i=0;i<v[index].size();i++)
   {
  dfs(v[index][i],h+1);//遍历每个子节点
   }
}
int main(){
   int n ,m,i,j,k;
   scanf("%d%d",&n,&m);
   int father,numofchild,child;
   for(i=0;i<m;i++)
   {   scanf("%d%d",&father,&numofchild);
         for(j=0;j<numofchild;j++)
{scanf("%d",&child);
  v[father].push_back(child);
}
   }


dfs(1,1);//从第一层第一个节点开始
printf("%d",leaf[1]);
for(i=2;i<=maxh;i++)
printf(" %d",leaf[i]);
return 0;
}
