#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   m0d           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   lim           1000000000
using namespace std;
 
int red[105],blue[105],l[105],r[105],vis[105];
vector<int> g[105];
 
bool kuhn(int u)
{
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]) continue;
        vis[v]=1;
        if(r[v]==-1 || kuhn(r[v])){
            r[v]=u;
            l[u]=v;
            return true;
        }
    }
    return false;
}
 
int main()
{
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n;
        for(int i=0;i<n;i++) cin>>red[i];
        cin>>m;
        for(int i=0;i<m;i++) cin>>blue[i];
        for(int i=0;i<105;i++) g[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(blue[j]%red[i]==0) g[i].pb(j);
        mm(l,-1);
        mm(r,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            mm(vis,0);
            if(kuhn(i)) ans++;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
/*sample
 
*/
