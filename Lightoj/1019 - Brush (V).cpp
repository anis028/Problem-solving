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
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        priority_queue<pii,vector<pii>, greater<pii> >q;
        int n,r,u,v,w,cost[105];
        vector<pii>g[105];
        for(int i=0;i<105;i++) cost[i]=1e7,g[i].clear();
        while(!q.empty()) q.pop();
        cin>>n>>r;
        while(r--){
            cin>>u>>v>>w;
            g[u].pb({w,v});
            g[v].pb({w,u});
        }
        cost[1]=0;
        q.push({0,1});
        while(!q.empty()){
            u=q.top().sc;
            for(int i=0;i<g[u].size();i++){
                v=g[u][i].sc;
                w=g[u][i].fs;
                if(cost[v]>cost[u]+w){
                    cost[v]=w+cost[u];
                    q.push({cost[v],v});
                }
            }
            q.pop();
        }
        cout<<"Case "<<cas++<<": ";
        if(cost[n]==1e7) cout<<"Impossible"<<endl;
        else cout<<cost[n]<<endl;
    }
    return 0;
}
/*sample
 
*/
