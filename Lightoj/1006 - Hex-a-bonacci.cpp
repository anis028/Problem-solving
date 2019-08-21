#include<bits/stdc++.h>
#define mx 10000007
using namespace std;
int dp[10005];
int a, b, c, d, e, f;
int fn( int n )
{
    if( n == 0 ) return dp[n]=a%mx;
    if( n == 1 ) return dp[n]=b%mx;
    if( n == 2 ) return dp[n]=c%mx;
    if( n == 3 ) return dp[n]=d%mx;
    if( n == 4 ) return dp[n]=e%mx;
    if( n == 5 ) return dp[n]=f%mx;
    if(dp[n]==-1)return dp[n]=(fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%mx;
        else return dp[n];
            return dp[n];
}
int main()
{
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
