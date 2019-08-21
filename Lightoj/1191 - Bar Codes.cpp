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
 
using namespace std;
 
 
long long int dp[51][51][51];
 
long long rec(int pos,int part,int m)
{
    if(pos<0||part<0) return 0;
    if(pos==0) return part==0;
 
    long long &ret=dp[pos][part][m];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=1;i<=m;i++)
        ret+=rec(pos-i,part-1,m);
    return ret;
}
 
int main()
{
    int tc,p=1,n,m,k;
    scanf("%d",&tc);
    mm(dp,-1);
    while(tc--)
    {
        scanf("%d %d %d",&n,&k,&m);
        printf("Case %d: %lld\n",p++,rec(n,k,m));
    }
    return 0;
}
/*sample
 
*/
 
