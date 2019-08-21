#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   PI            acos(-1.0)
using namespace std;
typedef long long ll;
typedef double dbl;
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        double r1,r2,h,p,r3,H,v1,v2;
        cin>>r1>>r2>>h>>p;
        r3=((p*(r1-r2))/h);
        H=(p*r1)/r3;
        r3+=r2;
        v1=(PI*r3*r3*(H-h+p))/3.0;
        v2=(PI*r2*r2*(H-h))/3.0;
        cout<<fixed<<setprecision(12)<<"Case "<<cas++<<": "<<(v1-v2)<<endl;
    }
    return 0;
}
/*sample
 
*/
