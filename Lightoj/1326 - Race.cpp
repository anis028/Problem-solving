#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   md            10056
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
 
using namespace std;
int ncr[1005][1005],dp[1005];
int main()
{
    int tc,p=1,n;
 
    for(int i=1;i<1005;i++) {ncr[i][1]=i;ncr[i][i]=1;}
    for(int i=2;i<1005;i++)
        for(int j=2;j<i;j++) ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%md;
 
    dp[0]=dp[1]=1;
    for(int i=2;i<1005;i++)
        for(int j=1;j<=i;j++)
            dp[i]=(dp[i]+(dp[i-j]*ncr[i][j])%md)%md;
 
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",p++,dp[n]);
    }
    return 0;
}
/*sample
 
*/
