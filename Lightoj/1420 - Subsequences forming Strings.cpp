#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define   mod           1000000007
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
int dp[101][101][101][3],vis[101][101][101][3],cas=1;
string a,b,c;
 
int rec(int x,int y,int z,int call)
{
    if(z==c.length()) return 1;
    if(x==a.length() and y==b.length()) return 0;
    int &ret=dp[x][y][z][call];
    if(vis[x][y][z][call]==cas) return ret;
    vis[x][y][z][call]=cas;
 
    ret=0;
    if(x<a.length() and call!=2){
        if(a[x]==c[z]) ret=(ret+rec(x+1,y,z+1,0))%mod;
        ret=(ret+rec(x+1,y,z,1))%mod;
    }
    if(y<b.length() and call!=1){
        if(b[y]==c[z]) ret=(ret+rec(x,y+1,z+1,0))%mod;
        ret=(ret+rec(x,y+1,z,2))%mod;
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        cin>>a>>b>>c;
        cout<<"Case "<<cas++<<": "<<rec(0,0,0,0)<<endl;
    }
    return 0;
}
/*sample
 
*/
 
