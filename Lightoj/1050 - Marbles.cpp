#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
double dp[505][505];
 
double rec(int r,int b)
{
    if(r==0) return dp[r][b]=1.0;
    if(b==0) return dp[r][b]=0.0;
    double &ret=dp[r][b];
    if(ret>=0.0) return ret;
    ret=0.0;
    ret+=(1.0*r)/(r+b)*rec(r-1,b-1);
    if(b>1) ret+=(1.0*b)/(r+b)*rec(r,b-2);
    return ret;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    for(int i=0;i<=502;i++)
        for(int j=0;j<=502;j++) dp[i][j]=-1.0;
    while(tc--)
    {
        int r,b;
        scanf("%d %d",&r,&b);
        printf("Case %d: %.10f\n",cas++,rec(r,b));
    }
    return 0;
}
/*sample
 
*/
