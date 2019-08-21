#include<bits/stdc++.h>
 
using namespace std;
int m,n,cnt;
char a[25][25];
void dfs(int i,int j)
{
    a[i][j]='*';
    cnt++;
    if(i+1<m && a[i+1][j]=='.') dfs(i+1,j);
    if(j+1<n && a[i][j+1]=='.') dfs(i,j+1);
    if(j-1>=0 && a[i][j-1]=='.') dfs(i,j-1);
    if(i-1>=0 && a[i-1][j]=='.') dfs(i-1,j);
}
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int x,y;
        cnt=0;
        scanf("%d %d ",&n,&m);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%c",&a[i][j]);
                if(a[i][j]=='@'){
                    x=i;y=j;
                }
            }
            getchar();
        }
        dfs(x,y);
        cout<<"Case "<<p++<<": "<<cnt<<endl;
    }
    return 0;
}
