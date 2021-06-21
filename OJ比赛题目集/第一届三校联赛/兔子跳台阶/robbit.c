#include "stdio.h"
#include "math.h"
#define mod 1000000007
#define  maxn  1000000
typedef long long  ll;
int n,m;
ll dp[maxn+5];
//快速取幂
ll powmod(ll a,ll b)   //求平方 此算法会大大缩短时间
{
    a%=mod;              //递推基数
    ll res=1;            //所求结果
    while(b)             //把b看做二进制数进行处理
    {

        if(b&1) res=res*a%mod;  //如果当前bn是0 则乘一 是1 则乘a(上一次是an-1*an-1)%c
        a=a*a%mod;                  // 更新A 下一次bn是一则相乘 不是一默认不乘（相当与不执行任何操作） 核心递推关系
        b>>=1;
    }
    return res;
}
void main()
{

    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=1;i<=m;i++)
    {
        dp[i]=powmod(2,i-1);
    }
    if(n<=m)
        printf("%lld",dp[n]);
    else
    {
        for(i=m+1;i<=n;i++)
            for(j=1;j<=m;j++)
                dp[i]=(dp[i]+dp[i-j])%mod;
        printf("%d",dp[n]);
    }

}
