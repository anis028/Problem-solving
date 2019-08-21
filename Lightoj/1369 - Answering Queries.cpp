#include<bits/stdc++.h>
 
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   md            1000000007
#define   fs            first
#define   sc            second
 
using namespace std;
 
long long a[100005],co[100005];
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int x,n,q;
        long long ans=0;
        memset(co,0,sizeof(co));
        scanf("%d %d",&n,&q);
       
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
       
        x=n-1;
       
        for(int i=0;i<n;i++,x-=2)
            co[i]=x;
       
        for(int i=0;i<n;i++) ans+=(a[i]*co[i]);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            scanf("%d",&x);
            if(x==1) printf("%lld\n",ans);
            else
            {
                scanf("%d %d",&x,&n);
                ans-=(a[x]*co[x]);
                a[x]=n;
                ans+=(a[x]*co[x]);
            }
        }
 
    }
    return 0;
}
/*sample
   
*/
