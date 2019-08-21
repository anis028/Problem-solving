#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
 
long long ncr[1001][1001],fact[1001];
 
int main()
{
    int tc,cas=1;
    fact[0]=ncr[0][0]=1;
    for(int i=1;i<1001;i++)
    {
        fact[i]=(i*fact[i-1])%md;
        ncr[i][0]=ncr[i][i]=1;
    }
    for(int i=2;i<1001;i++)
        for(int j=1;j<i;j++) ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%md;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        long long res=0;
        for(int i=0;i<=m-k;i++)
        {
            if(i&1) res=(((res-ncr[m-k][i]*fact[n-k-i])%md)+md)%md;
            else res=(res+(ncr[m-k][i]*fact[n-k-i]))%md;
        }
        res=(res*ncr[m][k])%md;
        //if(res<0) res+=md;
        printf("Case %d: %lld\n",cas++,res);
    }
    return 0;
}
/*sample
 
*/
