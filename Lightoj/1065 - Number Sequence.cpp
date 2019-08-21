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
 
int mod[5]= {1,10,100,1000,10000};
ll MOD;
 
struct Matrix
{
    vector< vector<ll> > mat;
    int row, col;
    Matrix(int r,int c){
        row=r, col=c;
        mat= vector<vector<ll> >(r,vector<ll>(c));
    }
 
    static Matrix identity_matrix(int n){
        Matrix res(n,n);
        for(int i = 0; i < n; i++) res.mat[i][i] = 1;
        return res;
    }
 
    Matrix operator*(const Matrix &other) const{
        int n = row, m = other.col;
        Matrix res(n,m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                for(int k = 0; k < col; k++)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
        }
        return res;
    }
    inline bool is_square() const {return row == col;}
};
 
Matrix mat_expo(Matrix m, int power)
{
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.row);
 
    while(power)
    {
        if(power & 1) result = result * m;
        m = m * m;
        power >>= 1;
    }
    return result;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int x,y,n,m;
        cin>>x>>y>>n>>m;
        int temp[][2] ={
            {1,1},
            {1,0}
        };
 
        Matrix A(2,2);
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++) A.mat[i][j]= temp[i][j];
 
        MOD=mod[m];
        A = mat_expo(A,n-1);
        int res = (A.mat[0][0]*y + A.mat[1][0]*x)%MOD;
        cout<<"Case "<<cas++<<": "<< res <<endl;
    }
    return 0;
}
/*sample
 
*/
