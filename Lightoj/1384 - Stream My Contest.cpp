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
const int Maxn = 65 ; // Highest Vertex
struct edge
{
    int u, v, w, band ;
    edge() {}
    edge(int _u, int _v, int _w, int _band )
    {
        u = _u, v = _v, w = _w , band = _band;
    }
};
int nV, nE, root, allowence ;   // nV = number of vertex , nE = number of edge , root is root
int vis[Maxn], parnt[Maxn] ;  // vis[] will store from which cycle it belogs , pre[] store its parnt
int Idx[Maxn] ; // will store new indxing Id
int dis[Maxn] ; // store the lowest incoming edge of a root
vector < edge > adj, g ;
int DMST()
{
    int Res  = 0, i, u,  v, w  ;
    while(1)
    {
        int i  ;
        for ( i = 0 ; i < nV ; i++ )
        {
            dis[i] = 1e9 ;
            vis[i] = -1 ;
            Idx[i] = -1 ;
        }
        for ( i = 0 ; i < nE ; i++ )
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
        for ( i = 0 ; i < nV ; i++ )
        {
            if ( dis[i] == 1e9 ) return 2000000000;
            Res += dis[i];
        }
        int idx = 0 ;
        // cycle detection
        for ( i = 0 ; i < nV ; i++ )
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
        for ( i = 0 ; i < nE ; i++ )
        {
            adj[i].w -= dis[adj[i].v];
            adj[i].u = Idx[adj[i].u] ;
            adj[i].v = Idx[adj[i].v];
        }
        nV = idx++;
        root = Idx[root];
    }
    return Res;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        g.clear();
        int e,w,u,v,z,n;
        cin>> n>> e>> allowence;
        for(int i=0;i<e;i++){
            cin>>u>>v>>z>>w;
            g.pb(edge(u,v,w,z));
        }
        int l=0,r=1000007,ans=-1,mid;
        while(l<=r)
        {
            nE=0,nV=n,root=0;
            adj.clear();
            mid=(l+r)>>1;
//            cout<<mid<< "--> "<<endl;
            for(int i=0;i<e;i++)
                if(g[i].band>=mid){
//                    cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<" "<<g[i].band<<endl;
                    adj.pb(g[i]),nE++;
                }
            int cost= DMST();
//            cout<<cost<<endl;
            if(cost<=allowence)
                ans=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<"Case "<<cas++<<": ";
        if(ans==-1) cout<<"impossible"<<endl;
        else cout<<ans<<" kbps"<<endl;
    }
    return 0;
}
/*sample
 
*/
