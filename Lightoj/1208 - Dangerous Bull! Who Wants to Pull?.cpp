#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   ff            first
#define   ss            second
using namespace std;
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 128;
const double BIG = 1e12;
template< class T > T sq(T x) { return x * x; }
 
typedef pair< int, int > point;
typedef struct { point u, v; double d; } segment;
 
segment s[MAX];
map< point, vector< int > > M;
double mat[MAX][MAX];
 
inline double dist(const point &a, const point &b) {
    return sqrt((double)sq(a.ff - b.ff) + (double)sq(a.ss - b.ss));
}
 
inline bool isleft(const point &a, const point &b, const point &c) {
    return (b.ff - a.ff) * (c.ss - a.ss) - (b.ss - a.ss) * (c.ff - a.ff) >= 0;
}
 
int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int test, cs, n, i, j, k, u, v;
    point bull;
    double ans;
    scanf("%d", &test);
    for(cs = 1; cs <= test; cs++) {
        scanf("%d %d %d", &n, &bull.ff, &bull.ss);
        M.clear();
        for(i = 0; i < n; i++) {
            scanf("%d %d %d %d", &s[i].u.ff, &s[i].u.ss, &s[i].v.ff, &s[i].v.ss);
            if(!isleft(s[i].u, s[i].v, bull)) swap(s[i].u, s[i].v);
            s[i].d = dist(s[i].u, s[i].v);
            M[s[i].u].pb(i);
        }
        for(i = 0; i < n; i++) for(j = 0; j < n; j++) mat[i][j] = BIG;
        for(u = 0; u < n; u++) {
            for(j = 0; j < M[s[u].v].size(); j++) {
                v = M[s[u].v][j];
                if(isleft(s[u].u, s[u].v, s[v].v)) mat[u][v] = s[u].d + s[v].d;
            }
        }
        for(k = 0; k < n; k++)
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        ans = BIG;
        for(i = 0; i < n; i++) ans = min(ans, mat[i][i]);
        if(fabs(ans - BIG) < EPS) printf("Case %d: %.8lf\n", cs, -1.0);
        else printf("Case %d: %.8lf\n", cs, ans + EPS);
    }
    return 0;
}
/*sample
 
*/
