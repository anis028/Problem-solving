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
 
int sz,dp[105][105],w;
vector<pii>v;
 
int rec(int pos,int k)
{
    if(k==0 or pos==sz) return 0;
    int &ret=dp[pos][k];
    if(ret!=-1) return ret;
    ret=0;
    int lim=v[pos].fs+w,i;
    for(i=pos;i<sz;i++)
    {
        if(v[i].fs>lim) break;
        ret+=v[i].sc;
    }
    ret+=rec(i,k-1);
    return ret=max(ret,rec(pos+1,k));
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,k,x,y;
        scanf("%d %d %d",&n,&w,&k);
        vector<pii>points;
        points.clear();
        v.clear();
        while(n--)
        {
            scanf("%d %d",&x,&y);
            points.pb({y,x});
        }
        sort(points.begin(),points.end());
        sz=0;
        for(int i=1;i<=points.size();i++)
        {
            int cnt=1;
            while(points[i].fs==points[i-1].fs and i<points.size())i++,cnt++;
            v.pb({points[i-1].fs,cnt});
            sz++;
        }
        mm(dp,-1);
        printf("Case %d: %d\n",cas++,rec(0,k));
 
    }
    return 0;
}
/*sample
   
*/
