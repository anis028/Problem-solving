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
#define pi acos(-1.0)
#define fs first
#define sc second
 
using namespace std;
 
pair<double,double> divide(double x1,double y1,double x2,double y2,double m,double n)
{
    return pair<double,double>((n*x1+m*x2)/(m+n),(n*y1+m*y2)/(m+n));
}
 
pair<double,double> ghurai(double x,double y,double ang)
{
    return pair<double,double>((x*cos(ang)-y*sin(ang)),x*sin(ang)+y*cos(ang));
}
 
int main()
{
    int tc,p=1;
    cin>>tc;
    while(tc--)
    {
        double x1,y1,x2,y2,a,b,c,d;
        cin>>x1>>y1>>x2>>y2>>b>>c>>d;
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        pair<double,double> x,y;
        x=divide(x1,y1,x2,y2,d,a-d);
        y=divide(x1,y1,x2,y2,a-b,b);
        double theta_a=acos((d*d+(a-c)*(a-c)-b*b)/(2*d*(a-c)));
        double theta_b=acos(((a-c)*(a-c)+b*b-d*d)/(2*b*(a-c)));
        x=ghurai(x.fs-x1,x.sc-y1,theta_a);
        y=ghurai(y.fs-x2,y.sc-y2,-theta_b);
        cout<<"Case "<<p++<<":\n";
        cout<<fixed<<setprecision(10)<<y.fs+x2<<" "<<y.sc+y2<<" "<<x.fs+x1<<" "<<x.sc+y1<<endl;
    }
    return 0;
}
/*sample
 
*/
