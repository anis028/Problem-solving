#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
#define   fs            first
#define   sc            second
 
using namespace std;
 
int n,m;
long long dp[(1<<15)+2],cost[16][16];
 
long long rec(int mask)
{
    if(mask==0) return 0;
    long long &ret=dp[mask];
    if(ret!=-1) return ret;
    ret=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
        {
            for(int j=i+1;j<n;j++)
                if(mask&(1<<j))
                    ret=min( ret, cost[i][j] + rec(mask & ((~(1<<i)) & (~(1<<j)))));
            break;
        }
    }
    return ret;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        long long sum=0,u,v,w,flag=0;
        scanf("%d %d",&n,&m);
 
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cost[i][j]=INT_MAX;
 
        while(m--)
        {
            scanf("%lld %lld %lld",&u,&v,&w);
            sum+=w;
            u--,v--;
            cost[u][v]=min(cost[u][v],w);
            cost[v][u]=min(cost[v][u],w);
            flag^=1<<u;
            flag^=1<<v;
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(cost[i][j]-cost[k][j]>cost[i][k])cost[i][j]=cost[i][k]+cost[k][j];
 
        memset(dp,-1,sizeof dp);
        sum+=rec(flag);
 
        printf("Case %d: %lld\n",cas++,sum);
    }
    return 0;
}
/*sample
 
*/
