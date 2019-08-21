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
 
bitset<10000005>flag;
ll prime[664600],tot;
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
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sieve(1e7+2);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        ll n,ans=1;
        cin>>n;
 
        for(int i=0;i<tot and prime[i]*prime[i]<=n;i++){
            ll cnt=0;
            while(n%prime[i]==0) cnt++,n/=prime[i];
            ans*=(2*cnt+1);
        }
        if(n>1) ans*=3;
        ans=(ans/2)+1;
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
