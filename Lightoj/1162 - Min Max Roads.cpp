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
 
using namespace std;
 
vector<pii>g[100005];
int par[100005][20],lvl[100005],mn[100005][20],mx[100005][20],n;
 
void init()
{
    mm(lvl,-1);
    mm(mn,-1);
    mm(mx,-1);
    lvl[1]=0;
    mx[1][0]=0;
    mn[1][0]=100009;
    for(int i=0;i<100005;i++)
        g[i].clear();
}
 
void DFS(int u)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].fs;
        int w=g[u][i].sc;
        if(lvl[v]==-1)
        {
            par[v][0]=u;
            lvl[v]=lvl[u]+1;
            mn[v][0]=w;
            mx[v][0]=w;
            DFS(v);
        }
    }
}
 
void make_table()
{
    for(int j=1;(1<<j)<n;j++)
    {
        for(int i=0;i<=n;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
                mn[i][j]=min(mn[i][j-1],mn[par[i][j-1]][j-1]);
                mx[i][j]=max(mx[i][j-1],mx[par[i][j-1]][j-1]);
            }
        }
    }
}
 
pii find_lca(int u, int v)
{
    pii ans=make_pair(100009,0);
    if(lvl[v]<lvl[u]) swap(u,v);
 
    int l=log2(lvl[v]);
    for(int i=l;i>=0;i--)
    {
        if(lvl[v]-(1<<i)>=lvl[u])
        {
            ans.fs=min(ans.fs,mn[v][i]);
            ans.sc=max(ans.sc,mx[v][i]);
            v=par[v][i];
        }
    }
    if(u==v) return ans;
    l=log2(lvl[v]);
    for(int i=l;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            ans.fs=min(ans.fs,min(mn[u][i],mn[v][i]));
            ans.sc=max(ans.sc,max(mx[u][i],mx[v][i]));
            v=par[v][i];
            u=par[u][i];
        }
    }
    ans.fs=min(ans.fs,min(mn[u][0],mn[v][0]));
    ans.sc=max(ans.sc,max(mx[u][0],mx[v][0]));
    return ans;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        init();
        int u,v,w;
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            g[u].pb({v,w});
            g[v].pb({u,w});
        }      
        DFS(1);
        make_table();
        printf("Case %d:\n",cas++);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&u,&v);
            pii a=find_lca(u,v);
            printf("%d %d\n",a.fs,a.sc);
        }
    }
    return 0;
}
/*sample
   
*/
