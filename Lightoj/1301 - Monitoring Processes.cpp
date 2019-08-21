#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   m0d           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
int tree[300005];
vector<pair<int,int> > process;
vector<int> v;
map<int,int> mp;
 
void clr()
{
    mm(tree,0);
    process.clear();
    v.clear();
    mp.clear();
}
 
bool cmp(pii a,pii b)
{
    return a.sc<b.sc;
}
 
void update(int node,int s,int f,int in,int val)
{
    if(s>in || f<in) return;
    if(s==f) {tree[node]+=val;return;}
    int mid=(s+f)/2,lc=node<<1,rc=lc+1;
    update(lc,s,mid,in,val);
    update(rc,mid+1,f,in,val);
    tree[node]=tree[lc]+tree[rc];
//    cout<<s<<" - "<<f<<": "<<tree[node]<<endl;
}
 
int query(int node,int s,int f,int l,int r)
{
    if(s>r || f<l) return 0;
    if(s>=l and f<=r) return tree[node];
    int mid=(s+f)/2,lc=node<<1,rc=lc+1;
    return query(lc,s,mid,l,r) + query(rc,mid+1,f,l,r);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        clr();
        int n,x,y;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            process.pb({x,y});
            v.pb(x);
            v.pb(y);
        }
        sort(v.begin(),v.end());
        x=1;
        for(int i=0;i<v.size();i++){
            if(mp[v[i]]==0) mp[v[i]]=x++;
//            cout<<v[i]<<"a"<<mp[v[i]]<<endl;
        }
        sort(process.begin(),process.end(),cmp);
        for(int i=0;i<n;i++){
//            cout<<mp[process[i].fs]<<endl;
            update(1,1,x,mp[process[i].fs],1);
        }
//        cout<<query(1,1,x,1,n)<<"ase"<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
//            cout<<mp[process[i].sc]<<"b"<<query(1,1,n,1,mp[process[i].sc])<<endl;
            ans=max(ans,query(1,1,x,1,mp[process[i].sc]));
            update(1,1,x,mp[process[i].fs],-1);
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
