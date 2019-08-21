#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846
 
typedef long long ll ;
typedef unsigned long long ull ;
 
 
ll dp[2][20000+10] , mod = 100000007 ;
 
ll solve()
{
    int N , K , S ;
    cin >> N >> K >> S ;
 
    int now = 1 ;
 
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=S;j++)
        {
            if(i==1)
            {
                if(j<=K) dp[i][j] = 1 ;
                else dp[i][j] = 0 ;
            }
            else
            {
                dp[now][j] = ( dp[now][j-1] + dp[now^1][j-1] - ( j-K-1 < 0 ? 0 : dp[now^1][j-K-1] ) ) %mod ;
                dp[now][j] = ( dp[now][j] + mod ) % mod ;
            }
        }
        now=now^1;
    }
 
    return dp[now^1][S] ;
}
 
int main()
{
    int T ;
    cin >> T ;
 
    for(int cas=1;cas<=T;cas++)
    {
        cout << "Case " << cas << ": " << solve() << endl ;
    }
    return 0;
}
