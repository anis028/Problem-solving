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
 
int ara[10005],mark[1000005],phi[1000005];
 
void phi_sieve(int n)
{
    for(int i=0; i<n; i++)
        phi[i]=i;
    for(int i=2; i<n; i++){
        if(!mark[i]){
            for(int j=i; j<n; j+=i){
                mark[i]=1;
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    phi_sieve(1000005);
    while(tc--)
    {
        int n,last=0,ind=0;
        cin>>n;
        for(int i=0; i<n; i++) cin>>ara[i];
        sort(ara,ara+n);
        ll ans=0;
        for(int i=2;i<1000004;i++){
            while(phi[i]>=ara[ind] and ind<n){
                ans+=i;
                ind++;
            }
            if(ind==n) break;
        }
        cout<<"Case "<<cas++<<": "<<ans<<" Xukha"<<endl;
    }
    return 0;
}
/*sample
 
*/
