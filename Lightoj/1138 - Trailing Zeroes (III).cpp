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
 
int n;
 
int zero(int n)
{
    int cnt=0;
    while(n>0)
    {
        n/=5;
        cnt+=n;
    }
    return cnt;
}
 
int solve(int l,int h)
{
    if(h<l) return -1;
    int mid=((h-l)/2)+l;
    int cnt=zero(mid);
    if(cnt==n)
    {
        while(zero(mid)==cnt) mid--;
        return ++mid;
    }
    if(cnt>n) return solve(l,mid-1);
    else return solve(mid+1,h);
}
 
int main()
{
    int tc,cas=1,ans;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        ans=solve(1,INT_MAX);
        printf("Case %d: ",cas++);
        if(ans==-1) printf("impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}
/*sample
   
*/
