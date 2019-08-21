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
 
int n,dp[(1<<16)+5];
vector<pii>v;
 
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
int check(int N,int pos){return (bool)(N & (1<<pos));}
 
 
int solve(int mask)
{
    if(mask==(1<<n)-1) return 0;
    int &ret=dp[mask];
    if(ret!=-1) return ret;
    ret=1<<30;
    for(int i=0;i<n;i++)
    {
        if(!check(mask,i))
        {
            int temp=Set(mask,i);
            ret=min(ret,solve(temp)+1);
            for(int j=i+1;j<n;j++)
            {
                temp=Set(mask,i);
                if(!check(temp,j))
                {
                    temp=Set(temp,j);
                    for(int k=j+1;k<n;k++)
                    {
                        if(!check(temp,k))
                            if((v[i].sc-v[k].sc)*(v[i].fs-v[j].fs)==(v[i].sc-v[j].sc)*(v[i].fs-v[k].fs))
                                temp=Set(temp,k);
                    }
                    ret=min(ret,solve(temp)+1);
                }
            }
            break;
        }
    }
    return ret;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        int x,y;
        v.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            v.pb({x,y});
        }
        mm(dp,-1);
        printf("Case %d: %d\n",cas++,solve(0));
    }
    return 0;
}
/*sample
   
*/
