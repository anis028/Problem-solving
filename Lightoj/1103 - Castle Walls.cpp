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
 
int tree[800007];
 
vector<pii>inp;
 
int query(int node,int s,int f,int ind)
{
    if(f<ind) return 0;
    if(s>=ind) return tree[node];
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    return query(lc,s,mid,ind) + query(rc,mid+1,f,ind);
}
 
void update(int node,int s,int f,int ind)
{
    if(s==f) {tree[node]++; return;}
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    if(ind>mid) update(rc,mid+1,f,ind);
    else update(lc,s,mid,ind);
    tree[node]=tree[lc]+tree[rc];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        mm(tree,0);
        inp.clear();
        int n,m,x,y;
        cin>>n>>m;
        for(int i=1;i<=n+m;i++){
            cin>>x>>y;
            inp.pb({x,y});
        }
        sort(inp.begin(),inp.end());
        ll ans=0;
        for(int i=0;i<n+m;i++){
            ans+=(ll)query(1,1,n+m,inp[i].sc);
            update(1,1,n+m,inp[i].sc);
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
