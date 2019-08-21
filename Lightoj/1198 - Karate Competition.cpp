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
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,ans=0,j=0,last;
        scanf("%d",&n);
        int a[n+2],b[n+2],flag1[n+2],flag2[n+2];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        mm(flag1,0);
        mm(flag2,0);
        for(int i=0;i<n;i++)
        {
            j=0;
            last=-1;
            while(j<n)
            {
                if(flag2[j]==1)
                {
                    j++;
                    continue;
                }
//                cout<<a[i]<<" "<<b[j]<<endl;
                if(a[i]<=b[j]) break;
                last=j;
                j++;
            }
            if(last==-1) continue;
            flag1[i]=1;
            flag2[last]=1;
            ans+=2;
        }
//      cout<<ans<<endl;
        for(int i=0;i<n;i++)
        {
            j=0;
            last=-1;
            if(flag1[i]==1) continue;
            while(j<n)
            {
                if(flag2[j]==1){ j++;continue;}
                if(a[i]==b[j]){last=j; break;}
                j++;
            }
            if(j>=n and last==-1) continue;
            flag2[last]=1;
            ans++;
            j++;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
