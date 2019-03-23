#include<cstdio>
int main(){
  int k,i,j,pre=0;
  long max;
  scanf("%d",&k);
  max=k*5;
  for(i=0;i<k;i++)
  {
    scanf("%d",&j);   
    if(j>pre) max=max+(j-pre)*6;
    else max=max+(pre-j)*4;
    pre=j;
  }
  printf("%ld",max);
return 0;
}
