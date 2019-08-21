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
 
ll cost[20][20],dp[(1<<16)+2],cnt[20];
int m,n,vis[(1<<16)+2],cas=1;
 
ll rec(int mask)
{
    if(mask==(1<<m)-1) return 0;
    ll &ret=dp[mask];
    if(vis[mask]==cas) return ret;
    vis[mask]=cas;
    ret=1e15;
    for(int i=0;i<m;i++){
        if(mask&(1<<i)) continue;
        int tmp=0;
        for(int j=0;j<m;j++) if(mask&(1<<j)) tmp+=cost[i][j];
        ret=min(ret,tmp+rec(mask|(1<<i)));
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        mm(cnt,0);
        mm(cost,0);
        int x;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>x;
            x--;
            cnt[x]++;
            for(int j=0;j<m;j++){
                if(j==x) continue;
                cost[x][j]+=cnt[j];
            }
        }
        cout<<"Case "<<cas++<<": "<<rec(0)<<endl;
    }
    return 0;
}
/*sample
 
*/
 
