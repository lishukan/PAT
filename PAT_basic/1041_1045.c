// 1041 考试座位号 Seat number of Examination
/*
#include<stdio.h>//直接把每行第二个输入当作结构体数组的下标
#include<malloc.h>
struct node{
       char s[15];
  int t;
  int c;
};
int main(){
struct node *p=malloc(sizeof(struct node)*1001);
int n,i,k;
     struct node temp;
int need[1001];
char c;
scanf("%d",&n);
for(i=0;i<n;i++)
{ scanf("%s %d %d",&temp.s,&temp.t,&temp.c);
   p[temp.t]=temp;
}


scanf("%d",&k);
for(i=0;i<k;i++)
scanf("%d",&need[i]);
for(i=0;i<k;i++)
printf("%s %d\n",p[need[i]].s,p[need[i]].c);
return 0;
}*/




//1042 字符统计 Character statistics
/*
#include<stdio.h>
int cmp(int *i,int *j){
     return *j-*i;
}
int main(){
int num[200]={0};
char temp,flag;
char c;
int k=0;
    while((c=getchar())!='\n')
{
if(c>='A'&&c<='Z')  {c+=32;num[c]++;}
else if(c<='z'&&c>='a') num[c]++;
if(num[c]>k)  {flag=c;k=num[c];}
else if(num[c]==k) {if(c<flag)    flag=c;}
}  
     printf("%c %d",flag,k);
return 0;
}*/


//1043 输出patest
/*
#include<stdio.h>
int main(){
  char c;
   int a[7]={0};
int flag=0;
int i,j;
   while((c=getchar())!='\n')
{
    switch(c)
  { 
     case 'P':a[0]++;flag++;break; 
     case 'A':a[1]++;flag++;break;
     case 'T':a[2]++;flag++;break;
     case 'e':a[3]++;flag++;break;
     case 's':a[4]++;flag++;break;
     case 't':a[5]++;flag++;break;  
     default :break;
    
 }
}


while(flag>0)
 {
   for(j=0;j<6;j++)
   {
         if(a[0]>0) {printf("P");a[0]--;flag--;} 
         if(a[1]>0) {printf("A");a[1]--;flag--;}
      if(a[2]>0) {printf("T");a[2]--;flag--;}
         if(a[3]>0) {printf("e");a[3]--;flag--;}
         if(a[4]>0) {printf("s");a[4]--;flag--;}
         if(a[5]>0) {printf("t");a[5]--;flag--;}
    } 
 }    


return 0;
}*/




//1044 火星数字 
//tmd  看错了题目意思，题目讲13的倍数，不用打印tret，例如，26-》hel，39-》maa，而不是maa tret


/*
#include<stdio.h>
#include<string.h>
int main(){
  char s[100][8];
  char temp1[5]={""},temp2[5]={""};        //                                                                   
  int n,i,j,flag,k=0;// 0   1                                                                           12   13        26     39                                                                 
  char mars[25][5]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
   scanf("%d",&n);
  // fflush(stdin);//清除缓冲区，防止下一次gets会读取这一次的回车字符
   getchar();//为什么我用fflush不行？？？？？
   for(i=0;i<n;i++)
   { gets(s[i]);
  
         flag=0;
     if(s[i][0]>='0'&&s[i][0]<='9') //数字
     {
       for(j=0;s[i][j]!='\0';j++)
         flag=flag*10+(s[i][j]-'0');
         if(flag<13) printf("%s",mars[flag%13]);
       else 
       {
           printf("%s",mars[12+flag/13]);
            if(flag%13!=0) printf(" %s",mars[flag%13]);
       }    
     }
     else//火星文
     {


      if(s[i][0]=='t'&&s[i][1]=='r') flag=0;//如果输入为tret，必须单独拿出来，不然之后的输入出错，butwhy？
      else                                 //  如果不单独的话，要用memset（temp，0，sizeof（temp））；语句来先清空清空字符串；
      {      k=0;j=0;                      // 不然的话，第一次输入tret，temp【3】=t，下一次输入tam，这时temp【3】还是t（本来应该是‘\0’）；
        temp1[0]=0;temp2[0]=0;             //memset库函数，是清空字符串。
        while(s[i][j]>='a'&&s[i][j]<='z')
        {
          temp1[k]=s[i][j];
          k++;
          j++;
        }
         if(s[i][j]!='\0')//两位火星文
         {
           k=0;
           for(j++;s[i][j]!='\0';j++)
           {     temp2[k]=s[i][j];
              k++;
           }
           for(j=13;j<25;j++)
             if(!strcmp(temp1,mars[j]))    {flag=(j-12)*13;  break;}
          for(j=0;j<13;j++)
            if(!strcmp(temp2,mars[j]))        { flag+=j;break;}
         }
         else//一位火星文
         {
           for(j=0;j<25;j++)
             if(!strcmp(temp1,mars[j]))      break;
           if(j>12) flag=(j-12)*13;
             else flag=j;
         }
      //   printf("%d",flag);
      }
      printf("%d",flag);


     }
     printf("\n");
   }
   return 0;
}*/
 
//1045 快速排序 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int cmp(const void *i, const void  *j){
      return *(long long int * )i-*(long long int *)j;
}
int main(){
     
   int n,i,j,flag=0;
   long long int max=0;
   long long int *s=(long long *)malloc(100001*sizeof(long long int) );
   long long int *q=(long long *)malloc(100001*sizeof(long long int));
   long long int *out=(long long *)malloc(100001*sizeof(long long int));
   scanf("%d",&n);
  //               将输入的数组拷贝到另一个数组，对其排序，比较两个数组，同一下标数值相同的且大于前面最大值的就是什么什么元 
  for(i=0;i<n;i++)         //                        q  1 2 3 4 5 6 7 8 9  
  {   scanf("%lld",&s[i]);  //                  s  1 3 2 4 5 6 7 9 8  --1，4，5，6，7 
      q[i]=s[i];                  //            s  1 7 2 5 4 6 8 3 9 -1,9(虽然6和Q6一样，但是6小于前面数组的最大值7，)
  }                                    //       不用考虑是否小于后面的数，数组和是一样的，只要大于前面任何一个，肯定小于后面任何数 
   qsort(q,n,sizeof(q[0]),cmp);
 
max=s[0];
if(q[0]==s[0])  {out[0]=q[0];flag++;}
for(i=1;i<n-1;i++)
 {
  if(s[i-1]>max) max=s[i-1];
  if(q[i]==s[i]&&s[i]>max)
  { 
 out[flag]=q[i];
   flag++;
 
   }
   else continue;
 }
if(q[n-1]==s[n-1])  {
out[flag]=q[n-1];flag++;
}
 printf("%d\n",flag);
 if(flag==0) printf("\n");//题目说了要输出第二行，就算是0，也要输出空行 
 else if (flag==1) printf("%lld",out[0]);
 else{
        for(i=0;i<flag-1;i++)
         printf("%lld ",out[i]);
         printf("%lld",out[flag-1]);
        
 }
  return 0;
}
