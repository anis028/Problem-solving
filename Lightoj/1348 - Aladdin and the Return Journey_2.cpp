#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   N             30005
 
 
using namespace std;
 
int n,par[N],lev[N],chainhead[N],chainind[N],serial[N],ara[N],val[N],tree[4*N],subsize[N],chain,pos;
 
vector<int>g[N];
 
void init(int n)
{
    for(int i=1;i<=n+1;i++)
    {
        lev[i]=-1;
        g[i].clear();
        chainhead[i]=-1;
        subsize[i]=0;
    }
}
 
void dfs(int u,int p)
{
    subsize[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=p)
            if(lev[v]==-1){
                lev[v]=lev[u]+1;
                par[v]=u;
                dfs(v,u);
                subsize[u]+=subsize[v];
            }
    }
}
 
void hld(int u,int p)
{
    if(chainhead[chain]==-1) chainhead[chain]=u;
    pos++;
    chainind[u]=chain;
    serial[u]=pos;
    ara[pos]=val[u];
 
    int sc=-1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=p)
            if(sc==-1 || subsize[v]>subsize[sc]) sc=v;
    }
    if(sc!=-1) hld(sc,u);
 
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=p and v!=sc){
            chain++;
            hld(v,u);
        }
    }
}
 
void build(int node,int s,int f)
{
    if(s==f)
    {
        tree[node]=ara[s];
        return ;
    }
    int mid=(s+f)>>1,lc=node<<1,rc=lc+1;
    build(lc,s,mid);
    build(rc,mid+1,f);
    tree[node]=tree[lc]+tree[rc];
}
 
void update(int node,int s,int f,int in,int val)
{
    if(s>in || f<in) return;
    if(s==f)
    {
        ara[s]=val;
        tree[node]=val;
        return;
    }
    int mid=(s+f)>>1,lc=node<<1,rc=lc+1;
    update(lc,s,mid,in,val);
    update(rc,mid+1,f,in,val);
    tree[node]=tree[lc]+tree[rc];
}
 
int query(int node,int s,int f,int i,int j)
{
    if(s>j || f<i) return 0;
    if(s>=i and f<=j) return tree[node];
    int mid=(s+f)>>1,lc=node<<1,rc=lc+1;
    int x= query(lc,s,mid,i,j);
    int y= query(rc,mid+1,f,i,j);
    return x+y;
}
 
int query_up(int u,int v)
{
    int ans=0,uchain=chainind[u],vchain=chainind[v];
 
    if(uchain<vchain) swap(u,v);
    uchain=chainind[u],vchain=chainind[v];
 
    while(uchain>vchain)
    {
        //cout<<uchain<<" u "<<vchain<<endl;
        ans+=query(1,1,n,serial[chainhead[uchain]],serial[u]);
        u=chainhead[uchain];
        u=par[u];
        uchain=chainind[u];
    }
    while(uchain!=vchain)
    {
        //cout<<uchain<<" v "<<vchain<<endl;
        ans+=query(1,1,n,serial[chainhead[vchain]],serial[v]);
        v=chainhead[vchain];
        v=par[v];
        vchain=chainind[v];
    }
    int x=serial[v],y=serial[u];
    if(x>y) swap(x,y);
    ans+=query(1,1,n,x,y);
    return ans;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int u,v,x;
        scanf("%d",&n);
        init(n);
        for(int i=1;i<=n;i++) scanf("%d",&val[i]);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d",&u,&v);
            u++,v++;
            g[u].pb(v);
            g[v].pb(u);
        }
        par[1]=-1;
        lev[1]=0;
        dfs(1,-1);
        pos=0;
        chain=1;
        hld(1,-1);
        build(1,1,n);
//        for(int i=1;i<5;i++) printf("%d ",ara[i]);
//        cout<<endl;
//        for(int i=1;i<8;i++) printf("%d ",tree[i]);
//        cout<<endl;
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            scanf("%d %d %d",&x,&u,&v);
            if(x)
                update(1,1,n,serial[u+1],v);
            else printf("%d\n",query_up(u+1,v+1));
        }
    }
    return 0;
}
/*sample
1
 
4
10 20 30 40
0 1
1 2
1 3
3
0 2 3
1 1 100
0 2 3
 
 
*/
