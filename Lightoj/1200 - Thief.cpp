#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int price[102],weight[102],dp[10002];
 
int solve(int n,int cap)
{
    dp[0]=0;
    for(int i=1;i<=cap;i++)
    {
        dp[i]=dp[i-1];
        for(int j=0;j<n;j++)
            if(i>=weight[j])
                dp[i]=max(dp[i],dp[i-weight[j]]+price[j]);
    }
    return dp[cap];
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int w,n,x;
        scanf("%d %d",&n,&w);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&price[i],&x,&weight[i]);
            w-=(weight[i]*x);
        }
        printf("Case %d: ",cas++);
        if(w<0) printf("Impossible\n");
        else if(!w) printf("0\n");
        else printf("%d\n",solve(n,w));
    }
    return 0;
}
/*sample
 
*/
