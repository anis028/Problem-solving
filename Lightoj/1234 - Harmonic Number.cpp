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
 
double ans[1000001];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    int ind=1;
    double sum=0.0;
    for(int i=1;i<100000001;i++){
        sum+=1.0/(double)i;
        if(i%100==0) ans[ind++]=sum;
    }
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        double res = ans[n/100];
        for(int i=100*(n/100)+1;i<=n;i++) res += 1.0/(double)i;
        cout<<fixed<<setprecision(12)<<"Case "<<cas++<<": "<<res<<endl;
    }
    return 0;
}
/*sample
 
*/
 
