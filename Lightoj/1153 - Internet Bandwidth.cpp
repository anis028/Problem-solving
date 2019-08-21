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
void addEdge(int s, int t, int cap)
{
    Edge a = {t, g[t].size(), 0, cap};
    Edge b = {s, g[s].size(), 0, cap};
    g[s].push_back(a);
    g[t].push_back(b);
}
 
bool dinic_bfs()
{
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
//        cout<<"as"<<endl;
        fill(work, work + nodes, 0);
        while (1)
        {
            int delta = dinic_dfs(src, INT_MAX);
            if(delta==0)
                break;
//            cout<<endl<<"jai"<<endl;
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
        int n,s,t,edge,u,v,c;
        cin>>n>>s>>t>>edge;
        for(int i=0;i<=n;i++) g[i].clear();
        while(edge--)
            cin>>u>>v>>c,addEdge(u,v,c);
        cout<<"Case "<<cas++<<": "<<maxFlow(s,t)<<endl;
    }
}
 
