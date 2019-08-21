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
#define fs first
#define sc second
 
 
using namespace std;
 
int dx[]= {1,1,2,2,-1,-1,-2,-2};
int dy[]= {2,-2,1,-1,2,-2,1,-1},row,col;
bool visited[15][15];
 
inline bool isokay(int x,int y)
{
    if(x<0 or x>=row or y<0 or y>=col or visited[x][y])
        return false;
    visited[x][y]=true;
    return true;
}
 
char grid[12][12];
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n=0,ans[15][15],x=1000000;
        memset(ans,0,sizeof(ans));
        scanf("%d %d",&row,&col);
        for(int i=0; i<row; i++)
        {
            getchar();
            for(int j=0; j<col; j++)
            {
                scanf("%c",&grid[i][j]);
                if(grid[i][j]!='.') n++;
            }
        }
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]!='.')
                {
                    int k=grid[i][j]-'0',level[15][15];
                    memset(visited,false,sizeof(visited));
                    memset(level,-1,sizeof(level));
                    queue<pair<int,int> >q;
                    q.push(pii(i,j));
                    level[i][j]=0;
                    visited[i][j]=true;
                    while(!q.empty())
                    {
                        pii cur=q.front();
                        q.pop();
                        for(int p=0; p<8; p++)
                        {
                            pii pos= pii(cur.fs+dx[p],cur.sc+dy[p]);
                            if(isokay(pos.fs,pos.sc))
                            {
                                level[pos.fs][pos.sc]=level[cur.fs][cur.sc]+1;
                                q.push(pos);
                            }
                        }
                    }
                    for(int y=0; y<row; y++)
                    {
                        for(int u=0; u<col; u++)
                            if(ans[y][u]==-1 or level[y][u]==-1)
                                ans[y][u]=-1;
                            else ans[y][u]+=ceil((level[y][u]*1.0)/(k*1.0));
                    }
                }
            }
        }
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                if(ans[i][j]!=-1) x=min(x,ans[i][j]);
        }
        printf("Case %d: ",cas++);
        if(x!=1000000) printf("%d\n",x);
        else printf("-1\n");
    }
    return 0;
}
/*sample
 
*/
