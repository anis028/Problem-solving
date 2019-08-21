#include<bits/stdc++.h>
 
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   md            1000000007
#define   fs            first
#define   sc            second
 
using namespace std;
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int ans=1,n,dig,r=-1,x;
        scanf("%d %d",&n,&dig);
        x=dig;
        while(x!=0)
        {
            while(x<n)
            {
                x=(x*10)+dig;
                ans++;
            }
            x-=(n*(x/n));
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
/*sample
 
*/
