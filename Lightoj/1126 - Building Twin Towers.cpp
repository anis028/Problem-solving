#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 1e9
#define endl '\n'
#define LL long long
 
using namespace std;
 
 
int dp[2][500050];
 
int main(void)
{
    int T,n,i,j;
    int a[55];
    scanf("%d",&T);
    int cas = 1;
    while(T--)
    {
        scanf("%d",&n);
        int sum = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        sum /= 2;
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;
        int s = 0;
        for(i=1;i<=n;i++)
        {
            s ^= 1;
            for(j=0;j<=sum;j++)
            {
                dp[s][j] = max(dp[s^1][j],dp[s][j]);
                if(dp[s^1][j] == -1)
                    continue;
                if(j+a[i] <= sum)
                    dp[s][j+a[i]] = max(dp[s][j+a[i]],dp[s^1][j] + a[i]);
                if(j >= a[i])
                    dp[s][j-a[i]] = max(dp[s][j-a[i]],dp[s^1][j]); //The height of the tallest tower is constant
                else{
                    //cout<<j<<" "<<a[i]-j<<" "<<dp[s^1][j] + a[i] - j<<endl;
                    dp[s][a[i]-j] = max(dp[s][a[i]-j],dp[s^1][j] + a[i] - j);// Here notice that the height of the lower tower has become higher
                }
            }
//            for(int j=0;j<=sum;j++) cout<<dp[s][j]<<" ";
//            cout<<endl;
 
        }
        printf("Case %d: ",cas++);
        if(dp[s][0]==0)
            printf("impossible\n");
        else
            printf("%d\n",dp[s][0]);
    }
 
}
