#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define N 3
#define MOD 10007
using namespace std;
typedef long long ll;
typedef double dbl;
 
ll base[N][N]={{1,1,2},{1,0,0},{0,1,1}};
ll unit[N][N]={{1,0,0},{0,1,0},{0,0,1}};
 
void mul(ll a[N][N], ll b[N][N]) {
    int i, j, k;
    ll r[N][N] = {0};
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            for(k = 0; k < N; k++) {
                r[i][j] += a[i][k]*b[k][j];
                if(r[i][j] >= MOD) r[i][j] %= MOD;
            }
        }
    }
    memcpy(a, r, sizeof(r));
}
 
void expo(ll r[N][N], ll n) {
    ll b[N][N];
    memcpy(r, unit, sizeof(unit));
    memcpy(b, base, sizeof(base));
    while(n > 0) {
        if(n&1) mul(r, b);
        n >>= 1;
        mul(b, b);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    ll mat[N][N];
    while(tc--){
        int n;
        cin>>n;
        cout<<"Case "<<cas++<<": ";
        if(n==1) cout<<1<<endl;
        else if(n==2) cout<<2<<endl;
        else{
            expo(mat,n-2);
            cout<<(mat[0][0]+mat[0][0]+mat[0][1]+mat[0][2])%MOD<<endl;
        }
    }
    return 0;
}
/*sample
 
*/
 
