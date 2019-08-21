#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
priority_queue<pii,vector<pii>, greater<pii> >q;
int dis1[10005],dis2[10005];
vector<pii>g[10005],gg[10005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int n,r,u,v,w,s,f,p;
        for(int i=0;i<10005;i++) dis2[i]=dis1[i]=1e9,g[i].clear(),gg[i].clear();
        while(!q.empty()) q.pop();
        cin>>n>>r>>s>>f>>p;
        while(r--){
            cin>>u>>v>>w;
            g[u].pb({w,v});
            gg[v].pb({w,u});
        }
        dis1[s]=0;
        q.push({0,s});
        while(!q.empty()){
            u=q.top().sc;
            for(int i=0;i<g[u].size();i++){
                v=g[u][i].sc;
                w=g[u][i].fs;
                if(dis1[v]>dis1[u]+w){
                    dis1[v]=w+dis1[u];
                    q.push({dis1[v],v});
                }
            }
            q.pop();
        }
        dis2[f]=0;
        q.push({0,f});
        while(!q.empty()){
            u=q.top().sc;
            for(int i=0;i<gg[u].size();i++){
                v=gg[u][i].sc;
                w=gg[u][i].fs;
                if(dis2[v]>dis2[u]+w){
                    dis2[v]=w+dis2[u];
                    q.push({dis2[v],v});
                }
            }
            q.pop();
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<g[i].size();j++)
            {
                if(dis1[i]+dis2[g[i][j].sc]+g[i][j].fs<=p)
                    ans=max(ans,g[i][j].fs);
            }
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
