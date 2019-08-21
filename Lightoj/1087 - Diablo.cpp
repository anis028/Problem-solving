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
vector<int>v;
 
void update(int node,int s,int f,int ind,int val)
{
    if(s==f){
        if(s==ind) tree[node]+=val;
        return;
    }
    if(s>ind || f<ind) return;
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    update(lc,s,mid,ind,val);
    update(rc,mid+1,f,ind,val);
    tree[node] = tree[lc] + tree[rc];
//    cout<<s<<"_"<<f<<":"<<tree[node]<<endl;
}
 
void query(int node,int s,int f,int val)
{
//    cout<<s<<" _ "<<f<<endl;
    if(s==f){
        printf("%d\n",v[s-1]);
        update(1,1,150001,s,-1);
        return;
    }
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    if(val>tree[lc]) query(rc,mid+1,f,val-tree[lc]);
    else query(lc,s,mid,val);
}
 
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--){
        mm(tree,0);
        v.clear();
        int n,q,x;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) update(1,1,150001,i,1);
        for(int i=0;i<n;i++) scanf("%d",&x), v.pb(x);
        printf("Case %d:\n",cas++);
        while(q--){
            char c;
            getchar();
            scanf("%c %d",&c,&x);
            if(c=='a') v.pb(x),update(1,1,150001,v.size(),1);
            else{
                if(tree[1]<x) printf("none\n");
                else query(1,1,150001,x);
            }
        }
    }
    return 0;
}
/*sample
 
*/
