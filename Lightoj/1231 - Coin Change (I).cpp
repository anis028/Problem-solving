#include<bits/stdc++.h>
 
using namespace std;
 
int n,k,dp[55][1005],val[55],coins[55];
 
int rec(int pos,int k)
{
    if(pos==n) return k==0?1:0;
 
    int &ret=dp[pos][k];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=0;i<=coins[pos];i++)
        if(i*val[pos]<=k)
            ret=(ret+rec(pos+1,k-i*val[pos]))%100000007;
    return ret;
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&val[i]);
        for(int i=0;i<n;i++) scanf("%d",&coins[i]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",p++,rec(0,k));
    }
}
