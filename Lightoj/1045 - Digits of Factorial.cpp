#include<bits/stdc++.h>
#include<cmath>
using namespace std;
 
double a[1000001],k;
int main()
{
    int i,base,n,tc,p=1;
    for(i=1;i<1000002;i++)a[i]=a[i-1]+log(i+0.0);
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&n,&base);
        k=floor(a[n]/log(base*1.0)+1);
        printf("Case %d: %.0lf\n",p++,k);
    }
    return 0;
}
