#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
using namespace std;
typedef long long ll;
typedef double dbl;
 
ll bm(ll b, ll p ,ll mod)
{
    ll ret=1;
    while(p>0){
        if(p&1) ret=(ret*b)%mod;
        b=(b*b)%mod;
        p/=2;
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int x,n,k,mod;
        ll ans=0;
        cin>>n>>k>>mod;
        for(int i=0;i<n;i++){
            cin>>x;
            ans=(ans+(x%mod))%mod;
        }
        ll po = bm(n,k-1,mod);
        ans=((ans*(k%mod)%mod)*po)%mod;
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
