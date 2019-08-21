#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int dis1[30005],dis2[30005];
vector<int>g[30005],cost[300005];
 
int bfs(int u)
{
    queue<int>q;
    q.push(u);
    dis1[u]=0;
    int dis=-1,node=-1,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(dis1[u]>dis)
        {
            dis=dis1[u];
            node=u;
        }
        for(int i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(dis1[v]==-1)
            {
                q.push(v);
                dis1[v]=dis1[u]+cost[u][i];
            }
        }
    }
    return node;
}
void Bfs(int u)
{
    queue<int>q;
    q.push(u);
    dis2[u]=0;
    int dis=-1,node=-1,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
 
        for(int i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(dis2[v]==-1)
            {
                q.push(v);
                dis2[v]=dis2[u]+cost[u][i];
            }
        }
    }
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
 
        int n,x,y,w;
        scanf("%d",&n);
        for(int i=0;i<n+2;i++) cost[i].clear(),g[i].clear(),dis1[i]=-1,dis2[i]=-1;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            g[x].pb(y);
            g[y].pb(x);
            cost[x].pb(w);
            cost[y].pb(w);
        }
        int node=bfs(0);
        for(int i=0;i<n+2;i++) dis1[i]=-1;
        node=bfs(node);
        Bfs(node);
        printf("Case %d:\n",cas++);
        for(int i=0;i<n;i++) printf("%d\n",max(dis1[i],dis2[i]));
    }
    return 0;
}
/*sample
 
*/
