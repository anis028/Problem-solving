#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
string dp[105][105],a,b;
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>a>>b;
        int l1=a.length(),l2=b.length();
        for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
            {
                if(i==0 || j==0) dp[i][j]="";
                else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+a[i-1];
                else if(dp[i-1][j].size()>dp[i][j-1].size()) dp[i][j]=dp[i-1][j];
                else if(dp[i-1][j].size()<dp[i][j-1].size()) dp[i][j]=dp[i][j-1];
                else if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i][j-1];
                else dp[i][j]=dp[i-1][j];
            }
        }
        printf("Case %d: ",cas++);
        if(dp[l1][l2].size()==0) printf(":(\n");
        else printf("%s\n",dp[l1][l2].c_str());
    }
    return 0;
}
