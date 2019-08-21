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
int i,j,ins,lazy[300005];
struct data{
    int one,two,three;
}tree[300005];
 
void build(int node,int s,int f)
{
    if(s==f)
    {
        tree[node].one=0;
        tree[node].two=0;
        tree[node].three=1;
        return;
    }
    int l=node*2,r=l+1,md=(s+f)/2;
    build(l,s,md);
    build(r,md+1,f);
    tree[node].three=tree[l].three+tree[r].three;
    tree[node].one=tree[l].one+tree[r].one;
    tree[node].two=tree[l].two+tree[r].two;
}
 
void update(int node,int s,int f)
{
    int l=node*2,r=l+1,md=(s+f)/2,temp;
    if(s>=i and f<=j)lazy[node]++;
    if(lazy[node]!=0)
    {
        if(s!=f)
        {
            lazy[l]+=lazy[node];
            lazy[r]+=lazy[node];
        }
        if(lazy[node]%3==1)
        {
            temp=tree[node].one;
            tree[node].one=tree[node].three;
            tree[node].three=tree[node].two;
            tree[node].two=temp;
        }
        else if(lazy[node]%3==2)
        {
            temp=tree[node].one;
            tree[node].one=tree[node].two;
            tree[node].two=tree[node].three;
            tree[node].three=temp;
        }
        lazy[node]=0;
    }
    if(s>=i and f<=j) return;
    if(s>j or f<i) return;
    update(l,s,md);
    update(r,md+1,f);
    tree[node].one=tree[l].one+tree[r].one;
    tree[node].two=tree[l].two+tree[r].two;
    tree[node].three=tree[l].three+tree[r].three;
}
 
int query(int node,int s,int f)
{
    int l=node*2,r=l+1,md=(s+f)/2,temp;
    if(lazy[node]!=0)
    {
        if(s!=f)
        {
            lazy[l]+=lazy[node];
            lazy[r]+=lazy[node];
        }
        if(lazy[node]%3==1)
        {
            temp=tree[node].one;
            tree[node].one=tree[node].three;
            tree[node].three=tree[node].two;
            tree[node].two=temp;
        }
        else if(lazy[node]%3==2)
        {
            temp=tree[node].one;
            tree[node].one=tree[node].two;
            tree[node].two=tree[node].three;
            tree[node].three=temp;
        }
        lazy[node]=0;
    }
    if(s>=i and f<=j) return tree[node].three;
    if(s>j or f<i) return 0;
    return query(l,s,md)+query(r,md+1,f);
}
 
int main()
{
    int tc,p=1,n,q;
    scanf("%d",&tc);
    while(tc--)
    {
        printf("Case %d:\n",p++);
        mm(lazy,0);
        scanf("%d %d",&n,&q);
        build(1,1,n);
        while(q--)
        {
            scanf("%d %d %d",&ins,&i,&j);
            i++;j++;
            if(ins) printf("%d\n",query(1,1,n));
            else update(1,1,n);
        }
    }
    return 0;
}
/*sample
 
*/
