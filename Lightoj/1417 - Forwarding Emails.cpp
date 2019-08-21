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
int visited[50005],email[50005],cmpo;
stack<int>s;
void dfs(int u)
{
    visited[u]=1;
    if(visited[email[u]]==-1) dfs(email[u]);
    s.push(u);
}
int Dfs(int u)
{
    visited[u]=1;
    cmpo++;
    if(visited[email[u]]==-1) Dfs(email[u]);
    return cmpo;
}
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int people,u,v,cnt=0,ans;
        scanf("%d",&people);
        for(int i=0; i<people; i++)
        {
            scanf("%d %d",&u,&v);
            email[u]=v;
        }
        mm(visited,-1);
        for(int i=1; i<=people; i++) if(visited[i]==-1) dfs(i);
        mm(visited,-1);
        while(!s.empty())
        {
            int i=s.top();
            s.pop();
            cmpo=0;
            if(visited[i]==-1)
            {
                mm(visited,-1);
                int cmp=Dfs(i);
                if(cnt<cmp)
                {
                    cnt=cmp;
                    ans=i;
                }
                else if(cnt==cmp) if(i<ans)ans=i;
            }
        }
        printf("Case %d: %d\n",p++,ans);
    }
    return 0;
}

