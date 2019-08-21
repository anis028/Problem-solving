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
 
int n,grid[205][205],dp[205][205],mx;
int rec(int r,int c)
{
    if(grid[r][c]==-1) return 0;
    if(dp[r][c]!=-1) return dp[r][c];
    else
    {
        dp[r][c]=grid[r][c]+max(rec(r+1,c+1),rec(r+1,c));
        if(dp[r][c]>mx)mx=dp[r][c];
        return dp[r][c];
    }
}
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        mm(grid,-1);
        mm(dp,-1);
        loop(i,0,2*n-1)
        {
            if(i<n)loop(j,0,i+1) scanf("%d",&grid[i][j]);
            else loop(j,i-n+1,n) scanf("%d",&grid[i][j]);
        }
        mx=0;
        rec(0,0);
        cout<<"Case "<<p++<<": "<<mx<<endl;
    }
    return 0;
}
