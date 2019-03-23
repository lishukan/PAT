#include<cstdio>
int main(){
   double w,t,l;
   double max=1,temp=0.0;
   char s[1000];
   int num=0,i=0;
   while(scanf("%lf%lf%lf",&w,&t,&l)!=EOF)


 //  int i=3;   //题目只说输入三次，不过无所谓了
  // while(i--)
   {   
 // (scanf("%lf%lf%lf",&w,&t,&l)!=EOF);
  temp=w;
  s[num]='W';
  if(t>temp) {temp=t;s[num]='T';}
  if(l>temp) {temp=l;s[num]='L';}
      max*=temp;
 num++;
          
    }
    max*=0.65;
  max-=1;
  max*=2;
  printf("%c",s[0]);
  for(i=1;i<num;i++)
 printf(" %c",s[i]);
  printf(" %.2lf",max);//vc6上这样错误，得max+0.005答案才相同
  return 0;
}
