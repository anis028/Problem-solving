#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   m0d           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
int dp[1005][2];
vector<int>g[1005];
bool vis[1005];
 
void dfs(int u)
{
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]==false){
            dfs(v);
            dp[u][0]+=max(dp[v][0],dp[v][1]);
            dp[u][1]+=dp[v][0];
        }
    }
    dp[u][1]++;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--){
        mm(dp,0);
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++) g[i].clear();
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        int ans=0;
        mm(vis,false);
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(i);
                ans+=max(dp[i][0],dp[i][1]);
            }
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
/*sample
 
*/
