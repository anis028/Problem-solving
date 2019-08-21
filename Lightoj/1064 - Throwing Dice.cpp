#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   m0d           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
ll power[27],dp[27][155];
int n,x;
 
ll solve(int pos,int sum)
{
    if(pos>n) return sum>=x ? 1 : 0;
    ll &ret= dp[pos][sum];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=1;i<=6;i++) ret+=solve(pos+1,sum+i);
    return ret;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    power[0]=1;
    for(int i=1;i<=25;i++) power[i]= power[i-1]*(ll)6;
    while(tc--){
        mm(dp,-1);
        scanf("%d %d",&n,&x);
        ll u = solve(1,0);
        ll v = power[n];
        ll gcd = __gcd(u,v);
        u /= gcd;
        v /= gcd;
        printf("Case %d: %lld",cas++,u);
        if(v!=1) printf("/%lld",v);
        printf("\n");
    }
    return 0;
}
/*sample
 
*/
 
