#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
vector<int>v;
 
void getdig(long long a)
{
    v.clear();
    while(a)
    {
        v.pb(a%10);
        a/=10;
    }
}
 
long long dp[12][12];
int ntight;
 
long long solve(int idx,int tight,int x,int nisi)
{
    if(idx==-1) return (nisi)?x:1;
    if(dp[idx][x]!=-1 and tight!=1 and nisi) return dp[idx][x];
    long long ret=0;
    int k=(tight)?v[idx]:9;
    for(int i=0; i<=k; i++)
    {
        ntight= (v[idx]==i)?tight:0;
        if(i==0)
        {
            if(nisi) ret+=solve(idx-1,ntight,x+1,nisi);
            else ret+=solve(idx-1,ntight,0,0);
        }
        else ret+=solve(idx-1,ntight,x,1);
    }
    if(nisi and tight==0) dp[idx][x]=ret;
    return ret;
}
 
long long go(long long x)
{
    if(x<0) return 0;
    if(x==0) return 1;
    getdig(x);
    return solve(v.size()-1,1,0,0);
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    memset(dp,-1,sizeof dp);
    while(tc--)
    {
        long long a,b;
        scanf("%lld %lld",&a,&b);
        long long ans=go(b);
        long long ans1=go(a-1);
        printf("Case %d: %lld\n",cas++,ans-ans1);
    }
    return 0;
}
/*sample
 
*/
