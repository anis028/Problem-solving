#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
using namespace std;
typedef long long ll;
typedef double dbl;
 
dbl dp[15][(1<<15)];
int vis[15][1<<15],cas=1,n,m,cost[15][15];
 
int dfs(int u,int mask)
{
    if(mask==(1<<n)-1){
        dp[u][mask]=0;
        return 1;
    }
    dbl &ret=dp[u][mask];
    if(vis[u][mask]==cas) return ret > 1e-8;
    vis[u][mask]=cas;
    int cnt=0;
    ret=5;
    for(int i=1;i<n;i++){
        if(mask&(1<<i)) continue;
        if(cost[u][i] and dfs(i,mask|(1<<i))){
            int temp=mask|(1<<i);
            cnt++;
            dp[u][mask]+=(1.0*cost[u][i])+dp[i][temp];
        }
    }
    if(cnt){
        dp[u][mask]/=cnt;
        return 1;
    }
    dp[u][mask]=0;
    return 0;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        int u,v,w;
        cin>>n>>m;
        mm(cost,0);
        while(m--){
            cin>>u>>v>>w;
            cost[u][v]=cost[v][u]=w;
        }
        dfs(0,1);
        cout<<"Case "<<cas++<<": "<<fixed<<setprecision(12)<<dp[0][1]<<endl;
    }
 
    return 0;
}
/*sample
 
*/
