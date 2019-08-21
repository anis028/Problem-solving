#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mod           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
 
using namespace std;
typedef long long ll;
typedef double dbl;
 
int Rank[18][10005],step,n,lcp[10005],p,q;
string str;
 
struct info{
    int prev,now,ind;
    bool operator < (const info &a)const{
        return prev != a.prev ? prev < a.prev : now < a.now;
    }
}ara[10005];
 
void build_suffix_array()
{
    int jump=1;
    for(int i = 0; i < n; i ++) Rank[0][i] = str[i] - 'a';
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1 ){
        for(int i = 0; i < n; i ++){
            ara[i].ind = i;
            ara[i].prev = Rank[step-1][i];
            ara[i].now = i+jump < n? Rank[step-1][i+jump] : -1;
        }
        sort(ara,ara+n);
        Rank[step][ara[0].ind] = 0;
        for(int i = 1; i < n; i++)
            Rank[step][ara[i].ind] = ara[i].prev == ara[i-1].prev &&
                ara[i].now == ara[i-1].now ? Rank[step][ara[i-1].ind] : i;
    }
}
 
int build_lcp()
{
    lcp[0] = 0;
    int id1, id2, tem, ret;
    tem = min(q, n - ara[0].ind) - p;
    ret = tem > 0? tem : 0;
    for(int i = 1; i < n; i++ ){
        id1 = ara[i-1].ind;
        id2 = ara[i].ind;
        lcp[i] = 0;
        for(int j = step-1; j >= 0 && id1<n && id2<n ; j--)
            if(Rank[j][id1] == Rank[j][id2]){
                lcp[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
        tem = min(q, n - ara[i].ind) - max(p, lcp[i]);
        ret += max(tem,0);
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin >> tc;
    while(tc--){
        cin >> str >> p >> q;
        p--;
        n = str.length();
        build_suffix_array();
        cout << "Case " << cas++ << ": " << build_lcp()<<endl;
    }
    return 0;
}
/*sample
 
*/
