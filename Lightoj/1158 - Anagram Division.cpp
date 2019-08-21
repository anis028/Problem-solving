#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
int dp[(1<<10)+5][1005],len,fact[10],cnt[10],d;
string s;
 
int rec(int mask,int mod)
{
    //cout<<mask<<" "<<mod<<endl;
    if(mask==(1<<len)-1) return mod==0;
    int &ret=dp[mask][mod];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=0;i<len;i++){
        if(mask&(1<<i)) continue;
        ret+=rec((mask|(1<<i)),((mod*10)+(s[i]-'0'))%d);
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<10;i++) fact[i]=(fact[i-1]*i),cnt[i]=0;
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        mm(dp,-1);
        mm(cnt,0);
        cin>>s>>d;
        len=s.length();
        for(int i=0;i<len;i++) cnt[s[i]-'0']++;
        int ans=rec(0,0);
        for(int i=0;i<10;i++) ans/=fact[cnt[i]];
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
