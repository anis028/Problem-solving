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
 
ll fact[1005];
vector<int>g[1005];
int in[1005],vis[1005],cas,sz[1005],root;
 
ll bm(ll b, int p)
{
    ll ret=1;
    while(p>0){
        if(p&1) ret=(ret*b)%mod;
        b=(b*b)%mod;
        p/=2;
    }
    return ret;
}
 
ll dfs(int u)
{
//    cout<<u<<endl;
    vis[u]=1;
    sz[u]=1;
    if(g[u].size()==1 and u!=root) return 1ll;
    ll ret=1,tmp=1;
    int tot=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
//        cout<<"-"<<v<<endl;
        if(vis[v]==0){
            ret=(ret*dfs(v))%mod;
            sz[u]+=sz[v];
            ret=(ret*bm(fact[sz[v]],mod-2))%mod;
        }
    }
    ret=(ret*fact[sz[u]-1])%mod;
//    cout<<u<<"--->"<<ret<<endl;
    return ret;
}
 
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<1005;i++) fact[i]=(fact[i-1]*i)%mod;
    int tc;
    cin>>tc;
    cas=1;
    while(tc--){
        for(int i=0;i<1005;i++) g[i].clear(),in[i]=0,sz[i]=0,vis[i]=0;
        int n,u,v;
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
            in[v]++;
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0)
            {
                root=i;
                ll ans = dfs(root)%mod;
                cout<<"Case "<<cas++<<": "<<ans<<endl;
                break;
            }
        }
    }
    return 0;
}
/*sample
 
*/
