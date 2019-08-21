#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
 
using namespace std;
 
long long int tree[300009],lazy[300009];
 
void update(int node,int s,int f,int x,int y,int v)
{
    //cout<<s<<" "<<f<<endl;
    int l=node*2,r=l+1;
    if(s>=x and f<=y) lazy[node]+=v;
    if(lazy[node]!=0)
    {
        if(s!=f)
        {
            lazy[node*2]=lazy[node*2]+lazy[node];
            lazy[node*2+1]=lazy[node*2+1]+lazy[node];
        }
        tree[node]+=(f-s+1)*lazy[node];
        lazy[node]=0;
    }
    if(s>=x and f<=y) return;
    if(s>y or f<x) return;
    int md=(s+f)/2;
    update(l,s,md,x,y,v);
    update(r,md+1,f,x,y,v);
    tree[node]=tree[l]+tree[r];
}
 
long long int query(int node,int s,int f,int x,int y)
{
    //cout<<s<<" "<<f<<"a"<<x<<" "<<y<<endl;
    if(lazy[node]!=0)
    {
        if(s!=f)
        {
            lazy[node*2]=lazy[node*2]+lazy[node];
            lazy[node*2+1]=lazy[node*2+1]+lazy[node];
        }
        tree[node]+=(f-s+1)*lazy[node];
        lazy[node]=0;
    }
    if(f<=y and s>=x) return tree[node];
    if(s>y or f<x) return 0;
    int l=node*2,r=l+1,md=(s+f)/2;
    return query(l,s,md,x,y)+query(r,md+1,f,x,y);
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        printf("Case %d:\n",p++);
        mm(tree,0);
        mm(lazy,0);
        int n,q;
        scanf("%d %d",&n,&q);
        while(q--)
        {
            int ins,x,y,v;
            scanf("%d",&ins);
            if(ins==0)
            {
                scanf("%d %d %d",&x,&y,&v);
                update(1,1,n,x+1,y+1,v);
            }
            else
            {
                scanf("%d %d",&x,&y);
                printf("%lld\n",query(1,1,n,x+1,y+1));
            }
        }
    }
    return 0;
}
/*sample
 
*/
