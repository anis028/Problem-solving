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
 
ll discreteLogarithm(ll a, ll b, ll m)
{
    ll n = (ll) sqrt (m) + 1;
 
    ll an = 1;
    for (int i = 0; i<n; ++i)
        an = (an * a) % m;
 
    unordered_map<ll, ll> value;
 
    for (int i = 1, cur = an; i<= n; ++i)
    {
        if (! value[ cur ])
            value[ cur ] = i;
        cur = (cur * an) % m;
    }
    ll ans=m+1;
    for (int i = 0, cur = b; i<= n; ++i)
    {
        if (value[cur])
        {
            ll tmp = value[cur] * n - i;
            ans = min(tmp, ans);
        }
        cur = (cur * a) % m;
    }
    if(ans!=m+1) return ans;
    return -1;
}
 
int main()
{
    int tc, cas = 1;
    cin >> tc;
    while(tc--){
        ll a, b ;
        cin >> a >> b;
        cout << "Case " << cas++ << ": " << discreteLogarithm(a,b,100000007) << endl;
    }
}
/*sample
 
*/
