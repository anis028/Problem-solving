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
 
bitset<50002>flag;
bitset<100009>segment;
int prime[8000],len;
int sieve(int n)
{
    flag.reset();
 
    for(int i=3; i*i<=n; i+=2){
        if(!flag[i]){
            for(int j=i*i; j<=n; j+=(i<<1))
                flag[j]=1;
        }
    }
    int ind=1;
    prime[0]=2;
 
    for(int i=3; i<=n; i+=2)
        if(!flag[i]) prime[ind++]=i;
 
    return ind;
}
 
int solve(ll a, ll b)
{
    segment.reset();
    ll lim=sqrt(b)+1;
    for(int i=1 ; i<len and prime[i]<=lim ; i++){
        ll start= prime[i]*prime[i];
        if(start<a) start= ((a+prime[i]-1)/prime[i])*prime[i];
        for(;start<=b;start+=(prime[i]))
            segment[start-a]=1;
    }
    int ret=(a<3 and b>1);
    ll j=a+(1^(a%2));
    for(;j<=b;j+=2)
        if(!segment[j-a]) ret++;
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    len=sieve(46350);
    while(tc--){
        int a,b;
        cin>>a>>b;
        cout<<"Case "<<cas++<<": "<<solve(a+(a==1),b)<<endl;
    }
    return 0;
}
/*sample
 
*/
