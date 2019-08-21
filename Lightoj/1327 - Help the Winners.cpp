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
 
int grid[15][15],n;
ll dp[(1<<15)+2][2][2];
 
ll rec(int pos,int mask,int super,int zero)
{
    if(mask==(1<<n)-1){
        if(zero) return super;
        return 1;
    }
 
    ll &ret=dp[mask][super][zero];
    if(ret!=-1) return ret;
 
    ret=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        if(grid[pos][i]==0) ret+=rec(pos+1,mask|(1<<i),super,1);
        if(grid[pos][i]==1) ret+=rec(pos+1,mask|(1<<i),super,zero);
        if(grid[pos][i]==2) ret+=rec(pos+1,mask|(1<<i),1,zero);
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) cin>>grid[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==2) {swap(grid[0],grid[i]);break;}
        mm(dp,-1);
        cout<<"Case "<<cas++<<": "<<rec(0,0,0,0)<<endl;
    }
    return 0;
}
/*sample
 
*/
