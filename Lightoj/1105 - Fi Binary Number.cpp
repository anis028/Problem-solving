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
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    ll f[45];
    f[1]=1,f[2]=2;
    for(int i=3;i<45;i++) f[i]=f[i-1]+f[i-2];
    while(tc--){
        int n;
        scanf("%d",&n);
        printf("Case %d: ",cas++);
        int i=44;
        while(n<f[i]) i--;
        while(i>0){
            if(n>=f[i]) n-=f[i],printf("1");
            else printf("0");
            i--;
        }
        printf("\n");
    }
    return 0;
}
/*sample
 
*/
