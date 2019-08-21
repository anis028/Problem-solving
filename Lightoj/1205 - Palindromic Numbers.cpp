#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long int ll;
 
ll dp[20][20];
vector<int>v;
 
inline ll solve(int len,int l,int r,int tight,int ok)
{
    if(l<r) return tight==0 || (tight&&ok);
    if(tight==0 and dp[len][l]!=-1) return dp[len][l];
    ll ret=0;
    int lim=tight? v[l]:9;
    for(int i=0;i<=lim ;i++)
    {
        if(l==len-1 and i==0) continue;
        int g=ok;
        if(g) g=(v[r]>=i);
        else g=(v[r]>i);
        ret+=solve(len,l-1,r+1,i==lim and tight,g);
    }
    if(tight==0) dp[len][l]=ret;
    return ret;
}
 
inline ll go(ll n)
{
    if(n<0) return 0;
    if(n==0) return 1;
    ll ans=1;
    v.clear();
    while(n){v.pb(n%10);n/=10;};
    int l=v.size();
    for(int i=l;i>0;i--)
        ans+=solve(i,i-1,0,i==l,1);
    return ans;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    memset(dp,-1,sizeof dp);
    while(tc--)
    {
        ll l,r;
        scanf("%lld %lld",&l,&r);
        if(r<l) swap(l,r);
        printf("Case %d: %lld\n",cas++,go(r)-go(l-1));
    }
    return 0;
}
/*sample
 
*/
