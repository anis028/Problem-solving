#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
double dp[10005],tmp,prob[105],lim;
int val[105];
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,total=0;
        scanf("%lf %d",&lim,&n);
        for(int i=0; i<n; i++){
            scanf("%d %lf",&val[i],&prob[i]);
            total+=val[i];
        }
        for(int i=1; i<=total; i++) dp[i]=1.0;
        dp[0]=0.0;
        for(int i=0; i<n; i++)
            for(int j=total; j>=val[i]; j--)
            {
                tmp=dp[j-val[i]]+(1.0-dp[j-val[i]])*prob[i];
                if(tmp<dp[j]) dp[j]=tmp;
            }
        for(int j=total; j>=0; j--)
            if(dp[j]<lim)
            {
                printf("Case %d: %d\n",cas++,j);
                break;
            }
    }
    return 0;
}
/*sample
 
*/
