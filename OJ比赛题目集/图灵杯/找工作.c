#include "stdio.h"
void main()  //n=0时输出n
{
    int T;
    int n[100];
    int i,j;
    int arr[100][100];
    int zer0;
    scanf("%d",&T);
    for(j=0;j<T;j++)
    {
        scanf("%d",&n[j]);
        for(i=0;i<=n[j];i++)  //输入的是最高次幂的项数 n+1
        {
            scanf("%d",&arr[j][i]);
            if(i!=n[j])
            {
                arr[j][i]*=(n[j]-i);
            }
        }

    }
    for(i=0;i<T;i++)
    {
        if(n[i]!=0)
        {
            if(i!=T-1)
        {
            for(j=0;j<n[i];j++)
            {
                if(j!=(n[i]-1))
                {
                    if(arr[i][j]!=0)
                      printf("%d ",arr[i][j]);
                }
                else
                {
                    if(arr[i][j]!=0)
                    printf("%d",arr[i][j]);

                }

            }
            printf("\n");
        }
        else
        {
            for(j=0;j<n[i];j++)
            {
                if(j!=(n[i]-1))
                {
                    if(arr[i][j]!=0)
                    printf("%d ",arr[i][j]);
                }
                else
                {
                    if(arr[i][j]!=0)
                    printf("%d",arr[i][j]);

                }

            }
        }

        }
        else
        {
            if(i!=T-1)
              printf("0\n");
              else printf("0");
        }

    }
}
