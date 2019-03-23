#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
int k;
    scanf("%d",&k);

int i,j,temp=0,left=0,right=0,sum=-1,flag=1,index=0;
vector<int > num;
for(i=0;i<k;i++)
{ scanf("%d",&j);
  num.push_back(j);
  temp+=j;
  if(j>=0) flag=0;//有大于零的数就标记
  if(temp>sum) {  //更新最大子列和
      sum=temp;  
  left=index;
  right=i;
  }
  else if(temp<0){  //小于零就不用再计算这一串子列和了，计算下一个（从正数）开始的子列
 index=i+1;   //这一时刻temp《0，始终将下一个数当作下一个子列的开始，index为下一个数的下标
  temp=0;    //置零计算下一个子列和
  }


}
if(flag) printf("0 %d %d",num[0],num[k-1]); //所有数都为负数
else {
printf("%d %d %d",sum,num[left],num[right]);}

return 0; 
}
