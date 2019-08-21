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
 
vector<int> g[10005];
stack<int>st;
int vis[10005];
 
void inline init()
{
    while(!st.empty()) st.pop();
    mm(vis,-1);
    for(int i=1;i<10005;i++) g[i].clear();
}
 
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<g[u].size();i++) if(vis[g[u][i]]==-1) dfs(g[u][i]);
    st.push(u);
}
 
void Dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<g[u].size();i++) if(vis[g[u][i]]==0) Dfs(g[u][i]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        init();
        int u,v,n,edge;
        cin>>n>>edge;
        while(edge--){
            cin>>u>>v;
            g[u].pb(v);
        }
        for(int i=1;i<=n;i++) if(vis[i]==-1) dfs(i);
        mm(vis,0);
        int ans=0;
        while(!st.empty()){
            int u=st.top();
            if(vis[u]);
            else Dfs(u),ans++;
            st.pop();
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
