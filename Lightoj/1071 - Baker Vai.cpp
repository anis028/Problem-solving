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
 
int dp[102][102][102],grid[102][102],ro,co;
 
int rec(int r1,int c1,int r2,int c2)
{
    if(r1>=ro||r2>=ro||c1>=co||c2>=co||(r1==r2&&c1==c2))
        return 0;
    int &ret= dp[r1][c1][r2];
    if(ret!=-1) return ret;
    ret=0;
    ret=max(ret,rec(r1+1,c1,r2+1,c2));
    ret=max(ret,rec(r1+1,c1,r2,c2+1));
    ret=max(ret,rec(r1,c1+1,r2+1,c2));
    ret=max(ret,rec(r1,c1+1,r2,c2+1));
    return ret += (grid[r1][c1] + grid[r2][c2]) ;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&ro,&co);
        for(int i=0;i<ro;i++)
            for(int j=0;j<co;j++) scanf("%d",&grid[i][j]);
        mm(dp,-1);
        printf("Case %d: %d\n",cas++,grid[0][0]+rec(0,1,1,0)+grid[ro-1][co-1]);
    }
    return 0;
}
/*sample
 
*/
