#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
using namespace std;
typedef long long ll;
typedef double dbl;
 
vector<pair<pair<int,int>,int> >v;
int dp[200005],n;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        v.clear();
        mm(dp,0);
        int a,b,c,mx=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            v.pb({{a,a+b},c});
            mx=max(mx,a+b);
        }
        sort(v.begin(),v.end());
        int ind=0;
        for(int i=0;i<mx;i++){
            while(ind<n and v[ind].fs.fs==i){
                dp[v[ind].fs.sc]=max(dp[v[ind].fs.sc],dp[v[ind].fs.fs]+v[ind].sc);
                ind++;
            }
            dp[i+1]=max(dp[i+1],dp[i]);
        }
        cout<<"Case "<<cas++<<": "<<dp[mx]<<endl;
    }
    return 0;
}
/*sample
1
3
1 5 1
2 10 3
7 12 1
*/
