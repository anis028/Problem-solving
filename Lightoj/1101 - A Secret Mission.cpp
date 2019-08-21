#include<bits/stdc++.h>
 
#define pb push_back
#define Pb pop_back
 
#define pii pair<int,int>
#define ppi pair<pii,int>
 
#define fs first
#define sc second
 
using namespace std;
 
#define md 50005
int rep[md],depth[md];
vector<pii>gr[md];
int tab[md][16],dis[md][16];
int k;
int Find(int x)
{
    if(rep[x]==x) return x;
    else return rep[x]=Find(rep[x]);
}
void dfs(int u,int d)
{
    depth[u]=d;
    k=max(k,d);
    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i].fs;
        int w=gr[u][i].sc;
        if(depth[v]==-1)
        {
            tab[v][0]=u;
            dis[v][0]=w;
            dfs(v,d+1);
        }
    }
    return;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        k=-1;
        scanf("%d %d",&n,&m);
        vector<pair<int,pair<int,int> > >ed(m);
        for(int i=0; i<m; i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            ed[i]= {z,pii(x,y)};
        }
        sort(ed.begin(),ed.end());
        for(int i=1; i<=n; i++)
        {
            gr[i].clear();
            rep[i]=i;
        }
        int cnt=0;
        for(int i=0; i<m && cnt<n-1; i++)
        {
            int x=ed[i].sc.fs,y=ed[i].sc.sc,w=ed[i].fs;
            int a=Find(x);
            int b=Find(y);
            if(a!=b)
            {
                rep[a]=rep[b];
                gr[x].pb(pii(y,w));
                gr[y].pb(pii(x,w));
                cnt++;
            }
        }
        dis[1][0]=0;
        tab[1][0]=-1;
        for(int i=1; i<=n; i++)depth[i]=-1;
        dfs(1,0);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; (1<<j) <= k; j++)
            {
                tab[i][j]=-1;
                dis[i][j]=0;
            }
        }
        for(int i=1; (1<<i) <= k; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(tab[j][i-1]!=-1)
                {
                    dis[j][i]=max(dis[j][i-1],dis[tab[j][i-1]][i-1]);
                    tab[j][i]=tab[tab[j][i-1]][i-1];
                }
            }
        }
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            int x,y,mx=0;
            scanf("%d %d",&x,&y);
            if(depth[y]>depth[x]) swap(x,y);
            int lg;
            for(lg=1; (1<<lg) <= depth[x]; lg++);
            lg--;
            for(int i=lg; i>=0; i--)
            {
                if((depth[x] - (1<<i) ) >= depth[y])
                {
                    mx=max(mx,dis[x][i]);
                    x=tab[x][i];
                }
            }
            if(x==y)
            {
                printf("%d\n",mx);
                continue;
            }
            for(int i=lg; i>=0; i--)
            {
                if(tab[x][i]!=-1 && tab[x][i]!=tab[y][i])
                {
                    mx=max(mx,max(dis[x][i],dis[y][i]));
                    x=tab[x][i];
                    y=tab[y][i];
                }
            }
            mx=max(mx,max(dis[x][0],dis[y][0]));
            printf("%d\n",mx);
        }
    }
    return 0;
}
