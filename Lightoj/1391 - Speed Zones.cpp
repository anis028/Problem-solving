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
 
int s[110];
double theta[105];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>s[i];
        double l=0,r=1,mid,ans=1e18;
        for(int x=1;x<=100;x++){
//            cout<<x<<"th iteration"<<endl;
            mid=(l+r)/2;
            theta[1]=mid;
            for(int i=2;i<=n;i++) theta[i]=theta[i-1]*s[i]/s[i-1];
            double len=0,cost=0;
            for(int i=1;i<=n;i++){
                double c = 100/sqrt(max(0.0,1-theta[i]*theta[i]));
 
                double a = c*theta[i];
//                cout<<i<<" -> "<<c<<" "<<theta[i]<<" "<<a<<endl;
                len+=a;
                cost+=c/s[i];
            }
            if(len>=d) ans=min(ans,cost), r=mid;
            else l=mid;
        }
        cout<<"Case "<<cas++<<": "<<fixed<<setprecision(8)<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/

