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
 
int prime[46350];
vector<ll>primes;
void seive(int n)
{
    prime[0]=prime[1]=1;
    for(int i=4; i<n; i+=2)prime[i]=1;
    for(int i=3; i*i<n; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<n; j+=i)prime[j]=1;
        }
    }
    for(int i=0;i<n;i++)
        if(prime[i]==0) primes.push_back(i);
}
ll bm(ll b, ll p)
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
    ios_base::sync_with_stdio(false);
    seive(46350);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        ll n,p,x,ans=1;
        cin>>n>>p;
        x=n;
        for(int i=0;primes[i]*primes[i]<=x;i++){
            if(x%primes[i]==0){
                ll cnt=0;
                while(x%primes[i]==0){
                    cnt+=1;
                    x/=primes[i];
                }
                cnt=(cnt*p)+1;
                //cout<<primes[i]<<" "<<cnt<<endl;
                ans=(ans*(bm(primes[i],cnt)-1))%mod;
                if(ans<0) ans+=mod;
                ans=(ans*bm(primes[i]-1,mod-2))%mod;
                //cout<<ans<<endl;
            }
        }
        if(x>1){
            ans=(ans*(bm(x,p+1)-1))%mod;
            if(ans<0) ans+=mod;
            ans=(ans*bm(x-1,mod-2))%mod;
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
