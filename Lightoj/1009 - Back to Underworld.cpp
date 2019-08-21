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
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d %d",&x,&y)
#define sf3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define pii pair<int,int>
#define mm(x,y) memset(x,y,sizeof(x))
 
using namespace std;
int main()
{
    int tc,p=1;
    sf1(tc);
    while(tc--)
    {
        vector<int>v[20005];
        int black=0,white=0,ans=0,col[20005],fight,now,mx;
        mm(col,0);
        sf1(fight);
        loop(i,0,fight)
        {
            int x,y;
            sf2(x,y);
            v[x].pb(y);
            v[y].pb(x);
            if(max(x,y)>mx)mx=max(x,y);
        }
        queue <int> q;
        for(int j=0; j<=mx; j++)
        {
            if(v[j].size()==0)continue;
            if(col[v[j][0]]==0)
            {
                black=0;
                white=0;
                q.push(v[j][0]);
                col[v[j][0]]=1;
                black++;
                while(!q.empty())
                {
                    now=q.front();
                    for(int i=0; i<v[now].size(); i++)
                    {
                        if(col[v[now][i]]==0)
                        {
                            q.push(v[now][i]);
                            if(col[now]==1)
                            {
                                col[v[now][i]]=2;
                                white++;
                            }
                            else
                            {
                                col[v[now][i]]=1;
                                black++;
                            }
                        }
                    }
                    q.pop();
                }
                ans+=max(black,white);
            }
        }
        printf("Case %d: %d\n",p++,ans);
    }
    return 0;
}
