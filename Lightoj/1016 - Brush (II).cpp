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
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,w,x,ans=0;
        scanf("%d %d",&n,&w);
        int a[n+1];
        for(int i=0;i<n;i++)
            scanf("%d %d",&x,&a[i]);
        sort(a,a+n);
        x=a[0]-1;
        for(int i=0;i<n;i++) if(x<a[i]) x=a[i]+w,ans++;
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
/*sample
   
*/

