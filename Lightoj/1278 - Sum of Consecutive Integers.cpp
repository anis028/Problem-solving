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
 
bitset<10000007>flag;
int prime[664600],tot;
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
 
vector<pii> factorize(ll n)
{
    vector<pii> ret;
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
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    sieve(10000002);
    //cout<<tot<<endl;
    while(tc--){
        ll n;
        cin>>n;
        vector<pii>fact = factorize(n);
        int ans=1;
        for(int i=0;i<fact.size();i++){
            if(fact[i].fs==2) continue;
            ans *= (fact[i].sc+1);
        }
        cout<<"Case "<<cas++<<": "<<ans-1<<endl;
    }
    return 0;
}
/*sample
 
*/
///https://www.cnblogs.com/zhengguiping--9876/p/6026910.html
 

