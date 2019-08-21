#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int dp[55][55][55];
 
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        string a,b,c;
        cin>>a>>b>>c;
        int x=a.length(),y=b.length(),z=c.length();
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                for(int k=0;k<=z;k++)
                {
                    if(i==0||j==0||k==0) dp[i][j][k]=0;
                    else if(a[i-1]==b[j-1] and b[j-1]==c[k-1]) dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    else dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],max(dp[i][j][k-1],max(dp[i-1][j-1][k],max(dp[i-1][j][k-1],dp[i][j-1][k-1])))));
                }
            }
        }
        printf("Case %d: %d\n",cas++,dp[x][y][z]);
    }
    return 0;
}
/*sample
 
*/
