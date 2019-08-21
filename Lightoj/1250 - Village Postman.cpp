#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long
#define DB double
 
using namespace std;
const int N = 209;
const int M = 1009;
const int INF = 0x3f3f3f3f;
int n,m;
int re[N],flag[N];
int ans;
int path[M],cnt;
int in[N];
struct LT{
    int to,nex;
} L[M<<1];
int F[N],C=2;
int v[M];
void add(int f,int t){
    L[C].nex = F[f];L[C].to = t;
    F[f] = C++;
}
void dfs(int k){
    for(int i=F[k];i;i=L[i].nex){
        if(v[i>>1]) continue;
        int to = L[i].to;
        v [i >> 1 ] = 1 ;
        dfs(to);
    }
    path[cnt++] = k;
}
void solve(int T)
{
    ans =0;
    int gesi=1;
    cnt = 0;
    in[1]--;
    dfs(1);
 
    for(int i=0;i<cnt;i++)
    {
        if(flag[path[i]]==0)
        {
            flag[path[i]]=1;
            ans+=(re[path[i]]-gesi);
            gesi++;
        }
    }
    ans-=m;
    printf("Case %d: %d\n",T,ans);
    for(int i=0;i<cnt;i++)
    {
        if(i) printf(" ");printf("%d",path[i]);
    }puts("");
}
int main()
{
//    #ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
//    #endif
    int cas,T=1;scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        ans =0;cnt = 0;C=2;
        memset(in,0,sizeof(in));
        memset(F,0,sizeof(F));
        memset(v,0,sizeof(v));
        memset(flag,0,sizeof flag);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&re[i]);
        }
        int a,b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);add(b,a);
            in[a]++;in[b]++;
        }
        solve(T);T++;
    }
    return 0;
}
