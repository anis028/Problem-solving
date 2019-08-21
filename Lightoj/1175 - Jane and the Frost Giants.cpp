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
#define fs first
#define sc second
 
using namespace std;
int t[205][205],dx[]= {1,0,0,-1},dy[]= {0,1,-1,0},row,col,ans;
char grid[205][205];
void bfs(int r , int c)
{
    queue<pii>q;
    q.push(pii(r,c));
    t[r][c]=0;
    while(!q.empty())
    {
        if(ans==0 && (q.front().fs==1 || q.front().fs==row||q.front().sc==1||q.front().sc==col))
        {
            ans=t[q.front().fs][q.front().sc]+1;
            break;
        }
        for(int i=0; i<4; i++)
        {
            int x=q.front().fs+dx[i];
            int y=q.front().sc+dy[i];
            if(x>0 && x<row+1 && y>0 && y<col+1 && grid[x][y]!='#')
            {
                if(t[x][y]>t[q.front().fs][q.front().sc]+1)
                {
                    t[x][y]=t[q.front().fs][q.front().sc]+1;
                    q.push(pii(x,y));
                }
            }
        }
        q.pop();
    }
}
int main()
{
    int tc,p=1,x,y;
    scanf("%d",&tc);
    while(tc--)
    {
        vector<pii>v;
        scanf("%d %d",&row,&col);
        getchar();
        loop(i,1,row+1)
        {
            loop(j,1,col+1)
            {
                t[i][j]=50000;
                scanf("%c",&grid[i][j]);
                if(grid[i][j]=='J')
                {
                    x=i;
                    y=j;
                }
                else if(grid[i][j]=='F') v.pb(pii(i,j));
            }
            getchar();
        }
        ans=1;
        loop(i,0,v.size()) bfs(v[i].first,v[i].second);
        ans=0;
        bfs(x,y);
        if(ans==0)printf("Case %d: IMPOSSIBLE\n",p++);
        else printf("Case %d: %d\n",p++,ans);
    }
    return 0;
}
