// 1036 和奥巴马一起编 Programming with Obama
/*
#include<stdio.h>
int main(){
float n;//四舍五入，要用到小数点，所以还是float吧
char c;
int hang;
int i,j;
scanf("%f %c",&n,&c);
// printf("%d %c",n,c);
hang=(int)(n/2+0.5);
// printf("%d ",hang);
for(i=0;i<n;i++)
printf("%c",c);printf("\n");
   for(i=0;i<hang-2;i++)
   {
  printf("%c",c);
  for(j=0;j<n-2;j++)
  printf(" ");
  printf("%c",c);
  printf("\n");


   }
    for(i=0;i<n;i++)
printf("%c",c);printf("\n");
}*/


//1037 在霍格沃茨找零钱 Give change in Hogwarts
/*
#include<stdio.h>
int main(){
int s1[4],s2[4];
int aa=17*29;
 long int a;
 int b,c;
int flag=0;//是否为负数的标记位，一定要记得先赋值为0
_int64 price=0,pay=0,change=0;
//long long int price,pay,change;
scanf("%ld.%d.%d %ld.%d.%d",&s1[0],&s1[1],&s1[2],&s2[0],&s2[1],&s2[2]);
price=aa*s1[0]+s1[1]*29+s1[2];
pay=aa*s2[0]+s2[1]*29+s2[2];
    change=pay-price;
if(change<0) {flag=1;change*=-1;}
a=change/aa;
b=(change-(aa*a))/29;
c=change%29;
   if(flag) printf("-");
   printf("%ld.%d.%d",a,b,c);
   return 0;
}*/


//1038 统计同成绩学生  Statistics the  number of students with same score
/*
#include<stdio.h>//直接将每一次输入的相应分数的数量加一            
int main(){
int n,k,i,j;
int score[100001];
int num[102]={0};//分数是0-100，有101个，所以起码下标要102
int std[102];//发现一个很怪的事，我这里std放在num后定义就没错，放在之前就会错？why？
scanf("%d",&n);
for(i=0;i<n;i++)
{ scanf("%d",&score[i]);
   num[score[i]]++;
}
scanf("%d",&k);
for(i=0;i<k;i++)//为什么这里用temp就可以，用&std【i】却最后一个测试用例无法通过
{ scanf("%d",&std[i]);
       //可以利用缓冲区，先记录结果，最后一下子输出
        if(i!=k-1)   printf("%d ",num[std[i]]);
        else printf("%d",num[std[i]]);
}
return 0;
}
*/


//1039 到底买不买 buy or not ？
/*
#include<stdio.h>
int main(){
      int i;
 int num1[200]={0};
 int num2[200]={0};
 char temp;
 int flag1=0,flag2=0,flag3=0;
 int need=0;
 while((temp=getchar())!='\n')
 {
               num1[temp]++;
  flag1++;
 }
// printf("")
 while((temp=getchar())!='\n')
 {
          num2[temp]++;
 flag2++;
 }
 for(i=0;i<200;i++)
 {
 if(num2[i]>0&&num1[i]<num2[i])  need+=(num2[i]-num1[i]);
 }   
      if(need)
         printf("No %d",need);
 else printf("Yes %d",flag1-flag2);
 return 0;


 
}
*/


// 有几个PAT 
/*逻辑清楚就很简单，不然就很棘手。。。
#include<stdio.h>//        就是用每个A之前的P数目乘以这个A之后的T数目。然后累加每个A的结果。
int main(){            // 别的就有点难
char s[100001];
char c;
int i=0,len;
int p=0,a=0,t=0;
// _int64 result=0;
long long int result=0;
while((c=getchar())!='\n')
{
s[i]=c;
i++;
// if(c=='P') p++;
// else if(c=='A') a++;
if(c=='T') t++;

}
    len=i;
for(i=0;i<len;i++)
{
if(s[i]=='P') p++;
else if(s[i]=='T') t--;
else if(s[i]=='A') result+=p*t;
}
printf("%lld",result%1000000007);
}*/
