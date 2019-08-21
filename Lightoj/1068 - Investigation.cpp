#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
vector<int> v;
int k;
int dp[12][85][85];
 
int solve(int pos,int tight,int mod,int sum,int nisi)
{
    if(pos<0) return (mod==0 and sum==0 and nisi==0);
    if(dp[pos][mod][sum]!=-1 and tight==0 and nisi==0)
        return dp[pos][mod][sum];
    int ret=0;
    int lim=tight?v[pos]:9;
    for(int i=0;i<=lim;i++)
    {
        //cout<<pos<<" "<<i<<endl;
        ret+=solve(pos-1,tight&&i==lim,((mod*10)+i)%k,(sum+i)%k,nisi and i==0);
    }
    if(!tight and nisi==0) dp[pos][mod][sum]=ret;
    return ret;
}
 
int go(int n)
{
    if(n<1 || k>82) return 0;
    v.clear();
    while(n) v.pb(n%10),n/=10;
    return solve(v.size()-1,1,0,0,1);
}
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(dp,-1,sizeof dp);
        int n,m;
        scanf("%d %d %d",&n,&m,&k);
        if(n>m) swap(n,m);
        printf("Case %d: %d\n",cas++,go(m)-go(n-1));
    }
    return 0;
}
/*sample
34
1 1000 4
*/
