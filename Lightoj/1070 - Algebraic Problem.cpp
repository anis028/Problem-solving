#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define N 2
using namespace std;
typedef unsigned long long ull;
typedef double dbl;
 
ull base[N][N]={{0,0},{1,0}};
ull unit[N][N]={{1,0},{0,1}};
 
void mul(ull a[N][N], ull b[N][N]) {
    int i, j, k;
    ull r[N][N] = {0};
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            for(k = 0; k < N; k++) {
                r[i][j] += a[i][k]*b[k][j];
                //if(r[i][j] >= MOD) r[i][j] %= MOD;
            }
        }
    }
    memcpy(a, r, sizeof(r));
}
 
void expm(ull r[N][N], ull n) {
    ull b[N][N];
    memcpy(r, unit, sizeof(unit));
    memcpy(b, base, sizeof(base));
    b[0][1]=-b[0][1];
    while(n > 0) {
        if(n&1) mul(r, b);
        n >>= 1;
        mul(b, b);
    }
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    ull mat[N][N];
    while(tc--){
        int n;
        scanf("%d %d %d",&base[0][0],&base[0][1],&n);
        printf("Case %d: ",cas++);
        if(n==0) printf("2\n");
        else if(n==1) printf("%llu\n",base[0][0]);
        else{
            expm(mat,n-1);
            printf("%llu\n",mat[0][0]*base[0][0]+2ull*mat[0][1]);
        }
    }
    return 0;
}
/*sample
 
*/
 

