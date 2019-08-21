#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   mod            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
 
using namespace std;
 
int tree[300005],indx;
 
void update(int node,int s,int f,int in,int x)
{
    if(s>in or f<in) return;
    if(s>=in and f<=in)
    {
        tree[node]=x;
        return;
    }
    int l=node*2,r=l+1,md=(s+f)/2;
    update(l,s,md,in,x);
    update(r,md+1,f,in,x);
    tree[node]=(tree[l]+tree[r])%mod;
}
 
int query(int node,int s,int f,int i,int j)
{
    if(s>j or f<i) return 0;
    if(s>=i and f<=j) return tree[node];
    int l=node*2,r=l+1,md=(s+f)/2;
    return (query(l,s,md,i,j)+query(r,md+1,f,i,j))%mod;
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,x;
        mm(tree,0);
        scanf("%d",&n);
        vector<pair<int,int> >v;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            v.pb({x,i});
        }
        sort(v.begin(),v.end());
        int age=v[0].first;
        queue<pair<int,int> >q;
        for(int i=0; i<v.size(); i++)
        {
            int indx=v[i].second;
 
            if(v[i].first!=age)
                while(!q.empty())
                {
                    update(1,1,n,q.front().second,q.front().first);
                    q.pop();
                }
            q.push({query(1,1,n,1,indx-1)+1,indx});
            age=v[i].first;
            //cout<<v[i].second<<" "<<ans<<endl;
        }
        while(!q.empty())
        {
            update(1,1,n,q.front().second,q.front().first);
            q.pop();
        }
        printf("Case %d: %d\n",p++,query(1,1,n,1,n));
    }
    return 0;
}
/*sample
 
*/
