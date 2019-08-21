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
 
ll dp[50003];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int ara[n+2],sum=0;
        for(int i=0;i<n;i++) cin>>ara[i],sum+=ara[i];
        int lim=sum>>1;
        mm(dp,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=lim;j>=ara[i];j--)
                dp[j] |= dp[j-ara[i]]<<1;
        }
        int a=(n+1)>>1,b=n>>1,j;
        for(j=lim;j>0;j--){
            if(dp[j] & ((ll)1<<a)) break;
            if(dp[j] & ((ll)1<<b)) break;
        }
        cout<<"Case "<<cas++<<": "<<j<<" "<<sum-j<<endl;
    }
    return 0;
}
/*sample
 
*/
