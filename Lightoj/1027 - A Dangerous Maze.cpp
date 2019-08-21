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
        int n,neg=0,total=0,x,gcd;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x<0) neg++,total-=x;
            else total+=x;
        }
        printf("Case %d: ",cas++);
        if(neg==n) {printf("inf\n");continue;}
        neg=n-neg;
        gcd=__gcd(total,neg);
        printf("%d/%d\n",total/gcd,neg/gcd);
    }
    return 0;
}
/*sample
 
*/
