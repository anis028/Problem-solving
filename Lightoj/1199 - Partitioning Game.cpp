#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
using namespace std;
typedef long long ll;
typedef double dbl;
 
int dp[10005];
 
int game(int x)
{
    if(x<3) return 0;
    int &ret=dp[x];
    if(ret!=-1) return ret;
    ret=0;
    set<int>s;
    int m=(x/2)-(x%2==0);
    for(int i=1;i<=m;i++){
        s.insert(game(i)^game(x-i));
    }
    while(s.count(ret)) ret++;
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    mm(dp,-1);
    while(tc--){
        int n,x,nim=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>x, nim^=game(x);
        cout<<"Case "<<cas++<<": ";
        if(nim) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
/*sample
 
*/
 
