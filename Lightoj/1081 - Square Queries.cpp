#include<bits/stdc++.h>
 
using namespace std;
 
int sparse[505][505][10];
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,s,q,x,y,a,ans;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&sparse[i][j][0]);
        for(int k=1;(1<<k)-1<=n;k++)
            for(int i=0;i+(1<<k)-1<n;i++)
                for(int j=0;j+(1<<k)-1<n;j++)
                {
                    a=1<<(k-1);
                    sparse[i][j][k]=max(max(sparse[i][j][k-1],sparse[i+a][j][k-1]),max(sparse[i][j+a][k-1],sparse[i+a][j+a][k-1]));
                }
        printf("Case %d:\n",cas++);
        while(q--)
        {
            scanf("%d %d %d",&x,&y,&s);
            x--,y--;
            int k=log2(s);
            a=1<<k;
            ans=max(max(sparse[x][y][k],sparse[x+s-a][y][k]),max(sparse[x][y+s-a][k],sparse[x+s-a][y+s-a][k]));
            printf("%d\n",ans);
        }
    }
    return 0;
}
 

