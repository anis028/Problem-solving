#include<bits/stdc++.h>
 
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   md            1000000007
#define   fs            first
#define   sc            second
 
using namespace std;
int cnt[1000005];
int main()
{
    int tc,cas=1,ase[55];
    scanf("%d",&tc);
    while(tc--)
    {
        memset(cnt,0,sizeof(cnt));
        int ind=0,ans=0;
        int n,x;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(cnt[x]==0) ase[ind++]=x;
            cnt[x]++;
        }
        for(int i=0;i<ind;i++)
        {
            x=ase[i];
            ans+=((x+1)*((cnt[x]+x)/(x+1)));
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
/*sample
 
*/
