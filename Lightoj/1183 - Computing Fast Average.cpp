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
int n,q,tree[300009],lazy[300009],ins,i,j,v;
 
void update(int node,int s,int f,int v)
{
    int l=node*2,r=l+1,md=(s+f)/2;
    if(s>=i and f<=j) lazy[node]=v;
    if(lazy[node]!=-1)
    {
        if(s!=f)
        {
            lazy[l]=lazy[node];
            lazy[r]=lazy[node];
        }
        tree[node]=(f-s+1)*lazy[node];
        lazy[node]=-1;
    }
 
    if(s>=i and f<=j) return;
    if(s>j or f<i) return;
 
    update(l,s,md,v);
    update(r,md+1,f,v);
    tree[node]=tree[l]+tree[r];
}
 
int query(int node,int s,int f)
{
    int l=node*2,r=l+1,md=(s+f)/2;
    if(lazy[node]!=-1)
    {
        if(s!=f)
        {
            lazy[l]=lazy[node];
            lazy[r]=lazy[node];
        }
        tree[node]=(f-s+1)*lazy[node];
        lazy[node]=-1;
    }
 
    if(s>=i and f<=j)return tree[node];
    if(s>j or f<i) return 0;
 
    return query(l,s,md)+query(r,md+1,f);
}
 
int gcd(int x,int y)
{
    if(x%y==0) return y;
    return gcd(y,x%y);
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        mm(tree,0);
        mm(lazy,-1);
        printf("Case %d:\n",p++);
        scanf("%d %d",&n,&q);
        while(q--)
        {
            scanf("%d %d %d",&ins,&i,&j);
            i++;
            j++;
            if(ins==1)
            {
                scanf("%d",&v);
                update(1,1,n,v);
            }
            else
            {
                int x=query(1,1,n),y=j-i+1,g;
                if(x==0) printf("0");
                else
                {
                    if(x<y) g=gcd(y,x);
                    else g=gcd(x,y);
                    printf("%d",x/g);
                    if(g!=y) printf("/%d",y/g);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
/*sample
 
*/
