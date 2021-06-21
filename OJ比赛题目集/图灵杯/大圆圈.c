#include "stdio.h"
#define mod  1000000007
void main()
{
    int T,n;
    int val[10000];
    int i=0,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        val[i++]=(n*n-n+2)%mod;
    }
    for(j=0;j<i;j++)
    {
        printf("%d\n",val[j]);
    }
}
