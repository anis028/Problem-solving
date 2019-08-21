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
const int N=1e8+5;
 
unsigned int mul[5861460];
 
bitset<N+5>flag;
int prime[5861460],len;
int sieve(int n)
{
    flag.reset();
    for(int i=4; i<=n; i+=2)flag[i]=1;
 
    for(int i=3; i*i<=n; i+=2){
        if(!flag[i]){
            for(int j=i*i; j<=n; j+=(i<<1))
                flag[j]=1;
        }
    }
    int ind=1;
    prime[0]=2;
 
    for(int i=3; i<=n; i++)
        if(!flag[i]) prime[ind++]=i;
 
    return ind;
}
 
void init_lcm()
{
    len=sieve(N);
    mul[0]=prime[0];
    for(int i=1; i<len; i++)
        mul[i]=mul[i-1]*prime[i];
}
 
void solve(int n)
{
    int pos=lower_bound(prime,prime+len,n)-prime;
    if(prime[pos]!=n)
        pos--;
    unsigned int ans=mul[pos];
    for(int i=0; prime[i]*prime[i]<=n; i++)
    {
        int x=prime[i];
        int y=prime[i]*prime[i];
        while(y/x==prime[i] and y<=n)
        {
            x*=prime[i];
            y*=prime[i];
        }
        ans*=(x/prime[i]);
    }
    cout<<ans<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    init_lcm();
    while(tc--)
    {
        int n;
        cin>>n;
        cout<<"Case "<<cas++<<": ";
        solve(n);
    }
    return 0;
}
/*sample
 
*/
