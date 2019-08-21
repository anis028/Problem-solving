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
 
int tree[400000];
 
void build(int node,int s,int f)
{
    if(s==f){ tree[node]=1;return;}
    int mid=(s+f)/2,lc=node<<1,rc=lc|1;
    build(lc,s,mid);
    build(rc,mid+1,f);
    tree[node]= tree[lc]+tree[rc];
}
 
void update(int node,int s,int f,int ind,bool print)
{
    if(s==f){
        tree[node]=0;
        if(print) cout<<s<<endl;
        return;
    }
    int mid=(s+f)/2,lc=node<<1,rc=lc|1;
    if(ind>tree[lc]) update(rc,mid+1,f,ind-tree[lc],print);
    else update(lc,s,mid,ind,print);
    tree[node]=tree[lc]+tree[rc];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int ara[n+2];
        for(int i=1;i<=n;i++) cin>>ara[i];
        build(1,1,n);
        cout<<"Case "<<cas++<<": ";
        for(int i=n;i>0;i--)
            update(1,1,n,i-ara[i],i==1);
    }
    return 0;
}
/*sample
 
*/
 
 
