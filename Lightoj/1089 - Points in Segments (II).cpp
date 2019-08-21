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
 
int tree[600000];
vector<pii>seg;
vector<int>p,all;
unordered_map<int,int>mp;
 
void update(int node,int s,int f,int i,int j)
{
//    cout<<s<<" : "<<f<<endl;
    if(s>j || f<i) return;
    if(s>=i and f<=j) {tree[node]++;return;}
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    update(lc,s,mid,i,j);
    update(rc,mid+1,f,i,j);
}
 
void build(int node,int s,int f)
{
    if(s==f) return;
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    tree[lc]+=tree[node], tree[rc]+=tree[node];
    build(lc,s,mid);
    build(rc,mid+1,f);
}
 
int query(int node,int s,int f,int ind)
{
    if(s==f) return tree[node];
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    if(ind>mid) return query(rc,mid+1,f,ind);
    return query(lc,s,mid,ind);
}
 
int main()
{
    int tc=1,cas=1;
    scanf("%d",&tc);
    while(tc--){
        mm(tree,0);
        seg.clear(), p.clear(), all.clear(), mp.clear();
        int n,q,l,r;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++){
            scanf("%d %d",&l,&r);
            seg.pb({l,r});
            all.pb(l),all.pb(r);
        }
        for(int i=0;i<q;i++){
            scanf("%d",&l);
            p.pb(l);
            all.pb(l);
        }
        sort(all.begin(),all.end());
        int ind=1;
        for(int i=0;i<all.size();i++){
            if(mp[all[i]]==0) mp[all[i]]=ind++;
//            cout<<all[i]<<" _ "<<mp[all[i]]<<endl;
        }
        for(int i=0;i<n;i++){
//            cout<<mp[seg[i].fs]<<" "<<mp[seg[i].sc]<<endl;
            update(1,1,ind,mp[seg[i].fs],mp[seg[i].sc]);
        }
        build(1,1,ind);
        printf("Case %d:\n",cas++);
        for(int i=0;i<q;i++)
            printf("%d\n",query(1,1,ind,mp[p[i]]));
    }
    return 0;
}
/*sample
 
*/
 
 

