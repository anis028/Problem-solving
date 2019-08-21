#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        long long int n,sum=0,i,j;
        scanf("%lld",&n);
        for(i=2;i*i<=n;i++)
        {
            j=n/i;
            sum+=(j+i)*(j-i+1)/2;
            sum+=i*(j-i);
        }
        printf("Case %d: %lld\n",p++,sum);
    }
    return 0;
}
