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
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,x,y,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            ans=(ans^(y-x-1));
        }
        printf("Case %d: ",p++);
        if(ans) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
/*sample
 
*/
 
