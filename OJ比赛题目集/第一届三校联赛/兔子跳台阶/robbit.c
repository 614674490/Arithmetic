#include "stdio.h"
#include "math.h"
#define mod 1000000007
#define  maxn  1000000
typedef long long  ll;
int n,m;
ll dp[maxn+5];
//����ȡ��
ll powmod(ll a,ll b)   //��ƽ�� ���㷨��������ʱ��
{
    a%=mod;              //���ƻ���
    ll res=1;            //������
    while(b)             //��b���������������д���
    {

        if(b&1) res=res*a%mod;  //�����ǰbn��0 ���һ ��1 ���a(��һ����an-1*an-1)%c
        a=a*a%mod;                  // ����A ��һ��bn��һ����� ����һĬ�ϲ��ˣ��൱�벻ִ���κβ����� ���ĵ��ƹ�ϵ
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
