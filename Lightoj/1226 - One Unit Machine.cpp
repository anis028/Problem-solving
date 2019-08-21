#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
ll bm(ll b, int p)
{
    ll ret=1;
    while(p>0){
        if(p&1) ret=(ret*b)%mod;
        b=(b*b)%mod;
        p/=2;
    }
    return ret;
}
ll fact[1000006];
 
ll ncr(ll n,ll r)
{
    if(r==0 || r==n) return 1;
    ll ret=1;
    ret=(fact[r]*fact[n-r])%mod;
    ret=(bm(ret,mod-2))%mod;
    ret=(ret*fact[n])%mod;
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<1000006;i++) fact[i]=(fact[i-1]*i)%mod;
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        int n,x,sum;
        cin>>n>>x;
        ll ans=1,tmp;
        sum=x;
        for(int i=0;i<n-1;i++){
            cin>>x;
            sum+=x;
            ans=(ans*ncr(sum-1,x-1))%mod;
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
