#include<bits/stdc++.h>
 
using namespace std;
vector <int>v[30005],cost[30005];
int a[30009];
bool visited[30009];
int bfs(int source,int call)
{
    int mx=0,b,node;
    a[source]=0;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        visited[u]=true;
        for(int i=0;i<v[u].size();i++)
        {
            int x=v[u][i];
            if(visited[x]==false)
            {
                q.push(x);
                int wt=cost[u][i];
                a[x]=a[u]+wt;
                if(a[x]>mx)
                {
                    mx=a[x];
                    node=x;
                }
            }
        }
        q.pop();
    }
    if(call==0)return node;
    if(call==1)return mx;
}
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            int a,b,x;
            scanf("%d %d %d",&a,&b,&x);
            v[a].push_back(b);
            v[b].push_back(a);
            cost[a].push_back(x);
            cost[b].push_back(x);
        }
        memset(visited,false,sizeof(visited));
        int z=bfs(0,0);
        memset(visited,false,sizeof(visited));
        int x=bfs(z,1);
        printf("Case %d: %d\n",p++,x);
        for(int i=0;i<n;i++){
            v[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
