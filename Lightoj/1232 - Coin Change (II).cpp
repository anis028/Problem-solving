#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        int a[n+1],dp[k+7];
        for(int i=0;i<=k;i++)dp[i]=0;
        dp[0]=1;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            for(int j=1;j<=k;j++)
                if(j-a[i]>=0) dp[j]=(dp[j]+dp[j-a[i]])%100000007;
        printf("Case %d: %d\n",p++,dp[k]);
    }
    return 0;
}
