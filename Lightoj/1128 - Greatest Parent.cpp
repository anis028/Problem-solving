#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
#define   fs            first
#define   sc            second
 
using namespace std;
 
int par[100005][20],val[100005],lev[100005];
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    val[0]=1,lev[0]=0;
    while(tc--)
    {
        int n,q,u,x;
        mm(par,-1);
        scanf("%d %d",&n,&q);
        for(int i=1;i<n;i++){
            scanf("%d %d",&par[i][0],&val[i]);
            lev[i]=lev[par[i][0]]+1;
        }
        for(int j=1;(1<<j)<n;j++)
        {
            for(int i=1;i<n;i++)
                if(par[i][j-1]!=-1)
                    par[i][j]=par[par[i][j-1]][j-1];
        }
 
        // for(int i=0;i<n;i++)
        // {
        //  printf("%d:",i);
        //  for(int j=0;(1<<j)<n;j++) printf(" %d",par[i][j]);
        //  printf("\n");
        // }
        printf("Case %d:\n",cas++);
        int l;
        while(q--)
        {
            scanf("%d %d",&u,&x);
            l=log2(lev[u]);
            // cout<<l<<" "<<u<<" "<<x<<" "<<lev[u]<<endl;
            for(int i=l;i>=0;i--){
                // cout<<i<<" "<<u<<" "<<par[u][i]<<" "<<cas<<" "<<val[par[u][i]]<<endl;
                if(lev[u]-(1<<i)>=0 and val[par[u][i]]>=x)
                    u=par[u][i];
            }
            printf("%d\n",u);
        }
    }
    return 0;
}
/*sample
 
*/
