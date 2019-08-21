#include <bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
 
const int maxnodes = 500;
 
int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];
 
struct Edge
{
    int to, rev;
    int f, cap;
};
 
vector<Edge> g[maxnodes], mirror[maxnodes];
 
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
//    cout<<result<<endl;
    return result;
}
 
pair<double,double>point[305];
int ase[305],dhore[305];
vector<int> ans;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        ans.clear();
        int n,cap,now,sum=0;
        double dis,x,y;
        cin>>n>>dis;
        n<<=1,n++;
        for(int i=0;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i+=2){
            cin>>x>>y>>ase[i]>>dhore[i];
            point[i]={x,y};
            addEdge(i,i+1,dhore[i],0);
            if(ase[i])
                addEdge(0,i,ase[i],0);
            sum+=ase[i];
        }
        for(int i=1;i<n;i+=2){
            for(int j=i+2;j<n;j+=2){
                x=fabs(point[i].fs-point[j].fs);
                y=fabs(point[i].sc-point[j].sc);
                double tmp = sqrt(x*x+y*y);
                if(tmp+1e-9<=dis){
                    addEdge(i+1,j,1e7,0),
                    addEdge(j+1,i,1e7,0);
                }
            }
        }
        for(int i=0;i<n;i++) mirror[i]=g[i];
        for(int i=1;i<n;i+=2){
            for(int j=0;j<n;j++) g[j]=mirror[j];
            if(maxFlow(0,i)==sum) ans.push_back(i>>1);
        }
        cout<<"Case "<<cas++<<":";
        if(ans.size()==0) cout<<" -1";
        else
            for(int i=0;i<ans.size();i++) cout<<" "<<ans[i];
        cout<<endl;
    }
}
/*sample
50
5 3.5
1 1 1 1
2 3 0 1
3 5 1 1
5 1 1 1
5 4 0 1
3 1.1
-1 0 5 10
0 0 3 9
2 0 1 1
*/
 
