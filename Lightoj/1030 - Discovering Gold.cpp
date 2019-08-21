#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int a[105],n;
double dp[105];
 
double solve(int pos)
{
    if(pos==n-1) return 0;
    double &ret= dp[pos],cnt=0.0;
    if(dp[pos]>-0.5) return ret;
    ret=0.0;
    for(int i=1;i<7;i++)
    {
        if(pos+i>=n) cnt+=1.0;
        else ret+=((1/6.0)*(a[pos+i]+solve(pos+i)));
    }
    //cout<<ret<<" "<<pos<<endl;
    double m=6.0/(6.0-cnt);
 
    ret*=m;
    return ret;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(int i=0;i<n+2;i++) dp[i]=-1.0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        printf("Case %d: %.10f\n",cas++,solve(0)+a[0]);
    }
    return 0;
}
/*sample
 
*/
