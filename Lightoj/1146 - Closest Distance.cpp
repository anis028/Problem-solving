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
        dbl ax,ay,bx,by,cx,cy,dx,dy,x_,y_,x__,y__;
        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
        dbl l=0.0,r=1.0,m1,m2,ans=1000000.0,seg,dis1,dis2;
        for(int i=0;i<10000;i++){
            seg=(r-l)/3.0;
            m1=l+seg,m2=l+seg+seg;
            x_=ax+(bx-ax)*m1;
            y_=ay+(by-ay)*m1;
            x__=cx+(dx-cx)*m1;
            y__=cy+(dy-cy)*m1;
            dis1=sqrt((x_-x__)*(x_-x__)+(y_-y__)*(y_-y__));
            x_=ax+(bx-ax)*m2;
            y_=ay+(by-ay)*m2;
            x__=cx+(dx-cx)*m2;
            y__=cy+(dy-cy)*m2;
            dis2=sqrt((x_-x__)*(x_-x__)+(y_-y__)*(y_-y__));
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
