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
#define   inf           1<<30
#define   ppi          pair<int,pair<int,int> >
using namespace std;
 
vector<pii>g[5007];
int n;
 
int dijkstra1(int source,int des)
{
    int dist[4][n+5];
    for(int i=0;i<n+3;i++){
        dist[1][i]=inf;
        dist[2][i]=inf;
    }
    dist[1][source]=0;
    priority_queue<ppi,vector<ppi>,greater<ppi> >q;
    q.push({1,{0,source}});
    while(!q.empty())
    {
        int t=q.top().first;
        int u=q.top().second.second;
        q.pop();
        if(t==2 and u==des) break;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].second;
            int cost=dist[t][u]+g[u][i].first;
            //cout<<v<<" "<<t<<" "<<cost<<endl;
            if(cost<dist[1][v])
            {
                dist[2][v]=dist[1][v];
                q.push({2,{dist[2][v],v}});
 
                dist[1][v]=cost;
                q.push({1,{dist[1][v],v}});
            }
            else if(cost>dist[1][v] and cost<dist[2][v])
            {
                dist[2][v]=cost;
                q.push({2,{dist[2][v],v}});
            }
        }
    }
    return dist[2][des];
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int node,edge,x,y,z;
        scanf("%d %d",&n,&edge);
        for(int i=0;i<=5003;i++)g[i].clear();
        while(edge--)
        {
            scanf("%d %d %d",&x,&y,&z);
            g[x].pb({z,y});
            g[y].pb({z,x});
        }
        printf("Case %d: %d\n",p++,dijkstra1(1,n));
    }
    return 0;
}
/*sample
 
*/
 
