#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
int n=0;
char temp[110];
    scanf("%s",temp);
int i;
for(i=0;temp[i]!='\0';i++)
n+=temp[i]-'0';
int num[110];
int j;
if(n==0) {printf("zero");return 0;}
for(i=0;i<110&&n!=0;i++)
    {    num[i]=n%10;
   n/=10;
}
char s[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
printf("%s",s[num[i-1]]);
for(j=i-2;j>=0;j--)
printf(" %s",s[num[j]]);
return 0;
}
