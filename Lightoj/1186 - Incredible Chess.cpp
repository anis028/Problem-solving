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
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int ans=0,x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            ans^=(x-a[i]-1);
        }
        cout<<"Case "<<p++<<": ";
        if(ans) cout<<"white wins"<<endl;
        else cout<<"black wins"<<endl;
    }
    return 0;
}
/*sample
 
*/
