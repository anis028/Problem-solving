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
 
using namespace std;
int tree[300009],ans;
void build(int node,int b,int e)
{
    //cout<<b<<" "<<e<<endl;
    if(b==e)
    {
        scanf("%d",&tree[node]);
        //cout<<b<<" "<<tree[node]<<endl;
        return;
    }
    int mid=(b+e)/2,l=node*2,r=node*2+1;
    build(l,b,mid);
    build(r,mid+1,e);
    tree[node]=tree[l]+tree[r];
}
int query(int node,int b,int e,int start,int fin)
{
    if(b>fin ||e<start) return 0;
    if(b>=start && e<=fin) return tree[node];
    int mid=(b+e)/2,l=node*2,r=node*2+1;
    int x=query(l,b,mid,start,fin);
    int y=query(r,mid+1,e,start,fin);
    return x+y;
}
void update(int node,int b,int e,int in,int add,int ins)
{
    if(b==e && b==in)
    {
        if(ins==2) tree[node]+=add;
        else
        {
            printf("%d\n",tree[node]);
            tree[node]=0;
        }
        return;
    }
    if(b>in||e<in) return;
    int mid=(b+e)/2,l=node*2,r=node*2+1;
    update(l,b,mid,in,add,ins);
    update(r,mid+1,e,in,add,ins);
    tree[node]= tree[l]+tree[r];
}
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        printf("Case %d:\n",p++);
        int n,q;
        scanf("%d %d",&n,&q);
        build(1,1,n);
        while(q--)
        {
            int ins;
            scanf("%d",&ins);
            if(ins==1)
            {
                int s;
                scanf("%d",&s);
                update(1,1,n,s+1,s+1,1);
            }
            else if(ins==2)
            {
                int in,add;
                scanf("%d %d",&in,&add);
                update(1,1,n,in+1,add,2);
            }
            else if(ins==3)
            {
                int x,y;
                scanf("%d %d",&x,&y);
                printf("%d\n",query(1,1,n,x+1,y+1));
            }
        }
    }
    return 0;
}
/*sample
 
*/
