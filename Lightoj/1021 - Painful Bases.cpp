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
#define   dig(p) ((p<65)?p-48:p-55)
 
 
using namespace std;
 
string s;
int b,k,n;
long long dp[22][(1<<16)+2];
 
long long rec(int m,int mask)
{
    if(mask==(1<<n)-1) return m==0;
    long long &ret= dp[m][mask];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i)) continue;
        ret+=rec((m*b+dig(s[i]))%k,mask|(1<<i));
    }
    return ret;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&b,&k);
        cin>>s;
        n=s.length();
        memset(dp,-1,sizeof dp);
        printf("Case %d: %lld\n",cas++,rec(0,0));
    }
    return 0;
}
/*sample
 
*/
