#include "stdio.h"
int f(int n)
{
    int i;
    if(n <= 0)
    return 0;
    if(n == 1)
    return 1;
    int f = 1;
    for(i = 2; i <= n; i++)
    {
    f = 2 * f;
    }
    return f;
}
void main()
{
    int m,n;
    scanf("%d",&m);  //ÌøÊý
    scanf("%d",&n);  //Ì¨½×Êý
    if(m>=n)
    {
        printf("%d",f(n)%1000000007);
    }
    else if(m<n)
    {

    }
    else
        printf("%d",f(n)+1);

}
