#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        int i,sum=0,a[n+1];
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]<=0);
            else sum+=a[i];
        }
        printf("Case %d: %d\n",p++,sum);
    }
    return 0;
}
 
