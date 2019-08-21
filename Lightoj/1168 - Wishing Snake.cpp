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
        int cities,roads,u,v,n;
        scanf("%d",&n);
        for(int i=0; i<=20005; i++)
        {
            g[i].clear();
            d[i]=-1;
            low[i]=0;
        }
        while(n--)
        {
            scanf("%d",&roads);
            for(int i=0; i<roads; i++)
            {
                scanf("%d %d",&u,&v);
                g[u].pb(v);
            }
        }
        tme=0;
        comp=0;
        find_scc(0);
        int con=0;
        for(int i=1; i<1000; i++)
            if(d[i]==-1 and g[i].size())
            {
                printf("Case %d: NO\n",p++);
                con=1;
                break;
            }
        if(con) continue;
        if(comp==1)
        {
            printf("Case %d: YES\n",p++);
            continue;
        }
        int in[comp+5],out[comp+5];
        mm(in,0);
        mm(out,0);
        for(int i=0; i<1000; i++)
        {
            if(!scc[i]) continue;
            for(int j=0; j<g[i].size(); j++)
            {
                if(scc[i]!=scc[g[i][j]])
                {
                    in[scc[g[i][j]]]++;
                    out[scc[i]]++;
                }
            }
        }
        int a=0,b=0,ans=0;
        for(int i=1; i<=comp; i++)
        {
            if(in[i]!=1)ans++;
            if(out[i]!=1)ans++;
        }
        printf("Case %d: ",p++);
        if(ans<3) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
