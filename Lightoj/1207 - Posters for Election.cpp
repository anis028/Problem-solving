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
 
int tree[600005];
set <int> st;
void update(int node,int s,int f,int i,int j,int poster)
{
    if(tree[node]!=-1 && s!=f)
    {
        tree[node*2]=tree[node];
        tree[node*2+1]=tree[node];
        tree[node]=-1;
    }
    if(s>j || f<i) return;
    else if(s>=i && f<=j)
    {
        tree[node]=poster;
        return;
    }
    int mid=(s+f)/2;
    int left=node*2,right=left+1;
    update(left,s,mid,i,j,poster);
    update(right,mid+1,f,i,j,poster);
 
 
}
void query(int node,int s, int f)
{
    //cout<<s<<" "<<f<<" "<<tree[node]<<" "<<node<<endl;
    if(s==f)
    {
        //cout<<s<<" "<<tree[node]<<endl;
        if(tree[node]!=-1)
        {
            //cout<<s<<" "<<tree[node]<<endl;
            st.insert(tree[node]);
        }
        return;
    }
    if(tree[node]!=-1)
    {
        tree[node*2]=tree[node];
        tree[node*2+1]=tree[node];
        tree[node]=-1;
    }
    int mid=(s+f)/2;
    int rson=node*2+1,lson=node*2;
    query(lson,s,mid);
    query(rson,mid+1,f);
    return;
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,mx=0;
        mm(tree,-1);
        scanf("%d",&n);
        st.clear();
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            mx=max(mx,y);
            update(1,1,200000,x,y,i);
        }
        query(1,1,200000);
        printf("Case %d: %d\n",p++,st.size());
    }
    return 0;
}
