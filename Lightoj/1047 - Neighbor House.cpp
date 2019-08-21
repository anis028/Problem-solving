#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        int a[n][3];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
        }
        for(int i=n-2;i>-1;i--)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0) a[i][j]+=min(a[i+1][1],a[i+1][2]);
                else if(j==1) a[i][j]+=min(a[i+1][0],a[i+1][2]);
                else if(j==2) a[i][j]+=min(a[i+1][1],a[i+1][0]);
            }
        }
        printf("Case %d: %d\n",p++,min(a[0][0],min(a[0][1],a[0][2])));
    }
    return 0;
}
