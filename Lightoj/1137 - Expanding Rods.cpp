#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   m0d           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   lim           1000000000
using namespace std;
 
double old,n;
 
double func(double b)
{
 
    double c=old*0.5,r,a;
    r=b/2+(c*c/(2*b));
    a=2*asin(c/r);
    return r*a;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        double temp,c;
        scanf("%lf %lf %lf",&old,&temp,&c);
        n=old*(1.0+(temp*c));
        double s=0.0,f=old,mid;
        for(int i=0;i<=60;i++)
        {
            mid=(s+f)*0.5;
            if(func(mid)>n) f=mid;
            else s=mid;
        }
        printf("Case %d: %f\n",cas++,mid);
    }
    return 0;
}
/*sample
 
*/

