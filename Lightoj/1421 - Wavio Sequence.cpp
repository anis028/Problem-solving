#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
int n,ara[100005],lis[100005],lds[100005],temp[100005];
void rec(int x)
{
    for(int i=0;i<n+2;i++) temp[i]=200000000;
    temp[0]=-200000000;
    int len=0;
    for(int i=0;i<n;i++)
    {
        int l=0,h=len;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(temp[mid]<ara[i]) l=mid+1;
            else h=mid-1;
        }
        temp[l]=ara[i];
        if(x) lds[i]=l;
        else lis[i]=l;
        if(l>len) len++;
    }
 
}
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        rec(0);
        reverse(ara,ara+n);
        rec(1);
        reverse(lds,lds+n);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,2*(min(lis[i],lds[i]))-1);
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
/*sample
 
*/
 
