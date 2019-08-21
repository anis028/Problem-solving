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
 
int x,y,l[55],r[55],vis[55];
vector<int>g[55];
 
struct person{
    int age,h,d;
}m[55],f[55];
 
bool bpm(int u)
{
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]) continue;
        vis[v]=1;
        if(r[v]==-1 || bpm(r[v])){
            r[v]=u;
            l[u]=v;
            return true;
        }
    }
    return false;
}
 
int match()
{
    mm(l,-1);
    mm(r,-1);
    int ans=0;
    for(int i=0;i<x;i++){
        mm(vis,0);
        if(bpm(i)) ans++;
    }
    return ans;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0;i<50;i++) g[i].clear();
        scanf("%d %d",&x,&y);
        for(int i=0;i<x;i++) scanf("%d %d %d",&m[i].h,&m[i].age,&m[i].d);
        for(int i=0;i<y;i++) scanf("%d %d %d",&f[i].h,&f[i].age,&f[i].d);
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(m[i].d==f[j].d)
                    if(abs(m[i].age-f[j].age)<6)
                        if(abs(m[i].h-f[j].h)<13)
                            g[i].pb(j);
            }
        }
        printf("Case %d: %d\n",cas++,match());
    }
    return 0;
}
/*sample
 
*/
