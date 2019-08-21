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
 
int uranium[502][502],radium[502][502],dp[502][502];
 
int solve(int i,int j)
{
    if(i<1 || j<1) return 0;
    int &ret= dp[i][j];
    if(ret!=-1) return ret;
    return ret= max( (uranium[i][j]+solve(i-1,j)) , (radium[i][j]+solve(i,j-1)) );
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--){
        int ro,co;
        scanf("%d %d",&ro,&co);
        for(int i=1;i<=ro;i++){
            for(int j=1;j<=co;j++){
                scanf("%d",&uranium[i][j]);
                uranium[i][j]+=uranium[i][j-1];
            }
        }
        for(int i=1;i<=ro;i++){
            for(int j=1;j<=co;j++){
                scanf("%d",&radium[i][j]);
                radium[i][j]+=radium[i-1][j];
            }
        }
        mm(dp,-1);
        printf("Case %d: %d\n",cas++,solve(ro,co));
    }
    return 0;
}
/*sample
 
*/
