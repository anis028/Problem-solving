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
 
vector<int> g[10005];
int vis[10005],dis[10005],low[10005],cut[10005],dfstime,cnt,cuts,comp;
 
void find_cut(int u,int p)
{
    dis[u]= low[u]= ++dfstime;
    vis[u]=1;
    int child=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==p) continue;
        if(vis[v]) low[u]=min(low[u],dis[v]);
        else{
            child++;
            find_cut(v,u);
            low[u]=min(low[u],low[v]);
            if(dis[u]<=low[v]) cut[u]=1;
        }
    }
    if(p==-1) cut[u] = (child>1);
}
 
void dfs(int u)
{
//    cout<<"visiting "<<u<<endl;
    vis[u]=1,cnt++;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
//        cout<<v<<" "<<cut[v]<<" "<<vis[v]<<endl;
        if(!cut[v] and !vis[v]) dfs(v);
        if(cut[v] and vis[v]!=comp+1) cuts++, vis[v]=comp+1;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int n,e;
        cin>>n>>e;
        for(int i=0;i<n;i++){
            g[i].clear();
            vis[i]=0;
            low[i]=0;
            cut[i]=0;
            dis[i]=0;
        }
        int u,v;
        for(int i=0;i<e;i++){
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfstime=0;
        find_cut(0,-1);
        mm(vis,0);
        unsigned long long nways=1;
        int need=0;
        comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i] and !cut[i]){
                cnt=cuts=0;
                dfs(i);
                comp++;
                if(cuts<2){
                    nways *= cnt;
                    need++;
                }
            }
        }
        if(need==1) need=2, nways=(n*(n-1))>>1;
        cout<<"Case "<<cas++<<": "<<need<<" "<<nways<<endl;
    }
    return 0;
}
/*sample
 
*/
 
