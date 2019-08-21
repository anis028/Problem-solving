#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        double ans=0.0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) ans+= (double) n/i;
        printf("Case %d: %.10f\n",cas++,ans);
    }
    return 0;
}
/*sample
 
*/
