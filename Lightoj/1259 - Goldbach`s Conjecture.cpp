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
int prime[665000],tot;
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
    int tc=1,cas=1;
    cin>>tc;
    sieve(10000003);
    while(tc--){
        int n,ans=0;
        cin>>n;
        for(int i=0; prime[i]<=n/2;i++)
            if(!flag[n-prime[i]]) ans++;
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
 
 
