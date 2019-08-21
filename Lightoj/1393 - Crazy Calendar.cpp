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
 
using namespace std;
 
int main()
{
    int tc,p=1;
    cin>>tc;
    while(tc--)
    {
        int n,m,ans=0,x;
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&x);
                if((n-i+m-j-2)&1) ans^=x;
            }
        }
        cout<<"Case "<<p++<<": ";
        if(ans) cout<<"win"<<endl;
        else cout<<"lose"<<endl;
    }
    return 0;
}
/*sample
 
*/
