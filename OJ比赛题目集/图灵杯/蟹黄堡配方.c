#include "stdio.h"
#include "string.h"
void main()
{
    int T,n;
    int i,j;
    int flag=0;
    /*char a[100000];  //调料1
    char b[100][100000];  //调料2  代求
    char s[100000]; */ //蟹黄堡
    char a[100];  //调料1
    char b[100][100];  //调料2  代求
    char s[100];  //蟹黄堡
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);  //字符串长度
        scanf("%s",a);
        scanf("%s",s);
        for(j=0;j<n;j++)
        {
            if(a[j]>=s[j])
            {
                strcat(b[i],s+j);


            }

            else
            {

                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            b[i][0]='0';
        }
        flag=0;
    }
    for(i=0;i<T;i++)
    {
        if(b[i][0]!='0')
            printf("%s\n",b[i]);
        else
            printf("-1\n");
    }

}
