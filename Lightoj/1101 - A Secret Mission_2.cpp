#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
#define fs first
#define sc second
using namespace std;
 
vector<pii>g[50005];
int lev[50005],par[50005][18],val[50005][18];
 
void dfs(int u)
{
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i].fs;
        int w=g[u][i].sc;
        if(lev[v]==-1) par[v][0]= u,val[v][0]=w,lev[v]=lev[u]+1,dfs(v);
    }
}
 
struct Disjoint_set
{
    int n;
    vector<int>parent,Rank;
    Disjoint_set(int n):n(n+2),parent(n+2),Rank(n+2)
    {
        for(int i=1; i<=n; i++)
        {
            parent[i]=i;
        }
    }
    int findparent(int x)
    {
        if(parent[x]==x) return x;
        else return parent[x]=findparent(parent[x]);
    }
    int mergenodes(int x,int y)
    {
        ///if connected returns false
        int a=findparent(x);
        int b=findparent(y);
        if(a==b) return 0;
        else
        {
            if(Rank[a]>Rank[b]) parent[b]=a;
            else if(Rank[b]>Rank[a]) parent[a]=b;
            else
            {
                parent[a]=parent[b];
                Rank[b]++;
            }
            return 1;
        }
    }
};
 
struct kruskal
{
    int n;
    kruskal(int n): n(n) {}
    vector< pair<int, pair<int,int> > > edges ;
    void addedge(int x,int y,int w)
    {
        edges.pb ({w,{x,y}});
    }
    void Minst()
    {
        Disjoint_set D(n);
        int mst=0,u,v;
        sort(edges.begin(),edges.end());
        for(int i=0; i<edges.size(); i++)
        {
             u=edges[i].sc.fs;
                v=edges[i].sc.sc;
                int w=edges[i].fs;
            if(D.mergenodes(u,v))
            {
                g[u].pb({v,w});
                g[v].pb({u,w});
            }
        }
    }
};
 
int find_lca(int u,int v)
{
    int ans=0;
    if(lev[v]>lev[u]) swap(u,v);
    int l;
    for(l=1;(1<<l)<=lev[u];l++);
    l--;
 
    for(int i=l; i>=0; i--)
        if( lev[u]- (1<<i) >= lev[v])
        {
            ans=max(ans,val[u][i]);
            u=par[u][i];
        }
    if(u==v) return ans;
    for(int i=l; i>=0; i--)
        if(par[u][i]!=par[v][i]) ans=max(ans,max(val[u][i],val[v][i])),u=par[u][i],v=par[v][i];  ///<<<--- this line had the bug
 
    ans=max(ans,max(val[u][0],val[v][0]));
    return ans;
}
 
int main()
{
    int cas=1,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,edge,q,u,v,w;
        scanf("%d %d",&n,&edge);
        kruskal K(n);
        while(edge--)
        {
            cin>>u>>v>>w;
            K.addedge(u,v,w);
        }
        for(int i=0;i<=n;i++) g[i].clear();
        K.Minst();
        mm(lev,-1);
        mm(par,-1);
        mm(val,0);
 
        lev[1]=0;
        dfs(1);
 
        for(int i=1; (1<<i)<n; i++)
        {
            for(int j=1; j<=n; j++)
                if(par[j][i-1]!=-1)
                {
                    val[j][i]=max(val[j][i-1],val[par[j][i-1]][i-1]);
                    par[j][i]=par[par[j][i-1]][i-1];
 
                }
        }
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            scanf("%d %d",&u,&v);
            printf("%d\n",find_lca(u,v));
        }
    }
    return 0;
}
