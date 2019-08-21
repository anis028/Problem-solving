#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
long long nc4[10005],ans[10005];
 
int main()
{
    nc4[4]=1ll;
    for(int i=5; i<=10000; i++)
        nc4[i]=(i*nc4[i-1])/(i-4);
    int tc,cas=1,x,n,mx=0;
    int cnt[10005];
    scanf("%d",&tc);
    while(tc--)
    {
        mm(cnt,0);
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&x);
            mx=max(mx,x);
            for(int j=1; j*j<=x; j++)
                if(x%j==0){
                    cnt[j]++;
                    if(j*j!=x)cnt[x/j]++;
                }
        }
        for(int i=mx; i>0; i--)
        {
            ans[i]=nc4[cnt[i]];
            for(int j=i+i; j<=mx; j+=i) ans[i]-=ans[j];
        }
        printf("Case %d: %lld\n",cas++,ans[1]);
    }
    return 0;
}
/*sample
 
*/
 

