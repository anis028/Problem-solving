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
int prime[]= {2,3,5,7,11,13,17,19,23,29,31,37},lvisit[12],lev[2000];
vector<int>v[1005];
int main()
{
    int tc,strt,fin,now,p=1;
    loop(i,2,1005)
    {
        int z=i;
        int j=0;
 
        for(int j=0; prime[j]<=sqrt(z); j++)
        {
            if(z%prime[j]==0)
            {
                v[i].pb(prime[j]);
 
                while(z%prime[j]==0) z/=prime[j];
            }
        }
        if(z!=1 and z!=i)v[i].pb(z);
    }
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&strt,&fin);
        if(fin==strt)
        {
            printf("Case %d: 0\n",p++);
            continue;
        }
        if(fin<strt)
        {
            printf("Case %d: -1\n",p++);
            continue;
        }
 
        mm(lev,-1);
        mm(lvisit,-1);
 
        int ans=0;
 
        queue<int>q;
        q.push(strt);
        lev[strt]=0;
        lvisit[0]=0;
        while(!q.empty())
        {
            now=q.front();
            if(ans!=0 or (lvisit[now[lev]]==-1 && now>fin))
                break;
 
            lvisit[lev[now]]=0;
 
            for(int i=0; i<v[now].size(); i++)
            {
                if(lev[now+v[now][i]]==-1 && now+v[now][i]<=fin)
                {
                    q.push(now+v[now][i]);
 
                    lev[now+v[now][i]]=lev[now]+1;
 
                    if(now+v[now][i]==fin)
                    {
                        ans=lev[fin];
                    }
                }
            }
            q.pop();
        }
        if(ans==0) printf("Case %d: -1\n",p++);
 
        else printf("Case %d: %d\n",p++,ans);
    }
    return 0;
}
