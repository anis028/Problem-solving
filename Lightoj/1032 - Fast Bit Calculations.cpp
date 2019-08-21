#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
vector<int> v;
long long dp[50][50][3];
 
 
inline void getbin(int n)
{
    while(n)
    {
        v.pb(n%2);
        n/=2;
    }
}
 
inline long long solve(int pos,int tight,int ek,int x)
{
    //cout<<"to "<<pos<<" "<<tight<<" "<<ek<<endl;
    if(pos==-1) return x;
    if(dp[pos][x][ek]!=-1 and tight==0)
    {
        //cout<<"return hoise"<<endl;
        return dp[pos][x][ek];
    }
    long long ret=0;
    int lim=tight?v[pos]:1;
    for(int i=0; i<=lim; i++)
    {
        int ntight=(v[pos]==i)? tight: 0;
        //cout<<"from "<<pos<<" "<<i<<" "<<ek<<endl;
        if(i==1)
        {
            //cout<<pos<<endl;
            if(ek) ret+=solve(pos-1,ntight,1,x+1);
            else ret+=solve(pos-1,ntight,1,x);
        }
        else ret+=solve(pos-1,ntight,0,x);
    }
    if(tight==0)
    {
        //cout<<"shesh "<<pos<<" "<<endl;
        dp[pos][x][ek]=ret;
    }
    return ret;
 
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    memset(dp,-1,sizeof dp);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        v.clear();
        getbin(n);
        printf("Case %d: %lld\n",cas++,solve(v.size()-1,1,0,0));
    }
    return 0;
}
/*sample
 
*/
