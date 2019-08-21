#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
int n,ara[205],m,d;
long long dp[205][25][25];
 
long long rec(int pos,int nisi,int mod)
{
    if(mod<0) mod+=d; // for negative number
    if(pos>n) return 0;
    if(nisi==m) return mod==0;
    long long &ret=dp[pos][nisi][mod];
    if(ret!=-1) return  ret;
    ret=0;
    ret+=rec(pos+1,nisi,mod);
    ret+=rec(pos+1,nisi+1,(mod+ara[pos])%d);
    return ret;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++) scanf("%d",&ara[i]);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            memset(dp,-1,sizeof dp);
            scanf("%d %d",&d,&m);
            printf("%lld\n",rec(0,0,0));
        }
    }
    return 0;
}
/*sample
 
*/
 
