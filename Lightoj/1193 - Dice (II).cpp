#include<stdio.h>
#include<string.h>
#define mod 100000007
long long  dp[2][15008];
long long  sum[15008];
int  main()
{
    int  t,n,k,s,i,j,now,cas=1;
 
    scanf( "%d" ,&t);
    while (t--)
    {
        scanf( "%d%d%d" ,&n,&k,&s);
        memset(dp,0, sizeof (dp));
        for (i=1;i<=k;i++) dp[1][i]=i;
        for (i=2; i<=n; i++)
        {
            now=i&1;
            memset(sum,0, sizeof (sum));
            for (j=1; j<=s; j++)
            {
                sum[j]=(sum[j-1]+dp[now^1][j])%mod;
                dp[now][j]=(dp[now][j-1]+sum[j-1])%mod;
                if (j>k) dp[now][j]=((dp[now][j]-sum[j-k-1]-dp[now^1][j-k-1]*k)%mod+mod) %mod;
            }
        }
        printf( "Case %d: %lld\n" ,cas++,dp[n&1][s]);
    }
 
    return  0;
}
