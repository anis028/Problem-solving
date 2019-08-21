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
        double x1,x2,y1,y2,r1,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        cout<<"Case "<<p++<<": ";
        double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(r1+r2<d) cout<<"0.000000"<<endl;
        else if(r1>=r2+d) cout<<acos(-1.0)*r2*r2<<endl;
        else if(r2>=r1+d) cout<<acos(-1.0)*r1*r1<<endl;
        else
        {
            double theta1=2.0*(acos(((d*d)+(r1*r1)-(r2*r2))/(2.0*d*r1)));
            double theta2=2.0*(acos(((d*d)+(r2*r2)-(r1*r1))/(2.0*d*r2)));
            double area1=0.5*r1*r1*sin(theta1),area2=0.5*r2*r2*sin(theta2);
            area1=(0.5*r1*r1*theta1)-area1;
            area2=(0.5*r2*r2*theta2)-area2;
            area1=area1+area2;
            cout<<fixed<<setprecision(10)<<area1<<endl;
        }
    }
    return 0;
}
/*sample
 
*/
 
