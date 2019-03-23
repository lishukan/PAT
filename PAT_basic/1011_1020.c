/*1011
#include<stdio.h>
int main(){
  long int a[10][3]; //2的31次方要用长整形
  int i,j,k;
  scanf("%d",&j);
  for(i=0;i<j;i++)
    scanf("%ld %ld %ld",&a[i][0],&a[i][1],&a[i][2]);//输入长整形要用%ld
    for(i=0;i<j;i++)
  {  if((a[i][0]+a[i][1])>a[i][2]) printf("Case #%d: true\n",i+1);
    else printf("Case #%d: false\n",i+1);
  }
  return 0;
}*/




/*1012
#include<stdio.h>
#include<math.h>
int main(){
   int n,i;
   int a[10001];
   float r=0.0;
int q=0,w=0,e=0,t=0,p=0;
   int k=0,flag=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {     scanf("%d",&a[i]);
          if(a[i]%5==0&&a[i]%2==0) q+=a[i];
      else  if(a[i]%5==1) {p=pow(-1,k);w+=(p*a[i]);k++;}
      else  if(a[i]%5==2) e++;
          else  if(a[i]%5==3){ r+=a[i];flag++;}
          else  if(a[i]%5==4&&a[i]>t) t=a[i];
   }
    //这里要注意的就是，应该立个flag判断是否有条件数，否则万一A1A2A3A4A5存在等于0就很尴尬了 
   if(q==0) printf("N ");else printf("%d ",q);
   if(k==0) printf("N ");else printf("%d ",w);//用k判断是否有条件数，否则万一w=0呢
   if(e==0) printf("N ");else printf("%d ",e);
   if(flag==0) printf("N ");else printf("%.1f ",r/flag);//0不能做被除数
   if(t==0) printf("N");else printf("%d",t);
   return 0;
}*/




/*1013
#include<stdio.h>
#include<math.h>
int main(){
  int m,n;


  int b[10002];//根据题意，最多有一万个素数，一万个明显不够
  int i,j,k=0,l=0;
 scanf("%d %d",&m,&n);
  for(i=1;k<=n;i++)
  {  for(j=2;j<=(int)sqrt(i);j++)
   if(i%j==0) break;
 if(j>(int)sqrt(i)) b[k++]=i;}//是素数就存入b
  b[k]=0;


  if(m==n) printf("%d",b[m]);
  else for(i=0;i<=(n-m);i++) 
  {     if(i!=(n-m)&&(i%10)<9) printf("%d ",b[i+m]);
        else if(i%10==9) printf("%d\n",b[i+m]);//每个需要换行的数
else if(i==n-m) printf("%d",b[i+m]);}//最后一个
   return 0;
}*/


/*1014
#include<stdio.h>
int main(){
  char a[62],b[62],c[63],d[62];
  int i,j,k;
  char day[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};//二维数组定义中要用双引号，列长度需考虑\0，刚开始还定义的【7】【3】
  gets(a);
  gets(b);
  gets(c);
  gets(d);
  for(i=0;a[i]!='\0'&&b[i]!='\0';i++)
    if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G')      { k=a[i]-'A';printf("%s ",day[k]); break;} //BREAK后，此时i仍在‘D’

//上面字母G前忘了加‘=’号，搞得竟然找了一晚上的错，硬是没看到。另外，当第一对字母等于G时就是测试用例5。

//  此处只考虑A到G，因为一个星期只有七天，之后的字母不用考虑，测试点4

  for(j=i+1;a[j]!='\0'&&b[j]!='\0';j++) //j=i+1，实际上就是继续上面的循环，只是跳过第一个相同的字母
  {  if(a[j]==b[j]&&a[j]>='0'&&a[j]<='9')        {printf("0%d:",a[j]-'0');break;}
     else if (a[j]==b[j]&&a[j]>='A'&&a[j]<='N')  {printf("%d:",a[j]-'A'+10);break;}
  }
    
// else if (a[j]==b[j]&&a[j]>='a'&&a[j]<='n') {printf("%d:",a[j]-'a'+10);break;}题目说只有大写字母代表小时
  for(i=0;c[i]!='\0'&&d[i]!='\0';i++)
  {     if(c[i]!=d[i]) continue;
        else if(c[i]>='a'&&c[i]<='z')    {j=i;break;} 
              else if(c[i]>='A'&&c[i]<='Z')          {j=i;break;}
  }  
 
 printf("%02d",j);//%02d*宽度小于2补0，大于2不变。例：2-02，1234-1234


  return 0;
}


/*1015
  #include<stdio.h>
#include<stdlib.h>
struct student{
int name;
int de;
int cai;
int sum;
};
int cmp(struct student *a,struct student *b){//返回正数----1排2后，负数----2排一后
     
if(b->sum-a->sum!=0)            //指针的结构体要记得用->
return b->sum-a->sum;
    else if(b->de-a->de!=0) return b->de-a->de;
        else return a->name-b->name;


}
int main(){
int n,l,h;
int zz,xx,cc;
int i=0,j=0,k=0,flag=0;
int A=0,B=0,C=0,D=0;
struct student *a=malloc(100000*sizeof(struct student));//按题目来讲，用数组无法得到10^5的空间，非要数组只能用malloc
struct student *b=malloc(100000*sizeof(struct student));
struct student *c=malloc(100000*sizeof(struct student));
struct student *d=malloc(100000*sizeof(struct student));


     scanf("%d %d %d",&n,&l,&h);
 


    for(i=0;i<n;i++)
   {
     scanf("%d %d %d",&zz,&xx,&cc);
      if(xx<l||cc<l) continue;
     else 
     {    flag++;
       if(xx>=h&&cc>=h)          {a[A].name=zz;a[A].de=xx;a[A].cai=cc;a[A].sum=xx+cc;A++;continue;}//为防止条件判断意外，用了一下continue
       if(xx>=h&&cc<h)           {b[B].name=zz;b[B].de=xx;b[B].cai=cc;b[B].sum=xx+cc;B++;continue;}
       if((xx<h&&cc<h)&&(xx>=cc)) {c[C].name=zz;c[C].de=xx;c[C].cai=cc;c[C].sum=xx+cc;C++;continue;}   
       else                      {d[D].name=zz;d[D].de=xx;d[D].cai=cc;d[D].sum=xx+cc;D++;continue;}
     }
   }
printf("%d\n",flag);
     qsort(a,A,sizeof(a[0]),cmp);//1.数组名2.要排序的长度3.数组（字节）大小4.排序方式
 qsort(b,B,sizeof(b[0]),cmp);
  qsort(c,C,sizeof(c[0]),cmp);
   qsort(d,D,sizeof(d[0]),cmp);
for(i=0;i<A;i++)
printf("%d %d %d\n",a[i].name,a[i].de,a[i].cai,a[i].sum);
for(i=0;i<B;i++)
printf("%d %d %d\n",b[i].name,b[i].de,b[i].cai,b[i].sum);
for(i=0;i<C;i++)
printf("%d %d %d\n",c[i].name,c[i].de,c[i].cai,c[i].sum);
for(i=0;i<D;i++)
printf("%d %d %d\n",d[i].name,d[i].de,d[i].cai,d[i].sum);
return 0;
}      
*/










/*1016
#include<stdio.h>
int main(){
  int A,DA,B,DB;
  int i=0,j=0,h=0,k=0;
  scanf("%d %d %d %d",&A,&DA,&B,&DB);
  for(i=0;A!=0;A/=10)
    if(A%10==DA) {h=h*10+DA;i++;}
  for(j=0;B!=0;B/=10)
    if(B%10==DB) {k=k*10+DB;j++;}


    
    printf("%d",h+k);
    return 0;
}*/












/*          1017       
#include<stdio.h>
int main(){
char s[1001];//10^1000无法用int ，只能用字符，一个个算，
int b,r;
int i,j;
int q[1001];
scanf("%s %d",&s,&b);


for(i=0,j=0,r=0;s[i]!='\0';i++) 
{    r=r*10+(int)(s[i]-'0');
     q[j++]=r/b;
 r=r%b;
}
if(j==1) printf("%d",q[0]);   //考虑到，如果商只有一位，那就无论是不是0都要表示
else if(j>1)
{   if(q[0]!=0) printf("%d",q[0]);//但是商大于1位，如果第一位为0必须舍弃。例如：12  7-》01   5-》1 5
for(i=1;i<j;i++)
             printf("%d",q[i]); 
}
   printf(" %d",r);
return 0;
}
*/








/*1018 锤子剪刀布    Hammer scissors cloth
#include<stdio.h>
int main(){
     int n;
int ab=0,aj=0,ac=0,wina=0,ping=0;
int bb=0,bj=0,bc=0,winb=0;
char a[100000],b[100000];
int i,ansa=0,ansb=0;
scanf("%d\n",&n);
for(i=0;i<n;i++)
{  
scanf(" %c %c",&a[i],&b[i]);//前面加空格防止读入上一行的回车字符


    if(a[i]=='B') 
{
if(b[i]=='B'){ping++;}
else if(b[i]=='C'){wina++;ab++;}
else if(b[i]=='J'){winb++;bj++;}
}
else if(a[i]=='C')
{
 if(b[i]=='B'){winb++;bb++;}
else if(b[i]=='C'){ping++;}
else if(b[i]=='J'){wina++;ac++;}
}
else if(a[i]=='J')
{
    if(b[i]=='B'){wina++;aj++;}
else if(b[i]=='C'){winb++;bc++;}
else if(b[i]=='J'){ping++;}
}
}
//  for(i=0;i<n;i++) printf("%c+%c-\n",a[i],b[i]);
    printf("%d %d %d\n",wina,ping,winb);
    printf("%d %d %d\n",winb,ping,wina);
    if(ac>ab&&ac>=aj) printf("C ");//注意答案格式
else if(aj>ab&&aj>ac) printf("J ");
else printf("B " );
if(bc>bb&&bc>=bj) printf("C");
else if(bj>bb&&bj>bc) printf("J");
else printf("B" );



return 0;
}*/


/*1019  数字黑洞 number black hole
#include<stdio.h>
#include<stdlib.h>
int cmp1(int *i,int *j) {return *j-*i;}//返回正数1排2后
int cmp2(int *i,int *j) {return *i-*j;}//注意注意，虽然定义的是int数组，但是cmp里仍然要用指针，不用就排出错误。6767-》7676而不是7766
int main(){
    int a[4],b[4],ans1=0,ans2=0,gg=0;
int k,i,j;
  
scanf("%d",&k);
    while(1)
{
for(i=0;i<4;i++)
{ a[i]=k%10;
b[i]=a[i];
 k/=10;
}


qsort(a,4,sizeof(a[0]),cmp1);
qsort(b,4,sizeof(b[0]),cmp2);
for(i=0;i<4;i++)
{ printf("%d",a[i]);    ans1=ans1*10+a[i];    }
printf(" - ");
        for(i=0;i<4;i++)
{ printf("%d",b[i]); ans2=ans2*10+b[i];}
k=ans1-ans2;
printf(" = ");
if(k==0) printf("0000\n");//2222-2222=0000
else if(k<1000) printf("0%d\n",k);//测试点2,例：0001-》1000-0001应该显示0999而不是999，所以k最好用4位数组存放4位。
else  printf("%d\n",k);
ans1=0;ans2=0;//注意每次循环打印结束要置零ans
if(k==6174) break;
if(k==0) break;




}






return 0;
}*/






//1020   mooncake 建立月饼的结构体，按平均价格排序，一份一份累加到满足需求或者库存卖完（库存小于需求，测试点3）。
/*
#include<stdio.h>
#include<stdlib.h>
struct node
{
float s;//库存stock       注意注意，题目直说库存和价格是正数，没说是正数，不能用int（这是测试点2）
float p;//价格price
double ave;
};
int cmp(struct node *a,struct node *b)//cmp里参数必须为指针
{


   if(b->ave-a->ave>0.0) return 1;//结构体指针成员，要用->
   else if(b->ave-a->ave<0) return -1;
   else return 0;
}
int main(){
int n,d;
    int i,j=0,k=0,flag=0;
double result=0.0;
struct node *test=malloc(1001*sizeof(struct node));
    
scanf("%d %d",&n,&d);
   for(i=0;i<n;i++)
  scanf("%f",&test[i].s);//注意注意，没说一定是整数，不能%d
 // for(i=0;i<n;i++) printf("%d ",test[i].s);
   for(i=0;i<n;i++)
   {   scanf("%f",&test[i].p);//注意注意，没说一定是整数，不能%d
        test[i].ave=test[i].p/test[i].s;
   } 
   qsort(test,n,sizeof(struct node),cmp);
//  for(i=0;i<n;i++)  printf("%d %d %f",test[i].s,test[i].p,test[i].ave);
   for(i=0;i<n;i++)//每种月饼
   {   for(j=0;j<test[i].s;j++)//每万吨
  {     result+=test[i].ave;
       k++;//每卖出一万吨，自加1
// printf("%.2f %d\n",result,k);

if(k==d)  {flag=1;break;}//销量达到目标，退出
  }
     if(flag) break;
   }


   printf("%.2f",result);


return 0;
}*/
