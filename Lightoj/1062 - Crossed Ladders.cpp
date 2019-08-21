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
        double ans,x,y,c,mid,hi,lo=0.0,t1,t2,z,h;
        cin>>x>>y>>c;
        hi=min(x,y);
        while(1)
        {
            mid=(hi+lo)/2.0;
            t1=acos(mid/y);
            t2=acos(mid/x);
            z=(mid*tan(t2))/(tan(t1)+tan(t2));
            h=z*tan(t1);
            if(fabs(h-c)<=1e-8)
            {
                ans=mid;
                break;
            }
            else if(h>c) lo=mid;
            else hi=mid;
        }
        printf("Case %d: ",p++);
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
