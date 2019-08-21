#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define   pll           pair<ll,ll>
using namespace std;
typedef long long ll;
typedef double dbl;
 
pll points[10005];
ll k,d,snipers,n;
 
bool cmp(pll a,pll b)
{
    return a.sc<b.sc;
}
 
int check(dbl m)
{
    ll cnt=1;
    pll ara[n+2];
    ll delta,x,y;
    for(int i=0;i<n;i++){
        x=points[i].fs;
        y=points[i].sc-k+m;
        if(y>d) return 0;
        delta=sqrt(d*d-y*y);
        ara[i].fs=x-delta;
        ara[i].sc=x+delta;
    }
    sort(ara,ara+n,cmp);
    ll last=ara[0].sc;
    for(int i=1;i<n;i++){
        if(ara[i].fs>last){
            cnt++;
            last=ara[i].sc;
        }
    }
    return cnt<=snipers;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        cin>>k>>n>>snipers>>d;
        for(int i=0;i<n;i++) cin>>points[i].fs>>points[i].sc;
        int l=0,h=d,ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid)) ans=mid, l=mid+1;
            else h=mid-1;
        }
        cout<<"Case "<<cas++<<": ";
        if(ans==-1) cout<<"impossible"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
 
