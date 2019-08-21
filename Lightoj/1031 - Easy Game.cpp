#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int a[105],dp[105][105];
 
int solve(int i,int j)
{
    if(i>j) return 0;
    int &ret=dp[i][j];
    if(ret!=-1) return ret;
    ret=-100000000;
    int p=0;
    for(int k=i;k<=j;k++)
    {
        p+=a[k];
        ret=max(ret,p-solve(k+1,j));
    }
    p=0;
    for(int k=j;k>=i;k--)
    {
        p+=a[k];
        ret=max(ret,p-solve(i,k-1));
    }
    return ret;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        mm(dp,-1);
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        printf("Case %d: %d\n",cas++,solve(0,n-1));
    }
    return 0;
}
/*sample
 
*/
