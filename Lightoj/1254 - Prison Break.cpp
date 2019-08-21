#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair<int,int> pii;
typedef pair<int,pii> ppii;
 
int daam[1005], dis[1005][105],n;
vector<pii>g[1005];
 
int dijkstra(int s,int e,int capa)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<=capa;j++) dis[i][j]=1e9;
    dis[s][0]=0;
    priority_queue<ppii> pq;
    pq.push({0,{0,s}});
    while(!pq.empty()){
        int u = pq.top().sc.sc;
        int fuel = pq.top().sc.fs;
        pq.pop();
 
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].fs;
            int w=g[u][i].sc;
            if(fuel>=w){
                if(dis[v][fuel-w]>dis[u][fuel]){
                    dis[v][fuel-w] = dis[u][fuel];
                    pq.push({-dis[u][fuel],{fuel-w,v}});
                }
            }
        }
        if(fuel < capa){
            if(dis[u][fuel+1] > dis[u][fuel]+daam[u]){
                dis[u][fuel+1] = dis[u][fuel]+daam[u];
                pq.push({-dis[u][fuel+1],{fuel+1,u}});
            }
        }
    }
    return dis[e][0];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int roads,u,v,w,q;
        cin>>n>>roads;
        for(int i=0;i<n;i++) cin>>daam[i],g[i].clear();
        while(roads--){
            cin>>u>>v>>w;
            g[u].pb({v,w});
            g[v].pb({u,w});
        }
        cin>>q;
        cout<<"Case "<<cas++<<":"<<endl;
        while(q--){
            int s,d,capa;
            cin>>capa>>s>>d;
            int ans = dijkstra (s,d,capa);
            if(ans==1e9) cout<<"impossible"<<endl;
            else cout<<ans<<endl;
        }
    }
    return 0;
}
/*sample
 
*/
