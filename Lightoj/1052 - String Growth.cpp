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
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef double dbl;
 
ll base[N][N]={{1,1},{1,0}};
ll unit[N][N]={{1,0},{0,1}};
 
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
 
ll fibo[50];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    int tmp;
    fibo[0]=0;fibo[1]=1;
    for(int i=2;i<46;i++) fibo[i]=fibo[i-1]+fibo[i-2];
    cin>>tc;
    ll mat[N][N];
    while(tc--){
        ll n,m,X,Y,k,a,b,c,d,D,D1,D2,x,y;
        cin>>n>>X>>m>>Y>>k;
        if(n>m){
            swap(n,m);
            swap(X,Y);
        }
        int ok=1;
        if(m>44) ok=0;
        else{
            a=fibo[n];
            b=fibo[n+1];
            c=fibo[m];
            d=fibo[m+1];
            D=a*d-b*c;
            D1=d*X-b*Y;
            D2=a*Y-c*X;
            if(D==0 || D1%D || D2%D || D1/D<0 || D2/D<0) ok=0;
        }
        cout<<"Case "<<cas++<<": ";
        if(ok){
            x=D1/D ,y=D2/D;
            expo(mat,k);
            cout<<(mat[0][0]*y+mat[0][1]*x)%MOD<<endl;
        }
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
/*sample
 
*/
