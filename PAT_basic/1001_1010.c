/*#include<stdio.h>
int main(){
  int n,i;
  scanf("%d",&n);
  if(n==1) i=0;
  else {for(i=0;n!=1;i++)
  { if(n%2==0)  n/=2;
    else  n=(3*n+1)/2;
  }}
  printf("%d\n",i);
  return 0;
}*/


/*#include<stdio.h>              1002
int main(){
char str[100];
int sum=0;
int i;
int a[100];
scanf("%s",&str);
    for(i=0;str[i]!='\0';i++)
sum+=(str[i]-'0');
     i=0;
for( ;sum;sum/=10)
 a[i++]=sum%10;
while(i>=1)
{switch(a[--i])
{case 0:printf("ling");break;
        case 1:printf("yi");break;
case 2:printf("er");break;
case 3:printf("san");break;
case 4:printf("si");break;
case 5:printf("wu");break;
case 6:printf("liu");break;
case 7:printf("qi");break;
case 8:printf("ba");break;
case 9:printf("jiu");break;
}if(i>=1)printf(" ");
}




}
*/


/*   1003 woyaotongguo  
#include<stdio.h>  
#include<string.h>
int main(){
    int n,i,j;
int a,b,c;
int fp,ft,fa,flag;
char str[100][100];
scanf("%d\n",&n);


for(i=0;i<n;i++)
scanf("%s",&str[i]); 


     for(i=0;i<n;i++)
{
         flag=0;
ft=0;fp=0;fa=0;
a=0;b=0;c=0;
 
for(j=0;str[i][j]!='\0';j++)
{ if ( str[i][j]=='T')             ft++;
else if (str[i][j]=='P')         fp++;
 else if(str[i][j]=='A')       fa++;
      else {flag++;break;}
  if(ft>fp) {flag++;break;}
  if (  &str[i][j]<strstr(str[i],"P") )   a++; 
else if ( ( &str[i][j]<strstr(str[i],"T")) && (&str[i][j]>strstr(str[i],"P")) ) b++;
else  if( &str[i][j]>strstr(str[i],"T")   &&(str[i][j]!='\0'))  c++; 
}
             //  printf("%d%d%d\n",fp,fa ,ft) ;
if (flag!=0)  {printf("NO\n");continue; }
else if (fp!=1) {printf("NO\n");continue; }
else if (ft!=1) {printf("NO\n");continue; }
else if(fa==0) {printf("NO\n");continue; }
else if(b==0)  {printf("NO\n");continue;}
else if(a==c)  printf("YES\n");
else if (c==(a*b))    printf("YES\n");
else printf("NO\n"); 
}
return 0;
}
*/


/* 1004 #include<stdio.h>
int main(){
int n,max,min,m,k,i;
int  c[100];
char a[100][100];
char b[100][100];
scanf("%d\n",&n);
for(i=0;i<n;i++)
scanf("%s %s %d",&a[i],&b[i],&c[i]);
max=c[0];
min=c[0];
k=0,m=0;
for(i=0;i<n;i++)
{ if (c[i]>max ) {max=c[i];m=i;}
   if (c[i]<min)  {min=c[i];k=i;}
}
printf("%s %s\n",a[m],b[m]);
printf("%s %s\n",a[k],b[k]);




return 0;
}*/


/*1005   jixu 3n+1 ideal
#include<stdio.h>
int paixu(int a[],int k){//冒泡排序函数
int i,j,m;
for(i=0;i<k-1;++i)
for(j=0;j<k-i-1;++j)
{ if(a[j]<a[j+1])   {m=a[j];a[j]=a[j+1];a[j+1]=m;}


}
return 0;
}






int main(){
int k,i,j=0,m=0;
int a[100];//存放输入示例
int b[10000];//存放示例的卡拉兹数，这里要10000才能满足测试用例，太少可能会有段错误。
int c[100];//存放输出结果
scanf("%d",&k);
for( i=0;i<k;i++)  scanf("%d",&a[i]); 
for(i=0;i<k;i++) 
for(m=a[i];m!=2;j++)
{ if(m%2==0)  {b[j]=m/2;m/=2;}     
else {b[j]=(3*m+1)/2;m=b[j];}}
b[j]=0;
  for(i=0;i<k;i++) 
  for(j=0;b[j]!=0;j++)
        if(a[i]==b[j])  {a[i]=0;break;}//将输入示例中被覆盖的数置零
   paixu(a,k);//从大到小排序后
   for(i=0,j=0;i<k;i++)  if(a[i]!=0) {c[j]=a[i];j++;};  //将不为零的结果存到C
   for(i=0;i<j-1;i++) printf("%d ",c[i]);printf("%d",c[j-1]);//输出不为零的结果


return 0;
}*/




/*1006
#include<stdio.h>
int main(){
  int i,j,k,m;
  scanf("%d",&k);
  i=(k%10);k/=10;
  j=k%10;k/=10;
  for(m=0;m<k;m++) printf("B");
  for(m=0;m<j;m++) printf("S");
  for(m=1;m<=i;m++) printf("%d",m);
  return 0;
}


*/


/*1007
#include<stdio.h>
#include<math.h>
int main(){
  int i,j,flag,k;
  int a[10000];
  int b[10000];
  int m;
  scanf("%d",&k);
  a[0]=3;
  for(i=3,flag=0;i<=k;i++)  
  {   a[i-2]=i;
    for(j=2,m=sqrt(i);j<=m;j++)
    if(a[i-2]%j==0)  break;
    if (j>m)  b[flag++]=i; }
  b[flag]=0;


    for(j=0,i=0;j<flag-1;j++)
    {    //printf("%d",b[j]);
      if((b[j+1]-b[j])==2)  i++;
    }
    printf("%d",i);
      return 0;
}
*/




/*1008   数组循环右移//123456-612345-561234
#include<stdio.h>
int main(){
  int i,j,k,temp;
  int a[101];
  scanf("%d %d",&i,&j);
  for(k=0;k<i;k++)
    scanf("%d",&a[k]);
  for(;j>0;j--)
  { temp=a[i-1];
    for(k=i-1;k>0;k--)
       a[k]=a[k-1];
   a[0]=temp;}
  for(k=0;k<i-1;k++)
    printf("%d ",a[k]);
  printf("%d",a[i-1]);
  return 0;
}*/




/*1009




#include<stdio.h>
#include<string.h>
int main(){
  int i=0,len,j=0,k;
  char a[80];
  char b[80][80];
  gets(a);
  len=strlen(a);
   while(i<len)
   {   
     for(k=0;a[i]!=' '&&i<len;i++)
       b[j][k++]=a[i];
     b[j][k]='\0';
     j++;
     i++;
   }


    for(;j>1;j--)
  printf("%s ",b[j-1]);
  printf("%s",b[j-1]);
    return 0;

}*/





/*1010
#include<stdio.h>
#include<string.h>
int main(){
  int i=0,j=0,l=0;
  //int len;
  int a[2100];
  int b[2100];
  char k;
  while(1){
   scanf("%d",&a[i++]);
   k=getchar();//用getchar来检查scanf后输入的是否为回车
   if(k=='\n')  break; 
  }
  j=i;//将数组实际长度i记录到J
 if(j<=2&&a[j-1]==0)   printf("%d %d",0,0);
 else if (j<=2&&a[j-1]!=0) printf("%d %d",a[0]*a[1],a[1]-1);
 else{   
       for(i=1;i<j&&a[i]>0;i+=2)//0次方不用求导
     { b[i-1]=a[i]*a[i-1]; b[i]=a[i]-1;}
         j=i-1;
    for(i=0;i<j-1;i++)
      printf("%d ",b[i]);
    printf("%d",b[i]);}


  return 0;
}*/
