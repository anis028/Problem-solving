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
 
int n,book[105],dp[103][103][103];
 
int rec(int pos,int left,int right)
{
    //cout<<pos<<" "<<left<<" "<<right<<" "<<taken<<endl;
    if(pos>=n) return 0;
    int &ret=dp[pos][left][right];
    if(ret!=-1) return ret;
    ret=0;
    if(book[pos]>=book[left] and book[pos]<=book[right])
        ret=max(rec(pos+1,pos,right),rec(pos+1,left,pos))+1;
 
    ret=max(ret,rec(pos+1,left,right));
    return ret;
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int right=0,left=100005,x,y;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
                scanf("%d",&book[i]);
                if(book[i]>right){right=book[i];x=i;}
                if(book[i]<left){left=book[i];y=i;}
        }
        mm(dp,-1);
        printf("Case %d: %d\n",p++,rec(0,y,x));
 
    }
    return 0;
}
/*sample
 
*/

