#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int a[12],len,dp[12][12],vis[12][12],n,cas;
 
int rec(int nisi,int ansi)
{
    if(nisi==len) return 1;
    int &ret=dp[nisi][ansi];
    if(vis[nisi][ansi]!=cas)
    {
        ret=0;
        for(int i=0;i<n;i++)
        {
            if(!ansi or abs(ansi-a[i])<3)
                ret+=rec(nisi+1,a[i]);
        }
    }
    vis[nisi][ansi]=cas;
    return ret;
}
 
int main()
{
    int tc;
    cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&len);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        printf("Case %d: %d\n",cas,rec(0,0));
        cas++;
    }
    return 0;
 
}
/*sample
 
*/
