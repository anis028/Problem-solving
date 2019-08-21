#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
using namespace std;
typedef long long ll;
typedef double dbl;
 
int lastpos[100005],ara[100005],tree[400005];
vector<pii> query[100005];
int ans [50005];
 
void update(int node,int s,int f,int ind,int val)
{
    if(s==f){
        tree[node]+=val;
        return;
    }
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    if(ind<=mid) update(lc,s,mid,ind,val);
    else update(rc,mid+1,f,ind,val);
    tree[node]=tree[lc]+tree[rc];
//    cout<<s<<" "<<f<<": "<<tree[node]<<endl;
}
 
int ask(int node,int s,int f,int i,int j)
{
    if(s>j || f<i) return 0;
    if(s>=i and f<=j) return tree[node];
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    int ret=0;
    ret+=ask(lc,s,mid,i,j);
    ret+=ask(rc,mid+1,f,i,j);
    return ret;
}
 
int main()
{
    int tc=1,cas=1;
    scanf("%d",&tc);
    while(tc--){
 
        mm(tree,0);
        mm(lastpos,0);
        for(int i=1;i<=100000;i++) query[i].clear();
 
        int n,q,l,r;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&ara[i]);
        for(int i=0;i<q;i++){
            scanf("%d %d",&l,&r);
            query[r].pb({l,i});
        }
        for(int i=1;i<=n;i++){
            int val = ara[i];
//            cout<<val<<" "<<lastpos[val]<<endl;
            if(lastpos[val]) {update(1,1,n,lastpos[val],-1);}
            update(1,1,n,i,1);
            lastpos[val]=i;
            for(int j=0;j<query[i].size();j++)
                ans[query[i][j].sc]=ask(1,1,n,query[i][j].fs,i);
        }
        printf("Case %d:\n",cas++);
        for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
/*sample
 
*/
 
