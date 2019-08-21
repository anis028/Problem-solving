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
 
struct data
{
    int l_id, r_id, l_cnt, r_cnt, mx_cnt;
    data() {}
    data(int a, int b, int c, int d, int e):
        l_id(a), l_cnt(b), r_id(c), r_cnt(d), mx_cnt(e) {}
} tree[400000];
 
data marge(data &l, data &r)
{
    data ret;
    ret.l_id = l.l_id;
    ret.r_id = r.r_id;
    ret.l_cnt = l.l_cnt;
    ret.r_cnt = r.r_cnt;
    ret.mx_cnt = max(l.mx_cnt,r.mx_cnt);
    if(l.l_id == r.l_id) ret.l_cnt += r.l_cnt;
    if(l.r_id == r.r_id) ret.r_cnt += l.r_cnt;
    if(l.r_id == r.l_id) ret.mx_cnt = max(ret.mx_cnt,l.r_cnt+r.l_cnt);
    return ret;
}
 
void build(int node,int s,int f)
{
    if(s==f){
        int x;
        scanf("%d",&x);
        tree[node] = data(x,1,x,1,1);
        return;
    }
    int mid=(s+f)/2, lc=node*2, rc=lc+1;
    build(lc,s,mid);
    build(rc,mid+1,f);
    tree[node] = marge(tree[lc],tree[rc]);
//    data &ret=tree[node], l=tree[lc], r=tree[rc];
//    ret.l_id = l.l_id;
//    ret.r_id = r.r_id;
//    ret.l_cnt = l.l_cnt;
//    ret.r_cnt = r.r_cnt;
//    ret.mx_cnt = max(l.mx_cnt,r.mx_cnt);
//    if(l.l_id == r.l_id) ret.l_cnt += r.l_cnt;
//    if(l.r_id == r.r_id) ret.r_cnt += l.r_cnt;
//    if(l.r_id == r.l_id) ret.mx_cnt = max(ret.mx_cnt,l.r_cnt+r.l_cnt);
}
 
data query(int node,int s,int f,int i,int j)
{
    if(s>j || f<i) return data(0,0,0,0,0);
    if(s>=i and f<=j) return tree[node];
    int mid=(s+f)/2, lc=node*2, rc=lc+1;
    data l, r, ret;
    l = query(lc,s,mid,i,j);
    r = query(rc,mid+1,f,i,j);
    return ret = marge(l,r);
//    ret.l_id = l.l_id;
//    ret.r_id = r.r_id;
//    ret.l_cnt = l.l_cnt;
//    ret.r_cnt = r.r_cnt;
//    ret.mx_cnt = max(l.mx_cnt,r.mx_cnt);
//    if(l.l_id == r.l_id) ret.l_cnt += r.l_cnt;
//    if(l.r_id == r.r_id) ret.r_cnt += l.r_cnt;
//    if(l.r_id == r.l_id) ret.mx_cnt = max(ret.mx_cnt,l.r_cnt+r.l_cnt);
//    return ret;
}
 
int main()
{
    int tc=1,cas=1;
    scanf("%d",&tc);
    while(tc--){
        int n,m,q;
        scanf("%d %d %d",&n,&m,&q);
        build(1,1,n);
 
        printf("Case %d:\n",cas++);
        int l, r;
        while(q--){
            scanf("%d %d",&l,&r);
            printf("%d\n",query(1,1,n,l,r).mx_cnt);
        }
    }
    return 0;
}
/*sample
 
*/
