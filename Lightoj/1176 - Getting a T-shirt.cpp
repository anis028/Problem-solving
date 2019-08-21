#include <bits/stdc++.h>
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
    map<string,int>mp;
    string x,y;
    mp["XS"]=1,mp["S"]=2,mp["M"]=3,mp["L"]=4,mp["XL"]=5,mp["XXL"]=6;
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        int shirt,n,des;
        cin>>shirt>>n;
        shirt*=6;
        des=shirt+n+1;
        for(int i=0;i<=des;i++) g[i].clear();
        for(int i=n+1;i<des;i++) addEdge(i,des,1,0);
        for(int i=1;i<=n;i++){
            addEdge(0,i,1,0);
            cin>>x>>y;
            for(int j=n+mp[x];j<des;j+=6) addEdge(i,j,1,0);
            for(int j=n+mp[y];j<des;j+=6) addEdge(i,j,1,0);
        }
        int flow = maxFlow(0,des);
//        cout<<flow<<endl;
        cout<<"Case "<<cas++<<": ";
        flow==n? cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}
/*sample
34
3 6
L XL
XL L
XXL XL
S XS
M S
M L
1 4
S XL
L S
L XL
L XL
1 1
L M
*/
