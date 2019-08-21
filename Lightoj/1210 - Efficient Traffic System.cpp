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
int d[20005],low[20005],in_stack[20005],scc[20005],comp,tme;
vector<int>g[20005];
stack<int>s;
 
void find_scc(int u)
{
    d[u]=low[u]=++tme;
    in_stack[u]=1;
    s.push(u);
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(in_stack[v]==1) low[u]=min(low[u],d[v]);
        else if(d[v]==-1)
        {
            find_scc(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==d[u])
    {
        comp++;
        while(1)
        {
            int x=s.top();
            scc[x]=comp;
            in_stack[x]=0;
            s.pop();
            if(x==u) break;
        }
    }
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int cities,roads,u,v;
        scanf("%d %d",&cities,&roads);
        if(roads==0)
        {
            printf("Case %d: %d\n",p++,cities);
            continue;
        }
        for(int i=0; i<=20005; i++)
        {
            g[i].clear();
            d[i]=-1;
            low[i]=0;
        }
        for(int i=0; i<roads; i++)
        {
            scanf("%d %d",&u,&v);
            g[u].pb(v);
        }
        tme=0;
        comp=0;
        for(int i=1; i<=cities; i++) if(d[i]==-1) find_scc(i);
        if(comp==1)
        {
            printf("Case %d: 0\n",p++);
            continue;
        }
        int in[comp+5],out[comp+5];
        mm(in,0);
        mm(out,0);
        for(int i=1; i<=cities; i++)
        {
            for(int j=0; j<g[i].size(); j++)
            {
                if(scc[i]!=scc[g[i][j]])
                {
                    in[scc[g[i][j]]]++;
                    out[scc[i]]++;
                }
            }
        }
        int a=0,b=0;
        for(int i=1; i<=comp; i++)
        {
            if(in[i]==0)a++;
            if(out[i]==0)b++;
        }
        printf("Case %d: %d\n",p++,max(a,b));
    }
    return 0;
}
