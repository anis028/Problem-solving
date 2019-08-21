#include<bits/stdc++.h>
 
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   md            1000000007
#define   fs            first
#define   sc            second
 
using namespace std;
 
int josephus(int n,int k)
{
    if(n==1) return 0;
    return (josephus(n-1,k)+k)%n;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        printf("Case %d: %d\n",cas++,josephus(n,k)+1);
    }
    return 0;
}
/*sample
   
*/
