#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
vector<int>v[100005];
double dp[100005];
 
inline double solve(int x)
{
    //cout<<x<<endl;
    if(x==1) return 1.0;
    double &ret=dp[x];
    if(ret>-0.5) return ret;
    ret=0.0;
    for(int i=1;i<v[x].size();i++)
    {
        ret+=(1.0/v[x].size())*(1.0+solve(x/v[x][i]));
        //cout<<x<<" "<<ret<<endl;
    }
    ret*=(1.0*v[x].size())/(v[x].size()-1);
    return ret;
}
 
inline void divsiv()
{
    for(int i=1;i<100005;i++)
        for(int j=i;j<100005;j+=i) v[j].pb(i);
 
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    divsiv();
    for(int i=1;i<100005;i++) dp[i]=-1.0;
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        if(n==1)
        {
            printf("Case %d: 0\n",cas++);
            continue;
        }
        printf("Case %d: %.12f\n",cas++,solve(n));
        //cout<<solve(n)<<endl;
    }
    return 0;
}
/*sample
 
*/
