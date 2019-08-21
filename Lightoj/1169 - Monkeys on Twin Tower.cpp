#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        int dp[4][n+2];
        for(int i=0;i<n;i++) scanf("%d",&dp[1][i]);
        for(int i=0;i<n;i++) scanf("%d",&dp[2][i]);
        for(int i=1;i<n;i++) scanf("%d",&dp[3][i]);
        for(int i=1;i<n;i++) scanf("%d",&dp[0][i]);
        for(int i=n-2;i>-1;i--)
        {
            dp[1][i]+=min(dp[1][i+1],dp[2][i+1]+dp[3][i+1]);
            dp[2][i]+=min(dp[2][i+1],dp[1][i+1]+dp[0][i+1]);
        }
        printf("Case %d: %d\n",cas++,min(dp[1][0],dp[2][0]));
    }
    return 0;
}
/*sample
 
*/
