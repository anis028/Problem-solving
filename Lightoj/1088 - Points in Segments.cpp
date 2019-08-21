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
        int n,q,x,y;
        scanf("%d %d",&n,&q);
        int a[n+2];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",upper_bound(a,a+n,y)-lower_bound(a,a+n,x));
        }
    }
    return 0;
}
/*sample
   
*/
