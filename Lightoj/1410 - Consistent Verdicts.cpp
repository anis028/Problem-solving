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
 
int x[702],y[702];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        vector<int>v;
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>x[i]>>y[i];
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                v.pb((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        sort(v.begin(),v.end());
        cout<<"Case "<<cas++<<": ";
        cout<<1+distance(v.begin(),unique(v.begin(),v.end()))<<endl;
    }
    return 0;
}
/*sample
 
*/

