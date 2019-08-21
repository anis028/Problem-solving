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
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        int ans=1;
        bool neg=(n<0);
        if(n<0) n = -n;
        for(ll i=2;i*i<=n;i++){
            ll now=i,cur=i;
            for(int p=1;cur<=n;p++,cur*=now){
                if(cur==n){
                    if(neg){
                        if(p%2) ans=max(ans,p);
                    }
                    else ans=max(ans,p);
                }
            }
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
 
 

