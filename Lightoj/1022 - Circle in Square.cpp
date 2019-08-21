#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--){
        double r;
        scanf("%lf",&r);
        printf("Case %d: %.2lf\n",p++,r*r*(4-(2*acos(0.0))));
    }
    return 0;
}
