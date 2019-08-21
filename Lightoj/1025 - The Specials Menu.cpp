#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
 
using namespace std;
 
string s;
long long int dp[65][65];
 
long long int solve(int i,int j)
{
    if(i>j) return 0;
    long long int &ret=dp[i][j];
    if(ret!=-1) return ret;
 
    if(i==j) return 1;
    else if(s[i]==s[j]) ret=solve(i+1,j)+solve(i,j-1)+1;
    else ret=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
 
    return ret;
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        cin>>s;
        mm(dp,-1);
        printf("Case %d: %lld\n",p++,solve(0,s.length()-1));
    }
    return 0;
}
/*sample
 
*/
