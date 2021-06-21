#include "stdio.h"
int gcd(int a,int b)
{
    int temp;
    int n;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    n=a%b;
    if(n!=0)
        return gcd(b,n);
    else
        return b;
}
void main()
{
    int T;
    int a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==2&&gcd(b,c)==1)
            printf("Yes\n");
        else
            printf("No\n");
    }



}
