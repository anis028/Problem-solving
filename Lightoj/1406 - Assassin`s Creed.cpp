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
 
vector<int>g[17];
bool vis[15][1<<15],ok[1<<15];
int dp[1<<15];
int n,m;
 
void dfs(int u,int mask)
{
    vis[u][mask]=true;
    ok[mask]=true;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v][mask|(1<<v)]) dfs(v,mask|(1<<v));
    }
}
 
int rec(int mask)
{
    if(mask==0) return 0;
    int &ret=dp[mask];
    if(ret!=-1) return ret;
    ret=20;
    for(int i=mask ; i>0 ; i = mask&(i-1)){
        if(ok[i])
            ret=min(ret,1+rec(mask^i));
    }
    return ret;
}
 
void init()
{
    for(int i=0;i<n;i++) g[i].clear();
    mm(vis,false);
    mm(ok,false);
    mm(dp,-1);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        init();
        cin>>n>>m;
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            g[--u].pb(--v);
        }
        for(int i=0;i<n;i++) dfs(i,(1<<i));
        cout<<"Case "<<cas++<<": "<<rec((1<<n)-1)<<endl;
    }
    return 0;
}
/*sample
 
*/
