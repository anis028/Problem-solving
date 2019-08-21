#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   pli           pair<ll,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
using namespace std;
typedef long long ll;
typedef double dbl;
 
bitset<1000009>flag;
ll prime[78600],tot;
void sieve(ll n)
{
    flag.reset();
    for(int i=4; i<=n; i+=2)flag[i]=1;
 
    for(ll i=3; i*i<=n; i+=2){
        if(!flag[i]){
            for(ll j=i*i; j<=n; j+=(i<<1))
                flag[j]=1;
        }
    }
    prime[tot++]=2;
 
    for(int i=3; i<=n; i+=2)
        if(!flag[i]) prime[tot++]=i;
}
 
vector<pli > factorize(ll n)
{
    vector<pli> ret;
    for(int i=0; prime[i]*prime[i]<=n and i<tot;i++){
        if(n%prime[i]==0){
            int cnt=0;
            while(n%prime[i]==0){
                cnt++;
                n/=prime[i];
            }
            ret.pb({prime[i],cnt});
        }
    }
    if(n>1) ret.pb({n,1});
    return ret;
}
 
vector<ll>divi;
void get_divi(int ind, ll now, ll lo, ll hi,vector<pli>v)
{
    if(ind==v.size()){
        if(now>=lo and now<=hi) divi.pb(now);
        return;
    }
    for(int i=0;i<=v[ind].sc;i++){
        get_divi(ind+1,now,lo,hi,v);
        now *= v[ind].fs;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    sieve(1000001);
    cin>>tc;
    while(tc--){
        ll a,b;
        cin>>a>>b;
        vector<pli>fact = factorize(a);
        divi.clear();
        get_divi(0,1,b,a/b,fact);
        cout<<"Case "<<cas++<<": "<<divi.size()/2<<endl;
    }
    return 0;
}
/*sample
 
*/
 
