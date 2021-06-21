#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 200

char fun(int x)
{
    switch(x)
    {
        case 0: return '0';break;
        case 1: return '1';break;
        case 2: return '2';break;
        case 3: return '3';break;
        case 4: return '4';break;
        case 5: return '5';break;
        case 6: return '6';break;
        case 7: return '7';break;
        case 8: return '8';break;
        case 9: return '9';break;
    }
}
int num_str(int l,int r,int x,char str[])
{
    char cmp;
    int num=0;
    str[0]='\0';
    int len=0;
    char temp[5];
    int ans=0;
    int i=0;
    for(i=l;i<=r;i++)
    {
        itoa(i,temp,10);  //要转换的数字 目标字母串 进制格式
        len=strlen(temp);
        temp[len]='\0';
        strcat(str,temp);
        len=strlen(str);
        str[len]='\0';
    }
    cmp=fun(x);
    len=strlen(str);
    str[len]='\0';

    for(i=0;i<len;i++)
    {
        if(str[i]==cmp)
            num++;
    }
    return num;
}
int main()
{
    int ans=0;
    char str[N];
    int L,R,K;   //起点 终点 查询数字
    int num=0;   //所查询数字出现的次数
    while(scanf("%d %d %d",&L,&R,&K)!=EOF)
    {
        ans=num_str(L,R,K,str);
        printf("%d\n",ans);
    }
    return 0;

}
