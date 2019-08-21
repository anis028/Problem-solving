#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        double R,n;
        scanf("%lf %lf",&R,&n);
        double x=sin(acos(-1.0)/n);
        printf("Case %d: %.10lf\n",p++,((R*x)/(1.0+x)));
    }
    return 0;
}
