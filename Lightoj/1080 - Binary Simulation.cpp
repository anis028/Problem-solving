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
char a[100005];
int ans,tree[300005];
void update(int node,int beg,int nd,int start,int fin)
{
    if(tree[node]!=0 && beg!=nd)
    {
        tree[node*2]=tree[node*2]+tree[node];
        tree[node*2+1]=tree[node*2+1]+tree[node];
        tree[node]=0;
    }
    if(beg>fin || nd<start) return;
    if(beg>=start && nd<=fin)
    {
        tree[node]=tree[node]+1;
        return;
    }
    //cout<<beg<<" "<<nd<<" "<<tree[node]<<endl;
    int mid=(beg+nd)/2,lson=node*2,rson=node*2+1;
    update(lson,beg,mid,start,fin);
    update(rson,mid+1,nd,start,fin);
}
 
void query(int node,int beg,int nd,int jao)
{
    //cout<<beg<<" "<<nd<<" "<<tree[node]<<endl;
    if(beg==nd && beg==jao) {ans=tree[node];return;}
    else if(beg==nd) return;
    if(tree[node]!=0 && beg!=nd)
    {
        tree[node*2+1]=tree[node*2+1]+tree[node];
        tree[node*2]=tree[node*2]+tree[node];
        tree[node]=0;
    }
    if(beg>jao||nd<jao) return;
    int mid=(beg+nd)/2,lson=node*2,rson=node*2+1;
    query(lson,beg,mid,jao);
    query(rson,mid+1,nd,jao);
}
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        mm(tree,0);
        printf("Case %d:\n",p++);
        string s;
        gets(a);
        int q,l;
        l=strlen(a);
        scanf("%d",&q);
        getchar();
        while(q--)
        {
            int x,y;
            char ch;
            scanf("%c",&ch);
            if(ch=='I')
            {
                scanf("%d %d",&x,&y);
                getchar();
                update(1,1,l,x,y);
            }
            if(ch=='Q')
            {
                scanf("%d",&x);
                getchar();
                query(1,1,l,x);
                //cout<<a[jao-1]<<" "<<ans<<endl;
                printf("%d\n",(a[x-1]-'0'+ans)%2);
            }
        }
    }
    return 0;
}
