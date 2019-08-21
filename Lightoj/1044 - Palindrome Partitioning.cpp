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
    int tc,k=1;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        string s;
        cin>>s;
        int l=s.length();
        int p[l+5][l+5];
        for(int i=0;i<=l+2;i++)
            for(int j=0;j<=l+2;j++) p[i][j]=0;
 
        for(int j=1;j<=l;j++)
        {
            for(int i=1;i<=j;i++)
            {
                if(i==j) p[i][j]=1;
                else if(s[i-1]==s[j-1])
                {
                    if(j-i==1) p[i][j]=1;
                    else p[i][j]=p[i+1][j-1];
                }
            }
        }
 
        int ans[l+5];
        for(int i=0;i<=l;i++) ans[i]=INT_MAX;
        ans[l+1]=0;
        for(int i=l;i>0;i--)
            for(int j=i;j<=l;j++)
                if(p[i][j])
                    ans[i]=min(ans[i],1+ans[j+1]);
 
        printf("Case %d: %d\n",k++,ans[1]);
    }
    return 0;
}
/*sample
 
*/
