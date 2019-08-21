#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--){
        double a,b;
        scanf("%lf : %lf",&a,&b);
 
        double area=(2*(acos(-1.0)-2*atan(a/b))*(pow((a*a+b*b),0.5)*0.5)+2*a);
        double x=400/area;
        printf("Case %d: %.10lf %.10lf\n",p++,x*a,x*b);
    }
    return 0;
}
