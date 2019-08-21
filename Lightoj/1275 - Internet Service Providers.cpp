#include<bits/stdc++.h>
 
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   md            1000000007
#define   fs            first
#define   sc            second
 
using namespace std;
 
int fun(int t,int n, int c)
{
    return t*(c-t*n);
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,k,t;
        scanf("%d %d",&n,&k);
        printf("Case %d: ",cas++);
        if(n==0) printf("0\n");
        else
        {
            t=k/(n*2);
            if(fun(t,n,k)<fun(t+1,n,k)) t++;
            printf("%d\n",t);
        }
    }
    return 0;
}
/*sample
 
*/
