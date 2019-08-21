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
string start,finish;
int n,ans;
map<string,int>m,dist,visited;
void bfs()
{
    queue<string>q;
    q.push(start);
    dist[start]=0;
    visited[start]=1;
    while(!q.empty())
    {
        string a=q.front(),b;
        if(a==finish){ans=1;break;}
        for(int i=0; i<3; i++)
        {
            b=a;
            if(a[i]=='a')b[i]='z';
            else b[i]--;
            if(visited[b]==0 && m[b]==0)
            {
                //cout<<b<<" 1we "<<endl;
                visited[b]=1;
                dist[b]=dist[a]+1;
                q.push(b);
            }
        }
        for(int i=0; i<3; i++)
        {
            b=a;
            if(a[i]=='z')b[i]='a';
            else b[i]++;
            if(visited[b]==0 && m[b]==0)
            {
                //cout<<b<<" 2we "<<endl;
                visited[b]=1;
                dist[b]=dist[a]+1;
                q.push(b);
            }
        }
        q.pop();
    }
}
int main()
{
    //freopen("a.txt","r",stdin);
    //freopen ("b.txt","w",stdout);
    int tc,p=1;
    scanf("%d",&tc);
    getchar();
    getchar();
    while(tc--)
    {
        visited.clear();
        m.clear();
        dist.clear();
        cin>>start;
        cin>>finish;
        scanf("%d",&n);
        getchar();
        loop(i,0,n)
        {
            string a,b,c,forbid="";
            cin>>a>>b>>c;
            //cout<<a<<" "<<b<<" "<<c<<endl;
            loop(j,0,a.size())
            {
                loop(k,0,b.size())
                {
                    loop(l,0,c.size())
                    {
                        forbid+=a[j];
                        forbid+=b[k];
                        forbid+=c[l];
                        m[forbid]=1;
                        //cout<<forbid <<" as "<<endl;
                        forbid="";
                    }
                }
            }
        }
        if(m[start]==1 || m[finish]==1)
        {
            cout<<"Case "<<p++<<": -1"<<endl;
            continue;
        }
        visited.clear();
        ans=0;
        bfs();
        if(ans==0) cout<<"Case "<<p++<<": -1"<<endl;
        else cout<<"Case "<<p++<<": "<<dist[finish]<<endl;
        m.clear();
        dist.clear();
    }
    return 0;
}
