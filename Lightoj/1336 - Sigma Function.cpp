///https://www.bbsmax.com/A/Gkz1nLZrJR/
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
    int tc,cas=1;
    cin>>tc;
    ll n;
    while(tc--){
        cin>>n;
        ll t1,t2;
        t1=sqrt(n);
        t2=sqrt(n/2);
        cout<<"Case "<<cas++<<": "<<n-t1-t2<<endl;
    }
    return 0;
}
/*sample
 
*/
