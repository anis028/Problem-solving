#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
string txt, pattern;
 
long long dp[2][50005];
int fail[50005], occur[50005];
 
void kmp( string &t, string &p, int ind)
{
    int now = -1;
    fail[0] = now;
    occur[0]=1;
    for(int i=1;i<p.length();i++){
        while(p[now+1]!=p[i] and now>-1) now=fail[now];
        fail[i]= (p[now+1]==p[i])? ++now : -1;
        occur[i]=1;
        if(now>-1) occur[i] += occur[now];
    }
    now=-1;
    for(int i=0;i<t.length();i++){
        while(p[now+1] != t[i] and now>-1) now= fail[now];
        if(p[now+1]==t[i]) ++now;
        if(now==p.length()-1) now=fail[now];
        dp[ind][i]=occur[now];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin >> tc;
    while(tc--){
        cin >> txt >> pattern;
        kmp( txt, pattern , 0);
        reverse( txt.begin(), txt.end());
        reverse( pattern.begin(), pattern.end());
        kmp(txt,pattern,1);
        int n = txt.length();
        ll ans = 0;
        for(int i = 0, j = n - 2; i < n-1; i++, j--)
            ans += (dp[0][i] * dp[1][j]);
        cout << "Case " << cas++ << ": " << ans << endl;
    }
    return 0;
}
/*sample
 
*/
