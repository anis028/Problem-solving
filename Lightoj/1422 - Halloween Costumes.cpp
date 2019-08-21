#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int a[105],dp[105][105],n;
 
/*int solve(int l,int r)
{
    if(l>r) return 0;
    int &ret=dp[l][r];
    if(ret!=-1) return ret;
    ret=0;
    if(a[l]==a[r]) ret=solve(l+1,r-1);
    else ret=1+min(solve(l+1,r),solve(l,r-1));
    return ret;
 
}
*/
int go(int b, int e) {
 
    if (b==n||b>e)return 0;
 
    int& best=dp[b][e];
    if (best==-1) {
        //kono dress na khule
        best=1+go(b+1,e);
 
        //if dress khuli
        //go through all  future match for current dress
        for (int i=b+1;i<n;++i) {
            if (a[b]==a[i]) {
                best=min(best,go(b+1,i-1)+go(i,e) );
            }
        }
    }
    return  best;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        mm(dp,-1);
        int ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        printf("Case %d: %d\n",cas++,go(0,n-1));
 
    }
    return 0;
}
/*sample
 
*/
