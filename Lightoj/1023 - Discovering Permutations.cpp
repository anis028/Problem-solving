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
vector<char>ans;
int n,k,cnt,flag[30];
 
void rec()
{
    if(cnt==k) return;
    if(ans.size()==n)
    {
        for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
        printf("\n");
        cnt++;
        return;
    }
 
    for(int i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            ans.push_back('A'+i);
            flag[i]=1;
            rec();
            if(cnt==k) return;
            flag[ans[ans.size()-1]-'A']=0;
            ans.pop_back();
        }
    }
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&k);
        ans.clear();
        printf("Case %d:\n",cas++);
        cnt=0;
        mm(flag,0);
        rec();
    }
    return 0;
}
/*sample
   
*/
