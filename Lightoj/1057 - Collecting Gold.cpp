#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   m0d           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
int dp[16][1<<16],n;
char grid[21][21];
pair<int,int>g[18];
 
int dist(pii a,pii b)
{
    return max(abs(a.fs-b.fs),abs(a.sc-b.sc));
}
 
int rec(int u,int mask)
{
    if(mask==((1<<n)-1)) return dist(g[u],g[0]);
    int &ret= dp[u][mask];
    if(ret!=-1) return ret;
    ret = 0x7ffffff;
    for(int i=1;i<n;i++)
        if((mask&(1<<i)) == 0) ret=min(ret, dist(g[u],g[i])+ rec(i,mask|(1<<i)));
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int ro,co;
        cin>>ro>>co;
        n=1;
        for(int i=0;i<ro;i++){
            cin>>grid[i];
            for(int j=0;j<co;j++){
                if(grid[i][j]=='x') g[0]=pii(i,j);
                else if(grid[i][j]=='g') g[n++]=pii(i,j);
            }
        }
        mm(dp,-1);
        cout<<"Case "<<cas++<<": "<<rec(0,1)<<endl;
    }
    return 0;
}
/*sample
 
*/
