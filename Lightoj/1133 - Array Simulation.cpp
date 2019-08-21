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
        int n,q,x,y;
        cin>>n>>q;
        vector<int>v;
        char ch;
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
        }
        while(q--)
        {
            cin>>ch;
            if(ch=='P')
            {
                cin>>x>>y;
                swap(v[x],v[y]);
            }
            else if(ch=='S')
            {
                cin>>x;
                for(int i=0;i<n;i++)
                    v[i]+=x;
            }
            else if(ch=='M')
            {
                cin>>x;
                for(int i=0;i<n;i++)
                    v[i]*=x;
            }
            else if(ch=='D')
            {
                cin>>x;
                for(int i=0;i<n;i++)
                    v[i]/=x;
            }
            else if(ch=='R')
                reverse(v.begin(),v.end());
        }
        printf("Case %d:\n",p++);
        printf("%d",v[0]);
        for(int i=1;i<n;i++)
            printf(" %d",v[i]);
        printf("\n");
    }
    return 0;
}
/*sample
 
*/
