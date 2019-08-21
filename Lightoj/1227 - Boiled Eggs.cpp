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
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        int n,p,q;
        cin>>n>>p>>q;
        int a[n+1];
        for(int i=0; i<n; i++) cin>> a[i];
        sort(a,a+n);
        cout<<"Case "<<cas++<<": ";
        int sum=0,cnt=0;
        while(p-- and cnt!=n)
        {
            if(sum+a[cnt]>q) break;
            sum+=a[cnt];
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
/*sample
 
*/
