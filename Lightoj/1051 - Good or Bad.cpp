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
int n,good,bad,dp[55][6][6];
 
int isvow(char c)
{
    c=toupper(c);
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return 1;
    return 0;
}
 
int solve(int pos,int vow,int con)
{
    if(vow>=3||con>=5) {bad=1;return 1;}
    if(pos>=n) {good=1;return 1;}
 
    int &ret=dp[pos][vow][con];
    if(ret==-1)
    {
        if(s[pos]=='?')
        {
            ret=solve(pos+1,vow+1,0);
            if(good and bad) return ret=1;
            ret=solve(pos+1,0,con+1);
        }
        else{
            if(isvow(s[pos])) return ret=solve(pos+1,vow+1,0);
            else return ret=solve(pos+1,0,con+1);
        }
    }
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
        n=s.length();
        bad=0;
        good=0;
        mm(dp,-1);
        solve(0,0,0);
        printf("Case %d: ",p++);
        if(good and bad) printf("MIXED\n");
        else if(good) printf("GOOD\n");
        else if(bad) printf("BAD\n");
    }
    return 0;
}
/*sample
 
*/
