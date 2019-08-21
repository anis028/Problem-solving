
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
 
struct point
{
    ll x,y;
}p[100005],qp;
int n;
 
ll area(point a,point b,point c)
{
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}
 
bool inpoly()
{
    int l=1,r=n-1,mid;
    while(r-l>1){
        mid=(l+r)>>1;
        if(area(p[0],p[mid],qp)<0) r=mid;
        else l=mid;
    }
    if(area(p[0],p[l],qp)<0) return false;
    if(area(p[l],p[r],qp)<0) return false;
    if(area(p[r],p[0],qp)<0) return false;
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
        int q;
        cin>>q;
        cout<<"Case "<<cas++<<":"<<endl;
        while(q--){
            cin>>qp.x>>qp.y;
            if(inpoly()) cout<<"y"<<endl;
            else cout<<"n"<<endl;
        }
    }
    return 0;
}
/*sample
 
*/
 
