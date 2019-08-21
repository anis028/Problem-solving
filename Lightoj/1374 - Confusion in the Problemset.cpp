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
        int n,x;
        cin>>n;
        int flag[n+2];
        mm(flag,-1);
        for(int i=0;i<n;i++){
            cin>>x;
            if(x>=n) continue;
            if(flag[x]==-1) flag[x]=1;
            else if(flag[n-1-x]==-1) flag[n-1-x]=1;
        }
        cout<<"Case "<<cas++<<": ";
        int done=1;
        for(int i=0;i<n;i++){
            if(flag[i]==-1){
                cout<<"no"<<endl;
                done=0;
                break;
            }
        }
        if(done) cout<<"yes"<<endl;
    }
    return 0;
}
/*sample
 
*/
