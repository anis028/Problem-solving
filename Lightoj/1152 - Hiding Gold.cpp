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
 
int ro,co,l[405],r[405],vis[405],blue[25][25];
char ara[25][25];
vector<int> g[405];
 
bool bpm(int u)
{
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(vis[v]) continue;
        vis[v]=1;
        if(r[v]==-1 || bpm(r[v]))
        {
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
    for(int i=0; i<ro; i++)
        for(int j=0;j<co;j++){
            if(blue[i][j] and ara[i][j]=='*'){
                mm(vis,0);
                if(bpm(i*co+j)) ans++;
            }
        }
    return ans;
}
 
void dfs(int i,int j,int c)
{
    blue[i][j]=c;
    if(i+1<ro and blue[i+1][j]==-1) dfs(i+1,j,1^c);
    if(j+1<co and blue[i][j+1]==-1) dfs(i,j+1,1^c);
    if(i-1>-1 and blue[i-1][j]==-1) dfs(i-1,j,1^c);
    if(j-1>-1 and blue[i][j-1]==-1) dfs(i,j-1,1^c);
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int cnt=0;
        for(int i=0;i<405;i++) g[i].clear();
        scanf("%d %d",&ro,&co);
        getchar();
        for(int i=0; i<ro; i++)
        {
            for(int j=0; j<co; j++)
            {
                scanf("%c",&ara[i][j]);
                if(ara[i][j]=='*') cnt++;
            }
            getchar();
        }
        mm(blue,-1);
        dfs(0,0,1);
        for(int i=0;i<ro;i++){
            for(int j=0;j<co;j++){
                if(blue[i][j] and ara[i][j]=='*'){
                    if(i+1<ro and ara[i+1][j]=='*'){
                        g[(i*co)+j].pb(((i+1)*co)+j);
                    }
                    if(j+1<co and ara[i][j+1]=='*'){
                        g[(i*co)+j].pb((i*co)+j+1);
                    }
                    if(i-1>-1 and ara[i-1][j]=='*'){
                        g[(i*co)+j].pb(((i-1)*co)+j);
                    }
                    if(j-1>-1 and ara[i][j-1]=='*'){
                        g[(i*co)+j].pb((i*co)+j-1);
                    }
                }
            }
        }
        printf("Case %d: %d\n",cas++,cnt-match());
    }
    return 0;
}
/*sample
5 8
oo**oooo
*oo*ooo*
******oo
*o*oo*oo
******oo
 
3 4
**oo
**oo
*oo*
*/
