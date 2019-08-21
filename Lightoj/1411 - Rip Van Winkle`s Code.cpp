///http://lbv-pc.blogspot.com/2012/11/rip-van-winkles-code.html
 
#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define   inf           (1ll<<60)
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
struct node_{
    ll sum, a_cnt, b_cnt, dis_a, dis_b, val;
} tree[250010*4];
 
void init(){
    for(int i=1;i<=4*250010 -4;i++)
        tree[i].a_cnt = tree[i].b_cnt = tree[i].sum = tree[i].dis_a = tree[i].dis_b = 0, tree[i].val = inf;
}
 
ll change_val;
 
ll cal(ll tot, ll ele, ll cnt)
{
    tot = 2*tot + (ele - 1)*cnt;
    tot = ele * tot / 2ll;
    return tot;
}
 
void push_down(int node,int l,int r)
{
    int lc = node<<1, rc = lc|1, mid=(l+r)>>1;
    if(tree[node].val!=inf){
        tree[lc].sum = (mid - l +1) * tree[node].val;
        tree[rc].sum = (r-mid) * tree[node].val;
 
        tree[lc].val = tree[rc].val = tree[node].val;
        tree[lc].a_cnt = tree[lc].b_cnt = tree[lc].dis_a = tree[lc].dis_b = 0;
        tree[rc].a_cnt = tree[rc].b_cnt = tree[rc].dis_a = tree[rc].dis_b = 0;
        tree[node].val = inf;
    }
    if(tree[node].dis_a){
        tree[lc].dis_a += tree[node].dis_a;
        tree[rc].dis_a += tree[node].dis_a + (mid-l+1)*tree[node].a_cnt;
 
        tree[lc].sum += cal(tree[node].dis_a, mid-l+1, tree[node].a_cnt);
        tree[rc].sum += cal(tree[node].dis_a + (mid-l+1)*tree[node].a_cnt, r-mid, tree[node].a_cnt);
 
        tree[lc].a_cnt += tree[node].a_cnt;
        tree[rc].a_cnt += tree[node].a_cnt;
 
        tree[node].a_cnt = tree[node].dis_a = 0;
    }
    if(tree[node].dis_b){
        tree[rc].dis_b += tree[node].dis_b;
        tree[lc].dis_b += tree[node].dis_b + (r-mid)*tree[node].b_cnt;
 
        tree[rc].sum += cal(tree[node].dis_b, r-mid, tree[node].b_cnt);
        tree[lc].sum += cal(tree[node].dis_b + (r-mid)*tree[node].b_cnt, mid-l+1, tree[node].b_cnt);
 
        tree[lc].b_cnt += tree[node].b_cnt;
        tree[rc].b_cnt += tree[node].b_cnt;
 
        tree[node].b_cnt = tree[node].dis_b = 0;
    }
}
 
void update(int node,int s,int f,int q_l,int q_r,int typ)
{
    if(s>q_r || f<q_l) return;
    if(s>=q_l and f<=q_r){
        if(typ==1){
            tree[node].a_cnt++;
            tree[node].dis_a += (s-q_l+1);
            tree[node].sum += cal(s-q_l+1, f-s+1, 1);
        }
        else if(typ==2){
            tree[node].b_cnt++;
            tree[node].dis_b += (q_r-f+1);
            tree[node].sum += cal(q_r-f+1, f-s+1, 1);
        }
        else{
            tree[node].val = change_val;
            tree[node].sum = change_val * (ll)(f-s+1);
            tree[node].a_cnt = tree[node].b_cnt = tree[node].dis_a = tree[node].dis_b = 0;
        }
        return;
    }
    push_down(node,s,f);
    int mid=(s+f)>>1,lc=node<<1,rc=lc|1;
    update(lc,s,mid,q_l,q_r,typ);
    update(rc,mid+1,f,q_l,q_r,typ);
    tree[node].sum = tree[lc].sum + tree[rc].sum;
}
 
ll query(int node,int s,int f,int q_l,int q_r)
{
    if(s>q_r || f<q_l) return 0;
    if(s>=q_l and f<=q_r) return tree[node].sum;
 
    push_down(node,s,f);
    int mid=(s+f)>>1,lc=node<<1,rc=lc|1;
    return query(lc,s,mid,q_l,q_r) + query(rc,mid+1,f,q_l,q_r);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        init();
        int q,l,r;
        cin>>q;
        cout<<"Case "<<cas++<<":"<<endl;
        char c;
        while(q--){
            cin>>c>>l>>r;
            if(c=='C'){
                cin>>change_val;
                update(1,1,250000,l,r,3);
            }
            else if(c=='A') update(1,1,250000,l,r,1);
            else if(c=='B') update(1,1,250000,l,r,2);
            else cout<<query(1,1,250000,l,r)<<endl;
        }
    }
    return 0;
}
/*sample
 
*/
