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
    while(tc--){
        dbl x,x1,x2,x_,y,y1,y2,y_,z,z1,z2,z_;
        cin>>x1>>y1>>z1>>x2>>y2>>z2>>x>>y>>z;
        dbl l=0.0,r=1.0,m1,m2,ans=1000000.0,seg,dis1,dis2;
        for(int i=0;i<500;i++){
            seg=(r-l)/3.0;
            m1=l+seg,m2=l+seg+seg;
            x_=x1+(x2-x1)*m1;
            y_=y1+(y2-y1)*m1;
            z_=z1+(z2-z1)*m1;
            dis1=sqrt((x_-x)*(x_-x)+(y_-y)*(y_-y)+(z_-z)*(z_-z));
            x_=x1+(x2-x1)*m2;
            y_=y1+(y2-y1)*m2;
            z_=z1+(z2-z1)*m2;
            dis2=sqrt((x_-x)*(x_-x)+(y_-y)*(y_-y)+(z_-z)*(z_-z));
            if(dis1<dis2){
                ans=min(ans,dis1);
                r=m2;
            }
            else{
                ans=min(ans,dis2);
                l=m1;
            }
        }
        cout<<setprecision(12)<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
