#include "stdio.h"
#include "string.h"
void main()
{
    int T,n;
    int i,j;
    int flag=0;
    /*char a[100000];  //����1
    char b[100][100000];  //����2  ����
    char s[100000]; */ //з�Ʊ�
    char a[100];  //����1
    char b[100][100];  //����2  ����
    char s[100];  //з�Ʊ�
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);  //�ַ�������
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
