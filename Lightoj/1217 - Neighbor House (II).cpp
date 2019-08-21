#include<bits/stdc++.h>
 
using namespace std;
 
int dp[1005][2],a[1005],n;
 
int rec(int pos,int one)
{
    if(pos>=n) return 0;
    if(pos==n-1 and one==1) return 0;
 
    int &ret=dp[pos][one];
    if(ret!=-1) return ret;
 
    int x=rec(pos+1,one);
    if(pos==0)
        one=1;
    int y=rec(pos+2,one)+a[pos];
 
    return ret=max(x,y);
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",p++,rec(0,0));
    }
 
    return 0;
}
