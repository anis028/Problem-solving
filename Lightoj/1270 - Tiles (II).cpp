#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
 
int row,col,vis[102][(1<<8)+5],cas;
ull dp[102][(1<<8)+5];
char grid[102][102],inp[102][102];
ull rec(int,int);
ull gen(int r,int c,int cur,int nxt)
{
    if(c==col) return rec(r+1,nxt);
    int cur_c=(cur>>c) & 1;
    int cur_nc=(cur>>(c+1)) & 1;
    int nxt_c=(nxt>>c)&1;
    int nxt_nc=(nxt>>(c+1))&1;
    int nxt_pc=(nxt>>max(0,c-1))&1;
    if(cur_c || grid[r][c]=='#') return gen(r,c+1,cur,nxt);
    ull ret=0;
 
    if(r+1<row) //tile 1
        if(grid[r+1][c]=='.' and !nxt_c)
            ret += gen(r,c+1,cur|(1<<c),nxt|(1<<c));
 
    if(c+1<col) //tile 2
        if(grid[r][c+1]=='.' and !cur_nc)
            ret += gen(r,c+2,cur|(1<<c)|(1<<(c+1)),nxt);
 
    if(r+1<row and c-1>=0) //tile 5
        if(grid[r+1][c]=='.' and grid[r+1][c-1]=='.' and !nxt_pc and !nxt_c)
            ret += gen(r,c+1,cur|(1<<c),nxt|(1<<c)|(1<<(c-1)));
 
    if(r+1 <row and c+1<col){
        //tile 4
        if(grid[r][c+1]=='.' and grid[r+1][c]=='.' and !cur_nc and !nxt_c)
            ret += gen(r,c+1,cur|(1<<c)|(1<<(c+1)),nxt|(1<<c));
        //tile 6
        if(grid[r][c+1]=='.' and grid[r+1][c+1]=='.' and !cur_nc and !nxt_nc)
            ret += gen(r,c+1,cur|(1<<c)|(1<<(c+1)),nxt|(1<<(c+1)));
        //tile 3
        if(grid[r+1][c]=='.' and grid[r+1][c+1]=='.' and !nxt_c and !nxt_nc)
            ret += gen(r,c+1,cur|(1<<c),nxt|(1<<c)|(1<<(c+1)));
    }
    return ret;
}
 
ull rec(int r,int mask)
{
    if(r==row) return mask==0;
    ull &ret=dp[r][mask];
    if(vis[r][mask]==cas) return ret;
    vis[r][mask]=cas;
    ret=gen(r,0,mask,0);
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        cas++;
        cin>>row>>col;
        for(int i=0;i<row;i++) cin>>inp[i];
        if(col>row){
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++) grid[j][i]=inp[i][j];
            swap(row,col);
        }
        else
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++) grid[i][j]=inp[i][j];
        printf("Case %d: %llu\n",cas,rec(0,0));
    }
    return 0;
}
/*sample
 
*/

