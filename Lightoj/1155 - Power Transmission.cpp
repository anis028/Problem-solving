#include <algorithm>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;
 
const int maxnodes = 5000;
 
int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];
 
struct Edge
{
    int to, rev;
    int f, cap;
};
 
vector<Edge> g[maxnodes];
 
// Adds bidirectional edge
void addEdge(int s, int t, int cap1,int cap2)
{
    Edge a = {t, g[t].size(), 0, cap1};
    Edge b = {s, g[s].size(), 0, cap2};
    g[s].push_back(a);
    g[t].push_back(b);
}
 
bool dinic_bfs()
{
//    cout<<"came for bfs "<<endl;
    fill(dist, dist + nodes, -1);
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for (int qh = 0; qh < qt; qh++)
    {
        int u = q[qh];
//        cout<<u<<" ";
        for (int j = 0; j < (int) g[u].size(); j++)
        {
            Edge &e = g[u][j];
            int v = e.to;
            if (dist[v] < 0 && e.f < e.cap)
            {
                dist[v] = dist[u] + 1;
                q[qt++] = v;
            }
        }
    }
//    cout<<endl;
    return dist[dest] >= 0;
}
 
int dinic_dfs(int u, int f)
{
//    cout<<u<<" ";
    if (u == dest)
        return f;
    for (int &i = work[u]; i < (int) g[u].size(); i++)
    {
        Edge &e = g[u][i];
        if (e.cap <= e.f)
            continue;
        int v = e.to;
        if (dist[v] == dist[u] + 1)
        {
            int df = dinic_dfs(v, min(f, e.cap - e.f));
            if (df > 0)
            {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}
 
int maxFlow(int _src, int _dest)
{
    src = _src;
    dest = _dest;
    int result = 0;
    while (dinic_bfs())
    {
        fill(work, work + nodes, 0);
        while (1)
        {
//            cout<<"going for dfs"<<endl;
            int delta = dinic_dfs(src, INT_MAX);
//            cout<<"Back with flow "<<delta<<endl;
            if(delta==0)
                break;
            result += delta;
        }
    }
    return result;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        int n,s=0,t,edge,u,v,c,x;
        cin>>n;
        t=(n*2)+1;
        for(int i=0;i<=t;i++) g[i].clear();
        for(int i=1;i<t;i+=2){
            cin>>c;
            addEdge(i,i+1,c,0);
        }
        cin>>edge;
        while(edge--){
            cin>>u>>v>>c;
            u*=2;
            v=(v*2)-1;
            addEdge(u,v,c,0);
        }
        int b,d;
        cin>>b>>d;
        for(int i=0;i<b+d;i++){
            cin>>x;
            if(i<b){
                x=(x*2)-1;
                addEdge(0,x,1e8,0);
            }
            else{
                x*=2;
                addEdge(x,t,1e8,0);
            }
        }
        cout<<"Case "<<cas++<<": "<<maxFlow(s,t)<<endl;
    }
}
