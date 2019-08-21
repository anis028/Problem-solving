#include<bits/stdc++.h>
 
using namespace std;
struct data{
    int mx,mn;
}tree[300005];
 
void build_stree(int node,int s,int f)
{
    if(s==f)
    {
        scanf("%d",&tree[node].mx);
        tree[node].mn=tree[node].mx;
        return;
    }
    int mid=(s+f)/2;
    int left=node*2;
    int right=node*2+1;
    build_stree(left,s,mid);
    build_stree(right,mid+1,f);
    tree[node].mn=min(tree[left].mn,tree[right].mn);
    tree[node].mx=max(tree[left].mx,tree[right].mx);
}
 
data query(int node,int s,int f,int i,int j)
{
    if(s>=i && f<=j) return tree[node];
    if(s>j || f<i)
    {
        data pre;
        pre.mx=0;
        pre.mn=INT_MAX;
        return pre;
    }
    int mid=(s+f)/2;
    int left=node*2,right=left+1;;
    data x=query(left,s,mid,i,j);
    data y=query(right,mid+1,f,i,j);
    int mx=0,mn=INT_MAX;
    data ret;
    ret.mx=max(mx,max(x.mx,y.mx));
    ret.mn=min(mn,min(x.mn,y.mn));
    return ret;
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,d,ans=0;
        scanf("%d %d",&n,&d);
        build_stree(1,1,n);
        for(int i=1;i+d-1<=n;i++)
        {
            data x=query(1,1,n,i,i+d-1);
            ans=max((x.mx-x.mn),ans);
        }
        printf("Case %d: %d\n",p++,ans);
    }
}
