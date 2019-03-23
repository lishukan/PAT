//1031 身份验证  check ID number
/*
#include<stdio.h>
int main(){
int n;
char s[100][20];
int i,j,k=0;
int  q[18]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//权重
char m[12]={'1','0','X','9','8','7','6','5','4','3','2'};//校验码m
int flag[100]={0};//每个身份证的标记位
int flag2=1;//是否全部通过的标记
int z;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%s",&s[i]);//按照题目，要先输入完，所以还是不要在输入时就进行判断等操作吧，麻烦
    for(i=0;i<n;i++)
{  z=0;
        for(j=0;j<17;j++)
if(s[i][j]<'0'||s[i][j]>'9') { flag[i]=1;break;}//发现有不是数字的，立flag
else z+=((s[i][j]-'0')*q[j]);
z=z%11;
if(m[z]!=s[i][17]) flag[i]=1;//校验码不对，立个flag
}

for(i=0;i<n;i++)
  if(flag[i]==1) 
  {   printf("%s\n",s[i]);//打印不对的
         flag2=0;//只要有不对的，就不用打印全部通过
  }
    if(flag2) printf("All passed");//


  return 0;
}*/




//1032  挖掘机技术哪家强 Which school is proficient in excavator Technology
/*
#include<stdio.h>
int main(){
  int n,num=0;
  int i;
  int flag=0;
  int max=0;
    int s[100003]={0};//初始化所有元素为0，方便处理
  int school,score;
    scanf("%d",&n);
  for(i=0;i<n;i++)
  {  scanf("%d",&school);
      scanf("%d",&score);
        s[school]+=score;
    if(school>num) num=school;//num用于计数有多少学校
    }
  
  for(i=1;i<=num;i++)
    if(s[i]>max) {max=s[i];flag=i;}
   printf("%d %d",flag,max);
    
  return 0;
}*/


//1033 旧键盘打字  typeing in oldkeyboard
/*为什么啊，为什么不行啊！！！有几个测试点就是过不去！啊啊啊啊为什么啊！求指教
#include<stdio.h>
#include<string.h>
int main(){
char num[11];//存放没用的数字
int  n=0;
char key[30];//没用的字母
int k=0;
char symbol[10];//没用的标点符号
int s=0;
char out[100002];//第二行的输入
int i,j,flag=1,len,tab,none=1;//flag是坏没坏的标记，none是有没有全坏的标记
char c;
    while((c=getchar())!='\n')
{   if(c>='0'&&c<='9')  num[n++]=c;
else if ( c>='A'&&c<='Z')   key[k++]=c;
else if(c=='+' )  tab=1;//大写没用
else symbol[s++]=c;
 } 
    gets(out);
// for(i=0;i<n;i++)
// printf("%c",num[i]);
// for(i=0;i<k;i++)
// printf("%c",key[i]);
// for(i=0;i<s;i++)
// printf("%c",symbol[i]);
len=strlen(out);
for(i=0;i<len;i++)
{
//printf("%c",out[i]);
 if(out[i]<='9'&&out[i]>='0')  
  {for(j=0;j<n;j++)      if(num[j]==out[i])  {flag=0;break;}        }
  else if(out[i]<='Z'&&out[i]>='A')
  {   if(tab==1)  flag=0;
  else for(j=0;j<k;j++)    if(out[i]==key[j])  {flag=0;break;}  }
  else if(out[i]<='z'&&out[i]>='a')
  {  for(j=0;j<k;j++)  if((out[i]-32)==key[j]) {flag=0;break;}      }
  else 
  {  for(j=0;j<s;j++)   if(out[i]==symbol[j]) {flag=0;break;}       }


  if(flag) { printf("%c",out[i]);none=0;}//不是坏键，输出
  flag=1;//下一次循环开始要重新从1开始
  
}
if(none) printf("\n");//测试点1,输出空行
return 0;
}
*/
/*以下是自己百思不得解后看的别人方案后重新写的
#include<stdio.h>
int main(){
int key[200]={0};//将所有键盘都初始化，这里存放的是每个字符的状态位（是否坏，1为坏，这里初始化所有键都是好的）
char c;
int tab=0;
int flag=1;//是否需要输出空行
int i;
while((c=getchar())!='\n')
{
if(c=='+') tab=1;//大写坏了
         else if(c>='A'&&c<='z')  {key[c]=1;key[c+32]=1;}// 相应大小写字母都置1（坏了）
else key[c]=1;
}
if(tab==1) for(i='A';i<='Z';i++) key[i]=1;//将大写的状态都置1
while((c=getchar())!='\n')//////********这里我一直不明白，不是先全部输入完字符再判断再打印吗，怎么这样一个个字符输入判断打印也可以？
{
if(key[c]) continue;//如果坏了就直接跳到判断下一个字符
printf("%c",c);//没坏打印
flag=0;//只要打印了，就不用输出空行
}
if(flag) printf("\n");
return 0;


}


*/


//1034 有理数的四则运算 Four operation of rational numbers
/*      虽然题目说只会输入int，但是！！！这是骗人的tmd，int*int 会溢出，所以还是要用longlongint
#include<stdio.h>
void fuck(long long int a,long long int b){
 long long  int result,c,fenmu,fenzi,flag=0;
    if(b<0)   {b*=(-1);a*=(-1);}//符号提到前面
    if(a<0)  { flag=1;a*=(-1);}//提取分子绝对值，flag用于记录是否有负号
  if(a==0) printf("0");//分子为0直接打印
  else
  {if(flag) printf("(-");//是负数要打印括号，我这里分两头各自打印，要一起打印好麻烦啊
        result=a/b;//记录商
      fenmu=b;//分母
      a=a%b;//余数的分子
      fenzi=a;//记录此时分子，方便日后倍数化简
      if(a==0) printf("%ld",result);//被整除
      else
      {   if(b%a==0)  {fenzi=1;fenmu/=a;}//分子就是最大公约数
       else
       {   while(c=b%a) {b=a; a=c;}//求出来最大公约数是a
           //if(a!=) 
         {c=fenzi/a;fenzi=c;fenmu=fenmu/a;}
       }
        if(result!=0) printf("%ld ",result);//商不为0才要打印，是0就不打印
        printf("%ld/%ld",fenzi,fenmu);//     打印也要用ld
      }
  
     if(flag) printf(")");
  }
}


int main(){
  long long    int a1,b1,a2,b2;
    long long int c;//用来当作每次运算的分母
  scanf("%ld/%ld %ld/%ld",&a1,&b1,&a2,&b2);//用了longlongint之后，切记切记，scanf要用%ld，否则还是只存够int位（32？16？）


  fuck(a1,b1);printf(" + ");fuck(a2,b2);printf(" = ");
  {   c=b1*b2;
     if(a1==0&&a2!=0)  fuck(a2,b2);                
      else if(a2==0&&a1!=0) fuck(a1,b1);
      else if(a1==0&&a2==0) printf("0");
       else  fuck(a1*b2+b1*a2,c);
  printf("\n");
  }
  fuck(a1,b1);printf(" - ");fuck(a2,b2);printf(" = ");
  {
    c=b1*b2;
    if(a1==0&&a2!=0)  fuck(-1*a2,b2);   //切记切记，减负数等于加上他的相反数 ，不要漏了这个            
      else if(a2==0&&a1!=0) fuck(a1,b1);
      else if(a1==0&&a2==0) printf("0");
      else fuck(a1*b2-a2*b1,c);
    printf("\n");
  }
  fuck(a1,b1);printf(" * ");fuck(a2,b2);printf(" = ");
    {
      c=b1*b2;
    if(a1==0||a2==0)  printf("0");             
    else  fuck(a1*a2,c);
    printf("\n");
  }
  fuck(a1,b1);printf(" / ");fuck(a2,b2);printf(" = ");
  {  c=b1*a2;除a等于×a倒数
    if(a2==0) printf("Inf\n");
     else {
           if(a1==0) printf("0");
         else fuck(a1*b2,c);
         printf("\n");
     }
  }
  return 0;
}*/


//1035 插入和归并  insertion sort&merge sort
/*
#include<stdio.h>
#include<stdlib.h>//我tmd，思路和别人一样的，不知道为什么就是有测试点过不去，最后两个测试点（merge）
int cmp(int *i,int *j){
return *i-*j;
}
int equ(int a[],int b[],int len){//判断数组是否一样
      int i;
 for(i=0;i<len;i++)
 if(a[i]!=b[i]) {return 1;break;}
      return 0;
}
void merge(int a[],int j,int n)//以J为单位merge
{
int i;
for(i=0;i+j<=n;i+=j)
qsort(&a[i],j,sizeof(a[0]),cmp);
  qsort(&a[i],n-i,sizeof(a[0]),cmp);
}
int main(){
int flag=-1,flag1,flag2,sum1=0,sum2=0;
int n,j=0,i,k=0;
int s1[101];
int s2[101];
scanf("%d",&n);
for(i=0;i<n;i++) scanf("%d",&s1[i]);
for(i=0;i<n;i++) scanf("%d",&s2[i]);


for(i=0;i<n-1;i++)
if(s2[i]>s2[i+1]) { flag=i;break;}//哪一个数大于后一个数，肯定就是插入终止的那一位
for(i=flag+1;i<n-1;i++)  if(s1[i]==s2[i]) j++;//看两个数组后面有多少个数相同
if(j==(n-flag-2))//insert，如果满足关系式肯定是插入排序,减2是因为，N是数目，flag和J是下标
// for(i=0;i<n-1&&s2[i]<=s2[i+1];i++);//别人的判断方法，两套flag值不一样，换着用小心出错
  //  for(j=i+1;j<n&&s1[j]==s2[j]; j++);
  //  if(j==n)
{
if(flag+2>=n) flag=n;
    else flag+=2;//flag和n都是下标，要加二，不然qsort会失败
qsort(s1,flag,sizeof(s1[0]),cmp);
printf("Insertion Sort\n");

}
else//难点在于如何高效的判断S2是以多少为单位归并的
{ 
printf("Merge Sort\n");
j=2;
flag2=1;
while(flag2)
{ 

merge(s1,j,n);//以2为单位归并
// equ(s1,s2,n);//看归并后数组是否一样
if(equ(s1,s2,n)==0)//如果一样，tmd一开始这里只有if（equ），equ没加参数，编译通过了？结果最后两个测试点一直过不去
{
if(j*2>n) qsort(s1,n,sizeof(s1[0]),cmp);//改了一个晚上，终于通过了
else merge(s1,j*2,n);
    flag2=0;
 
}
else 
{
j*=2;
merge(s1,j,n);
}


/* flag2=0;//以下是别人的方法，感觉和我差不多啊，为什么要加flag=0？，
flag2=equ(s1,s2,n);//这里1为不一样，0为一样
j*=2;
merge(s1,j,n);*/
}
}
for(i=0;i<n-1;i++) printf("%d ",s1[i]); printf("%d",s1[n-1]);//打印


}*/

这一期好难a
