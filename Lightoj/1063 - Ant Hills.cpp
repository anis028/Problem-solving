#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#define db(x) printf("**%d\n",x)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define pii pair<int,int>
#define mm(x,y) memset(x,y,sizeof(x))
 
using namespace std;
int tme,low[10005],d[10005],parent[10005],root,ans;
bool visited[10005],articulation[10005];
vector<int>g[10005];
void findarticulation(int u)
{
    low[u]=d[u]=++tme;
    visited[u]=true;
    int child=0;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(parent[u]==v) continue;
        else if(visited[v]==true)
        {
            low[u]=min(low[u],d[v]);
        }
        else if(visited[v]==false)
        {
            parent[v]=u;
            findarticulation(v);
            low[u]=min(low[u],low[v]);
            if(d[u]<=low[v] && u!=root)
                if(articulation[u]==false)
                {
                    articulation[u]=true;
                    ans++;
                }
            child+=1;
        }
        if(child>1 && u==root)
            if(articulation[u]==false)
            {
                articulation[root]=true;
                ans++;
            }
    }
}
int main()
{
    int tc,p=1;
    int number,n,x,y;
    scanf("%d",&tc);
    while(tc--)
    {
        for(int i=0; i<10005; i++) g[i].clear();
        scanf("%d %d",&number,&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        mm(articulation,false);
        mm(visited,false);
        mm(parent,0);
        mm(low,0);
        mm(d,0);
        tme=0;
        root=y;
        ans=0;
        findarticulation(y);
        cout<<"Case "<<p++<<": "<<ans<<endl;
    }
    return 0;
}
