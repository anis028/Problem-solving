#include<bits/stdc++.h>
#include<cstddef>
 
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
        unsigned long long x,y;
        cin>>x;
        cout<<"Case "<<p++<<": ";
        if(x&1)
        {
            printf("Impossible\n");
            continue;
        }
        bitset<66>b((x));
        for(size_t i=0;i<66;i++)
        {
            if(b.test(i))
            {
                y=1<<i;
                cout<<x/y<<" "<<y<<endl;
                break;
            }
        }
    }
    return 0;
}
/*sample
 
*/
 
