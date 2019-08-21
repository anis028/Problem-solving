#include<bits/stdc++.h>
 
#define   inputneo      freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
    scanf("%d",&tc);
    while(tc--)
    {
        int num,x;
        scanf("%d %d",&num,&x);
        int ans[5000],ind=0;
        num-=x;
        int sq=sqrt(num);
        for(int i=1; i<=sq; i++)
        {
            if(num%i==0)
            {
                if(i>x)
                {
                    ans[ind]=i;
                    ind++;
                }
                if(num/i!=i)
                {
                    if(num/i>x)
                    {
                        ans[ind]=(num/i);
                        ind++;
                    }
                }
            }
        }
        printf("Case %d:",p++);
        if(ind==0) printf(" impossible\n");
        else
        {
            sort(ans,ans+ind);
            for(int i=0; i<ind; i++) printf(" %d",ans[i]);
            printf("\n");
        }
 
    }
    return 0;
}
/*sample
 
*/
