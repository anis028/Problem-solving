#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>
 
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
 
ll exgcd(ll a, ll b, ll &x,ll &y)
{
    if(!a){
        x=0,y=1;
        return b;
    }
    ll x1,y1;
    ll g=exgcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
}
 
bool find_any_solution(ll a,ll b,ll c,ll &x0, ll &y0, ll &g)
{
    g=exgcd(abs(a),abs(b),x0,y0);
    if(c%g) return false;
 
    x0*=c/g;
    y0*=c/g;
 
    x0 = a<0? -x0 : x0;
    y0 = b<0? -y0 : y0;
    return true;
}
 
void shift_solution(ll &x,ll &y,ll a,ll b,ll cnt)
{
    x+=cnt*b;
    y-=cnt*a;
}
 
ll find_all_solution(ll a,ll b,ll c,ll minx,ll maxx,ll miny,ll maxy)
{
    ll x,y,g;
    if(!find_any_solution(a,b,c,x,y,g)) return 0;
    a/=g;
    b/=g;
    ll sign_a= a>0? 1 : -1;
    ll sign_b= b>0? 1 : -1;
 
    shift_solution(x,y,a,b,(minx-x)/b);
    if(x<minx) shift_solution(x,y,a,b,sign_b);
    if(x>maxx) return 0;
    ll lx1=x;
 
    shift_solution(x,y,a,b,(maxx-x)/b);
    if(x>maxx) shift_solution(x,y,a,b,-sign_b);
    ll rx1=x;
 
    shift_solution(x,y,a,b,-(miny-y)/a);
    if(y<miny) shift_solution(x,y,a,b,-sign_a);
    if(y>maxy) return 0;
    ll lx2=x;
 
    shift_solution(x,y,a,b,-(maxy-y)/a);
    if(y>maxy) shift_solution(x,y,a,b,sign_a);
    ll rx2=x;
 
    if(lx2>rx2) swap(lx2,rx2);
    ll lx=max(lx1,lx2);
    ll rx=min(rx1,rx2);
 
    if(lx > rx) return 0;
    return ((rx-lx)/abs(b)) +1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        ll a,b,c,x1,x2,y1,y2;
        cin>>a>>b>>c>>x1>>x2>>y1>>y2;
        c*=-1;
        cout<<"Case "<<cas++<<": ";
        if(!a and !b){
            if(c) cout<<0<<endl;
            else cout<<(x2-x1+1)*(y2-y1+1)<<endl;
        }
        else if(!a or !b){
            if(!b){
                swap(a,b);
                swap(x1,y1);
                swap(x2,y2);
            }
            if(c%b) cout<<0<<endl;
            else{
                ll y=c/b;
                if(y>y2 || y<y1) cout<<0<<endl;
                else cout<<(x2-x1+1)<<endl;
            }
        }
        else cout<<find_all_solution(a,b,c,x1,x2,y1,y2)<<endl;
    }
    return 0;
}
/*sample
 
*/
