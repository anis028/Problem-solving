#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define   mod           1000000007
using namespace std;
typedef long long ll;
typedef double dbl;
 
ll ncr[220][220],dp[220][55];
 
void ncr_cal()
{
    for(int i=0;i<220;i++){
        ncr[i][0]=ncr[i][i]=1;
        for(int j=1;j<i;j++){
            ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
        }
    }
}
 
ll rec(int square,int color)
{
    if(color<=0 || square<=0 || color>square) return 0;
    if(color==1) return 1;
    ll &ret=dp[square][color];
    if(ret!=-1) return ret;
    ret=0;
    for(int nisi=1;nisi<square;nisi++){
        ll tmp=(ncr[square][nisi]*rec(square-nisi,color-1))%mod;
        ret=(ret+tmp)%mod;
    }
    return ret;
}
 
ll solve(int n,int m,int k)
{
    if(n==1 and m==1) return k;
    ll ret=0;
    int a=(n*m)/2;
    int b=(n*m)-a;
    for(int color=1;color<k;color++){
        for(int rest=1;color+rest<=k;rest++){
            ll tmp=ncr[k][color];
            tmp=(tmp*ncr[k-color][rest])%mod;
            tmp=(tmp*rec(a,color))%mod;
            tmp=(tmp*rec(b,rest))%mod;
            ret=(ret+tmp)%mod;
        }
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    ncr_cal();
    mm(dp,-1);
    while(tc--){
        int n,m,k;
        cin>>n>>m>>k;
        n++,m++;
        cout<<"Case "<<cas++<<": "<<solve(n,m,k)<<endl;;
    }
    return 0;
}
/*sample
 
*/
