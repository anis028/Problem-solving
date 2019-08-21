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
 
int n,w,a1[50],a2[50];
vector<int>a,b;
 
inline void rec1(int sum,int i)
{
    if(i>(n/2))
    {
        a.pb(sum);
        return;
    }
    rec1(sum,i+1);
    if(sum<=w-a1[i]) rec1(sum+a1[i],i+1);
}
 
inline void rec2(int sum,int i)
{
    if(i==n)
    {
        b.pb(sum);
        return;
    }
    rec2(sum,i+1);
    if(sum<=w-a2[i]) rec2(sum+a2[i],i+1);
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        a.clear();
        b.clear();
        scanf("%d %d",&n,&w);
        for(int i=0;i<=(n/2);i++)
            scanf("%d",&a1[i]);
        for(int i=(n/2)+1;i<n;i++)
            scanf("%d",&a2[i]);
        rec1(0,0);
        rec2(0,(n/2)+1);
        int ans=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<b.size();i++)
        {
            int x=w-b[i];
            ans+=(upper_bound(a.begin(),a.end(),x))-a.begin();
        }
        printf("Case %d: %d\n",p++,ans);
    }
    return 0;
}
/*sample
 
*/
