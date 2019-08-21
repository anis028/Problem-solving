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
#define   fs            first
#define   sc            second
 
///ios_base::sync_with_stdio(false)
 
using namespace std;
 
vector<pii>g[505];
int ans[505];
 
void dfs(int u,int cost)
{
    ans[u]=cost;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].fs;
        if(ans[v]==-1)
            dfs(v,max(cost,g[u][i].sc));
    }
}
 
struct Disjoint_set
{
    int n;
    vector<int>parent,Rank;
    Disjoint_set(int n):n(n+2),parent(n+2),Rank(n+2)
    {
        for(int i=0; i<=n; i++)
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
                parent[a]=b;
                Rank[b]++;
            }
            return 1;
        }
    }
};
 
struct kruskal
{
    int n;
    kruskal(int n): n(n){}
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
            if(D.mergenodes(edges[i].sc.fs,edges[i].sc.sc))
            {
                u=edges[i].sc.fs;
                v=edges[i].sc.sc;
                g[u].pb({v,edges[i].fs});
                g[v].pb({u,edges[i].fs});
            }
        }
    }
};
 
int main()
{
    int cas=1,t;
    cin>>t;
    while(t--)
    {
        int n,q,t;
        cin>>n>>q;
        kruskal K(n);
        while(q--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            K.addedge(u,v,w);
        }
        for(int i=0;i<505;i++) g[i].clear();
        K.Minst();
        cin>>t;
        mm(ans,-1);
        dfs(t,0);
        printf("Case %d:\n",cas++);
        for(int i=0;i<n;i++)
            if(ans[i]==-1) printf("Impossible\n");
        else printf("%d\n",ans[i]);
    }
    return 0;
}
