#include<cstdio>
#include<cstring>
#include<algorithm>
 
using namespace std;
typedef long long LL;
const int MOD = 1e6+7;
 
char s[1005],t[1005];
int n,m,dp[1001][1001];
int num[1001][1001];
 
void init(){
    int i,j;
    for(i = 0;i <= n;i++) dp[i][0] = 0,num[i][0]=1;
    for(j = 0;j <= m;j++) dp[0][j] = 0,num[0][j]=1;
}
 
void sol(){
    int i,j,k;
    for(i = 1;i <= n;i++){
        for(j = 1;j <= m;j++){
            if(s[i]==t[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                num[i][j] = num[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j-1]>dp[i-1][j]){
                    num[i][j] = num[i][j-1];
                }else if(dp[i][j-1]<dp[i-1][j]){
                    num[i][j] = num[i-1][j];
                }else{
                    num[i][j] = num[i-1][j]+num[i][j-1]-(dp[i][j]==dp[i-1][j-1]?num[i-1][j-1]:0);
                    num[i][j] = (num[i][j]%MOD+MOD)%MOD;
                }
            }
        }
    }
    printf("%d\n",num[n][m]);
}
 
int main(){
    int i,j,cas;
    scanf("%d",&cas);
    for(int T=1;T<=cas;T++){
        scanf("%s%s",s+1,t+1);
        n = strlen(s+1);
        m = strlen(t+1);
        printf("Case %d: ",T);
        init();
        sol();
    }
    return 0;
}
