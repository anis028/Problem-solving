#include<bits/stdc++.h>
 
using namespace std;
 
int dp[30][200], t[30][200], vis[30][200];
int fish[30], decr[30], travel[30],n,cas=1;
 
int rec(int pos,int left)
{
    if(pos == n || left<=0) return 0;
    int &ret = dp[pos][left];
    if(vis[pos][left]==cas) return ret;
    vis[pos][left] = cas;
   
    ret=rec(pos+1,left-travel[pos]);
    t[pos][left]=0;
    int minus = 0,collected=0;
    for(int i=1;i<=left;i++,minus+=decr[pos]){
        collected += max(fish[pos]-minus,0);
        int tmp = rec(pos+1, left-i-travel[pos]) + collected;
        if(tmp>=ret){
            ret=tmp;
            t[pos][left]=i;
        }
    }
    return ret;
}
 
void print_sol(int pos,int left)
{
    if(pos==n){
        cout<<endl;
        return;
    }
    if(pos) cout<<", ";
    if(left<=0){
        cout<<0;
        print_sol(pos+1,0);
    }
    else{
        cout<<t[pos][left]*5;
        print_sol(pos+1,left-t[pos][left]-travel[pos]);
    }
}
 
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        int h;
        cin>>n>>h;
        for(int i=0;i<n;i++) cin>>fish[i];
        for(int i=0;i<n;i++) cin>>decr[i];
        for(int i=0;i<n-1;i++) cin>>travel[i];
        travel[n-1]=0;
        int ans = rec(0,h*12);
        cout<<"Case "<<cas++<<":"<<endl;
        print_sol(0,h*12);
        cout<<"Number of fish expected: "<<ans<<endl;
    }
    return 0;
}
