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
 
int dp[(1<<16)+7],n,a[17][17];
 
int rec(int row,int mask)
{
    if(mask==(1<<n)-1)return 0;
    int &ret=dp[mask];
    if(ret!=-1) return ret;
 
    for(int i=0;i<n;i++)
        if(!(mask&(1<<i)))
            ret=max(ret,a[row][i]+rec(row+1,mask|(1<<i)));
 
    return ret;
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        mm(dp,-1);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
        printf("Case %d: %d\n",p++,rec(0,0));
    }
    return 0;
}
/*sample
 
*/
