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
#define imx 2147483647
 
using namespace std;
int tree[300009];
void build_segtree(int node, int beg,int fin)
{
    if(beg==fin)
    {
//        tree[node]=ara[beg];
        scanf("%d",&tree[node]);
        return;
    }
    build_segtree(node<<1,beg,(beg+fin)>>1);
    build_segtree((node<<1)+1,((beg+fin)>>1)+1,fin);
    tree[node]=min(tree[(node<<1)+1],tree[node<<1]);
    return;
}
int khujo(int node,int beg,int fin,int i,int j)
{
    if(fin<i || beg>j) return imx;
    if(beg>=i && fin<=j) return tree[node];
    int p1=khujo((node<<1)+1,((beg+fin)>>1)+1,fin,i,j);
    int p2=khujo(node<<1,beg,(beg+fin)>>1,i,j);
    return min(p1,p2);
}
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,query;
        scanf("%d %d",&n,&query);
//        for(int i=1; i<=n; i++) scanf("%d",&ara[i]);
        build_segtree(1,1,n);
//        for(int i=0;i<=20;i++) printf(" %d",tree[i]);
        printf("Case %d:\n",p++);
        for(int i=0; i<query; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            int ans= khujo(1,1,n,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
