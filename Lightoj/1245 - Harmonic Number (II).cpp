#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
using namespace std;
typedef long long ll;
typedef double dbl;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        cout<<"Case "<<cas++<<": ";
        if(n==1) cout<<n<<endl;
        else{
            ll sum = n, last=1, start_p=n, end_p,tmp;
            for(int i= 2; ;i++){
                tmp = n/i;
                end_p = tmp;
                sum += (start_p - end_p) * last;
                if(end_p < i) break;
                sum += tmp;
                last = i;
                start_p = end_p;
                if(end_p==i)break;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
/*sample
 
*/
 
