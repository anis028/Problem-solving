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
#define   fs            first
#define   sc            second
 
using namespace std;
 
int n,m;
long long dp[35][35][65];
string a,b;
 
long long rec(int i,int j,int l)
{
    if(i==n and j==m)
        return l==0?1:0;
    long long &ret=dp[i][j][l];
    if(ret!=-1) return ret;
    if(i==n) return ret= rec(i,j+1,l-1);
    else if(j==m) return ret=rec(i+1,j,l-1);
    if(a[i]==b[j]) return ret=rec(i+1,j+1,l-1);
    else return ret=rec(i+1,j,l-1)+rec(i,j+1,l-1);
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>a>>b;
        int x,lcs[2][35];
        n=a.length();
        m=b.length();
 
        for(int i=0;i<=n;i++)
        {
            x=1&i;
            for(int j=0;j<=m;j++)
            {
                if(i==0 or j==0) lcs[x][j]=0;
                else if(a[i-1]==b[j-1]) lcs[x][j]=lcs[1-x][j-1]+1;
                else lcs[x][j]=max(lcs[1-x][j],lcs[x][j-1]);
            }
        }
        int l=n+m-lcs[x][m];
        mm(dp,-1);
        printf("Case %d: %d %lld\n",cas++,l,rec(0,0,l));
    }
    return 0;
}
/*sample
   
*/
 

