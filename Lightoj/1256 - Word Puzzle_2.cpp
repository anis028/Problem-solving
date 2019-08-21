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
#define   fs            first
#define   sc            second
 
using namespace std;
 
int g[26][26],col[26],in[26],out[26],u,v;
char word[1005][26];
vector<int>windex[26][26],path;
vector<pii>edge[26];
 
 
 
void init()
{
    memset(g,0,sizeof g);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)windex[i][j].clear();
        col[i]=2;
        edge[i].clear();
    }
    path.clear();
}
 
bool isconnected()
{
    int i,j;
    queue<int>q;
    for(i=0;col[i];i++); col[i]=1;
    q.push(i);
    while(!q.empty())
    {
        i=q.front();
        for(j=0;j<26;j++)
        {
            if((g[i][j]||g[j][i]) && !col[j])
            {
                q.push(j);
                col[j]=1;
            }
        }
        q.pop();
        col[i]=2;
    }
    for(i=0;i<26;i++) if(col[i]!=2) return false;
    return true;
}
 
bool has_eulerpath()
{
    if(!isconnected()) return false;
    int i,cnt1=0,cnt2=0;
    for(int i=0;i<26;i++)
    {
        if(in[i]-out[i]==1) cnt1++;
        else if(out[i]-in[i]==1) cnt2++;
        else if(in[i]!=out[i]) return false;
    }
    if(cnt1+cnt2==0||(cnt1==1 && cnt2==1)) return true;
    return false;
}
 
void findcycle(int u)
{
    for(int i=0;i<edge[u].size();i++)
    {
        if(edge[u][i].second!=0)
        {
            edge[u][i].second=0;
            findcycle(edge[u][i].first);
        }
    }
    path.pb(u);
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        init();
        int n,l;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",word[i]);
            l=strlen(word[i]);
            in[u=word[i][0]-'a']++;
            out[v=word[i][l-1]-'a']++;
            g[u][v]=1;
            col[u]=col[v]=0;
            windex[u][v].pb(i);
            edge[u].pb({v,1});
        }
        if(has_eulerpath())
        {
            int i,j,first=0;
            for(i=0;i<26;i++) if(in[i]>out[i]) break;
            if(i==26) for(i=0; !in[i] ;i++);
            findcycle(i);
            j=path.back();
            printf("Case %d: Yes\n",p++);
            for(i=path.size()-2;i>=0;i--)
            {
                if(first) printf(" ");
                printf("%s",word[windex[j][path[i]].back()]);
                windex[j][path[i]].pop_back();
                j=path[i];
                first=1;
            }
            printf("\n");
        }
        else printf("Case %d: No\n",p++);
    }
    return 0;
}
/*sample
 
*/
