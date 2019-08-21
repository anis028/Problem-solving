#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define rep(i,n) for(i = 0; i < n; i++)
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
int dx[]= {0,0,0,1,1,1,-1,-1,-1};
int dy[]= {-1,0,1,-1,0,1,-1,0,1};
string dirC[9]= {"L","*","R","DL","D","DR","UL","U","UR"};
vector <string>  res;
int R,C,len;
bool yes[30];
string grid[30],inp;
bool ok(int x,int y)
{
    if(x<0 || x>=R || y<0 || y>=C)
        return false;
    return true;
}
bool dfs(int idx,int x,int y)
{
    if(idx==len)
        return true;
 
    int i;
    for(i=0; i<9; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(ok(nx,ny))
        {
            char cur=grid[nx][ny];
            if(cur==inp[idx] &&  dfs(idx+1,nx,ny))
            {
 
                res.pb(dirC[i]);
                return true;
            }
        }
    }
    return false;
}
 
int main()
{
 
    int cs,t;
    cin>>t;
    rep(cs,t)
    {
        scanf("%d %d",&R,&C);
        int i,k,j,sz,m,x,y;
        mm(yes,0);
        for(i=0; i<R; i++)
        {
            cin>>grid[i];
            for(j=0; j<C; j++)
                yes[grid[i][j]-'A']=1;
        }
        scanf("%d",&m);
        printf("Case %d:\n",cs+1);
        rep(k,m)
        {
            bool flag=false;
            cin>>inp;
            len=inp.size();
            for(i=0; i<len; i++)
                if(!yes[inp[i]-'A'])
                {
                    flag=true;
                    break;
                }
            if(flag)
            {
                cout<<inp<<" not found"<<endl;
                continue;
            }
            bool br=false;
            for(i=0; i<R  && !br ; i++)
            {
 
                for(j=0; j<C; j++)
                {
                    if(grid[i][j]==inp[0])
                    {
                        res.clear();
 
                        if(dfs(1,i,j))
                        {
                            flag=true;
                            br=true;
                            x=i+1;
                            y=j+1;
 
                            break;
                        }
                    }
                }
            }
            if(flag)
            {
                cout<<inp<<" found: ("<<x<<","<<y<<")";
                for(i=res.size()-1; i>=0; i--)
                    cout<<", "<<res[i];
                cout<<endl;
            }
            else
                cout<<inp<<" not found"<<endl;
 
        }
    }
    return 0;
}
/*sample
 
*/

