#include "stdio.h"
void main()
{
    int T,n;
    int i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",n);
        for(i=0;i<n-1;i++)
        {
            printf("1 ");
        }
        printf("1");
    }
}
