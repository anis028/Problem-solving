#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        int a[n],ans=0;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int x=lower_bound(a,a+n,a[i]+a[j])-a;
                ans+=(x-j-1);
            }
        }
        cout<<"Case "<<p++<<": "<<ans<<endl;
 
    }
    return 0;
}
