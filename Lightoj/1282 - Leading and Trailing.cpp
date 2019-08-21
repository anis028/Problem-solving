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
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;
        double m = k*log10(n) - (int)(k*log10(n));
        m = pow(10,m);
        printf("Case %d: %d %03d\n", cas++, (int)(m*100.0), bm(n,k,1000));
    }
    return 0;
}
/*sample
 
*/
