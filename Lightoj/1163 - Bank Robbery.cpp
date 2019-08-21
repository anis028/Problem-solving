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
 
vector<int>v[100000];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        cout<<"Case "<<cas++<<": ";
        ll x=10ll*(n/9ll);
        if(n%9ll==0ll) cout<<x-1ll<<" "<<x<<endl;
        else cout<<x+(n%9ll)<<endl;
    }
    return 0;
}
/*sample
 
*/
 
