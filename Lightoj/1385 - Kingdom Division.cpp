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
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        double a,b,c,x,y;
        cin>>a>>b>>c;
        x=(a*c)/b;
        cout<<"Case "<<cas++<<": ";
        if(b-x<1e-9) cout<<-1<<endl;
        else{
            y=((a+x)*(x+c))/(b-x);
            cout<<fixed<<setprecision(12)<<x+y<<endl;
        }
    }
    return 0;
}
/*sample
 
*/
