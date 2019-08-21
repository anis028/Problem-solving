#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
vector<int>path;
int last[205],vis[1009],cost[205],flag[205],t=2;
 
struct a
{
    int nex,to;
} node[2018];
 
void add(int b,int e)
{
    node[t].nex=last[b];
    node[t].to=e;
    last[b]=t++;
}
 
void dfs(int u)
{
    for(int i=last[u]; i ; i=node[i].nex)
    {
        if(vis[i>>1]) continue;
        vis[i>>1]=1;
        dfs(node[i].to);
    }
    path.pb(u);
}
 
void solve(int cas,int n)
{
    dfs(1);
    int s=path.size(),ans=0,cnt=1;
    for(int i=0; i<s; i++)
    {
        if(flag[path[i]]==0)
        {
            flag[path[i]]=1;
            ans+=(cost[path[i]]-cnt);
            cnt++;
        }
    }
    ans-=n;
    printf("Case %d: %d\n",cas,ans);
    for(int i=0; i<s; i++)
    {
        if(i)printf(" ");
        printf("%d",path[i]);
    }
    printf("\n");
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,edge,u,v;
        scanf("%d %d",&n,&edge);
        path.clear();
        memset(vis,0,sizeof vis);
        memset(last,0,sizeof last);
        memset(flag,0,sizeof flag);
        for(int i=1; i<=n; i++)
            scanf("%d",&cost[i]);
        n=edge;
        while(edge--)
        {
            scanf("%d %d",&u,&v);
            add(u,v);
            add(v,u);
        }
        t=2;
        solve(cas,n);
        cas++;
    }
    return 0;
}
/*sample
 
*/
