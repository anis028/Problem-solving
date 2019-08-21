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
 
int n,dp[1<<17],val[18],pabo[18][18];
 
int rec(int mask)
{
    if(mask==(1<<n)-1) return 0;
    int &ret=dp[mask];
    if(ret!=-1) return ret;
    ret=1<<30;
    for(int i=0; i<n; i++)
    {
        if(!(mask&(1<<i))){
        int y=1;
        for(int j=0; j<n; j++) if(mask&(1<<j))y=max(y,pabo[j][i]);
        int x=(val[i]+y-1)/y;
        ret=min(ret,x+rec(mask|(1<<i)));}
    }
    return ret;
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        mm(dp,-1);
        char x;
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&val[i]);
        getchar();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) scanf("%1d",&pabo[i][j]);
            getchar();
        }
        printf("Case %d: %d\n",p++,rec(0));
    }
    return 0;
}
/*sample
45
3
3 5 7
030
500
007
*/
