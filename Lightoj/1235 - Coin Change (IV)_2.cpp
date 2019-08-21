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
#define   fs            first
#define   sc            second
 
using namespace std;
 
vector<int>lt,rt;
int a[20];
 
inline void generate(int sum, int b,int e,vector<int>&v)
{
    if(b==e) {v.push_back(sum);return;}
    generate(sum,b+1,e,v);
    generate(sum+a[b],b+1,e,v);
    generate(sum+2*a[b],b+1,e,v);
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,k,i;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int mid=n>>1;
        lt.clear();
        rt.clear();
        generate(0,0,mid,lt);
        generate(0,mid,n,rt);
        sort(lt.begin(),lt.end());
        for(i=0;i<rt.size();i++)
        {
            if(k>=rt[i])
                if(*lower_bound(lt.begin(),lt.end(),k-rt[i])==k-rt[i]) break;
        }
        printf("Case %d: ",cas++);
        if(i==rt.size()) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
/*sample
   
*/
