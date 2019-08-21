#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#define db(x) printf("**%d\n",x)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define pii pair<int,int>
#define mm(x,y) memset(x,y,sizeof(x))
 
using namespace std;
int ans[505][505],row,col,n,cnt,dirx[]={0,1,0,-1},diry[]={1,0,-1,0};
char grid[505][505];
queue<pii>q;
bool visited[505][505];
void dfs(int x,int y)
{
    if(grid[x][y]=='C')cnt++;
    grid[x][y]='#';
    for(int i=0;i<4;i++)
    {
        int a=x+dirx[i];
        int b=y+diry[i];
        if(a>-1 && b>-1 && a<row && b<col && grid[a][b]!='#')
        {
            q.push(pii(a,b));
            dfs(a,b);
        }
    }
}
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d ",&row,&col,&n);
        loop(i,0,row)gets(grid[i]);
        mm(visited,false);
        loop(i,0,row)
        {
            loop(j,0,col)
            {
                if(grid[i][j]=='.'||grid[i][j]=='C')
                {
                    cnt=0;
                    q.push(pii(i,j));
                    dfs(i,j);
                    while(!q.empty())
                    {
                        pii u=q.front();
                        ans[u.first][u.second]=cnt;
                        q.pop();
                    }
                }
            }
        }
        printf("Case %d:\n",p++);
        int x,y;
        loop(i,0,n)
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",ans[x-1][y-1]);
        }
    }
    return 0;
}

