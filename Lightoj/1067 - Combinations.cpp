#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mod           1000003
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
 
ll fact[1000002],ifact[1000002];
 
ll ncr(ll n,ll r)
{
    if(n<=0 || r>n ) return 0;
    ll ret=(fact[n]*ifact[r])%mod;
    return ret=(ret*ifact[n-r])%mod;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    fact[0]=ifact[0]=1;
    for(int i=1;i<1000002;i++){
        fact[i]=(fact[i-1]*(ll)i)%mod;
        ifact[i]=(ifact[i-1]*bm(i,mod-2))%mod;
    }
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int n,r;
        cin>>n>>r;
        cout<<"Case "<<cas++<< ": "<<ncr(n,r)<<endl;
    }
    return 0;
}
/*sample
 
*/
