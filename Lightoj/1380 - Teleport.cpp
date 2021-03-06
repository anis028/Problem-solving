#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define rep(i,n) for(i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef double dbl;
 
const int Maxn = 1005 ; // Highest Vertex
struct edge
{
    int u, v, w ;
    edge() {}
    edge(int _u, int _v, int _w )
    {
        u = _u, v = _v, w = _w ;
    }
};
int nV, nE, root ;   // nV = number of vertex , nE = number of edge , root is root
int vis[Maxn], parnt[Maxn] ;  // vis[] will store from which cycle it belogs , pre[] store its parnt
int Idx[Maxn] ; // will store new indxing Id
int dis[Maxn] ; // store the lowest incoming edge of a root
vector < edge > adj ;
void DMST()
{
    int Res  = 0, i, u,  v, w  ;
    while(1)
    {
        int i  ;
        rep(i,nV)
        {
            dis[i] = 1e9 ;
            vis[i] = -1 ;
            Idx[i] = -1 ;
        }
        rep(i,nE)
        {
            u = adj[i].u ;
            v = adj[i].v ;
            w = adj[i].w ;
            if ( u != v && dis[v] > w) // lowest Incoming Edge
            {
                parnt[v] = u ;
                dis [v] = w ;
            }
        }
        parnt[root] = root ;
        dis[root] = 0 ;
        rep(i,nV)
        {
            if ( dis[i] == 1e9 )
            {
                puts("impossible"); // its not possible to reach
                return ;
            }
            Res += dis[i];
        }
        int idx = 0 ;
        // cycle detection
        rep(i,nV)
        {
 
            if(vis[i]==-1) // not yet visited
            {
                int cur = i ;
                while ( vis[cur]==-1)
                {
                    vis[cur] = i ;
                    cur = parnt[cur] ;
                }
                if ( cur == root || vis[cur] != i )
                    continue ; // not cycle
                Idx[cur] = idx ; // new indexing
                for (  u = parnt[cur] ; cur != u ; u = parnt[u] )
                    Idx[u] = idx ;
                idx++;
            }
        }
        if(idx==0)
            break ; // no cycle
        for ( i = 0 ; i < nV ; i++ )
        {
            if(Idx[i]==-1) // yet not find any grp
            {
                Idx[i] = idx++;
            }
        }
        rep(i,nE)
        {
            adj[i].w -= dis[adj[i].v];
            adj[i].u = Idx[adj[i].u] ;
            adj[i].v = Idx[adj[i].v];
        }
        nV = idx++;
        root = Idx[root];
    }
    printf("%d\n",Res);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int cs, t  ;
    cin>>t;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        cin>>nV>>nE>>root ;
        int i, u, v, w ;
        adj.clear();
        rep(i,nE)
        {
            cin>>u>>v>>w;
            adj.pb(edge(u,v,w));
        }
        printf("Case %d: ",cs);
        DMST();
    }
    return 0;
}
/*sample
 
*/
 
