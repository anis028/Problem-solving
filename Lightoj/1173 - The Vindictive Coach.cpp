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
 
unsigned long long dp[51][51][2];
int flag[52],n;
 
unsigned long long rec(int pos,int last,int isSmall)
{
    if(pos==n) return 1;
    unsigned long long &ret=dp[pos][last][isSmall];
    if(ret!=-1) return ret;
    ret=0;
    if(isSmall){
        for(int i=1;i<last;i++){
            if(flag[i]) continue;
            flag[i]=1;
            ret+=rec(pos+1,i,0);
            flag[i]=0;
        }
    }
    else{
        for(int i=last+1;i<=n;i++){
            if(flag[i]) continue;
            flag[i]=1;
            ret+=rec(pos+1,i,1);
            flag[i]=0;
        }
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int start;
        cin>>n>>start;
        cout<<"Case "<<cas++<<": ";
        if(n<=3) {cout<<1<<endl;continue;}
        mm(flag,0);
        mm(dp,-1);
        flag[start]=1;
        if(start==1) flag[3]=1,cout<<rec(2,3,1)<<endl;
        else cout<<rec(1,start,1)<<endl;;
    }
    return 0;
}
/*sample
 
*/
