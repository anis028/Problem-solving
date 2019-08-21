#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
double cost[105][105];
 
int main()
{
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        mm(cost,0.0);
        int n,m,u,v;
        double data,tm,p;
        cin>>n>>m>>data>>tm;
        for(int i=0;i<m;i++){
            cin>>u>>v>>p;
            p*=.01;
            cost[u][v]=cost[v][u]=p;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    cost[i][j]=max(cost[i][j],cost[i][k]*cost[k][j]);
            }
        }
        printf("Case %d: %.10lf\n",cas++,(2.0*data*tm)/cost[0][n-1]);
    }
    return 0;
}
/*sample
 
*/
