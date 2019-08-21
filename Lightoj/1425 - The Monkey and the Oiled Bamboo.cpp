#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   m0d           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int n,x,y=0;
        cin>>n;
        int a[n+2];
        cin>>x;
        a[0]=x-y;
        y=x;
        for(int i=1;i<n;i++) cin>>x, a[i]=x-y,y=x;
        int ans=a[0],factor=ans-1;
//        for(int i=0;i<n;i++) cout<<a[i]<<" ";
//        cout<<endl;
        for(int i=1;i<n;i++){
            if(a[i]>ans){
                ans=a[i];
                factor=ans-1;
            }
            else if(a[i]>factor){
                ans++;
                factor=ans-1;
            }
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
