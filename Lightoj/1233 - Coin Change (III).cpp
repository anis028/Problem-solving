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
 
int n,k,dp[100005],a[105],num[105],taken[100005];
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int cnt=0;
        scanf("%d %d",&n,&k);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        for(int i=0; i<n; i++) scanf("%d",&num[i]);
        for(int i=0; i<=k; i++)
        {
            dp[i]=0;
            taken[i]=0;
        }
        dp[0]=1;
        for(int i=0; i<n; i++)
        {
            int val=a[i];
            for(int m=val; m<=k; m++)
                if(dp[m]==0 && dp[m-val]==1 and taken[m-val]+1<=num[i])
                {
                    dp[m]=1;
                    cnt++;
                    taken[m]=taken[m-val]+1;
                }
            for(int j=0; j<=k+2; j++) taken[j]=0;
        }
//        for(int i=0;i<=k;i++) printf(" %d",dp[i]);
//        cout<<endl;
        printf("Case %d: %d\n",p++,cnt);
    }
    return 0;
}
/*sample
 
*/
