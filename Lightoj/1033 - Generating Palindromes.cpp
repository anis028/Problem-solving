#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int cas=1,dp[105][105],vis[105][105];
string s;
 
int rec(int i,int j)
{
    if(i>=j) return 0;
    int &ret=dp[i][j];
 
    if(vis[i][j]==cas) return ret;
    vis[i][j]=cas;
 
    if(s[i]==s[j]) return ret=rec(i+1,j-1);
    else return ret=1+min(rec(i+1,j),rec(i,j-1));
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>s;
        int l=s.length();
        printf("Case %d: %d\n",cas,rec(0,l-1));
        cas++;
    }
 
    return 0;
}
/*sample
 
*/
