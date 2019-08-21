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
 
int Rank[18][50005], step, n, lcp[50005], p, q[50005], fail[50005], B[50005];
string str, pat;
 
struct info{
    int prev, now, ind;
    bool operator < (const info &a)const{
        return prev != a.prev ? prev < a.prev : now < a.now;
    }
}ara[50005];
 
bool cmp(int x, int y){
    return Rank[step-1][x] < Rank[step-1][y];
}
void build_suffix_array()
{
    int jump = 1;
    for(int i = 0; i < n; i++) Rank[0][i] = str[i] - 'a';
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1){
        for(int i = 0; i < n; i++){
            ara[i].ind = i;
            ara[i].prev = Rank[step-1][i];
            ara[i].now = i+jump < n ? Rank[step-1][i+jump] : -1;
        }
        sort(ara, ara+n);
        Rank[step][ara[0].ind] = 0;
        for(int i = 1; i < n; i++)
            Rank[step][ara[i].ind] = ara[i].prev == ara[i-1].prev &&
                                     ara[i].now == ara[i-1].now ?
                                     Rank[step][ara[i-1].ind] : i;
    }
    for(int i = 0; i < n; i++) B[i] = i;
    sort(B,B+n,cmp);
}
 
void build_lcp()
{
    lcp[0] = 0;
    int x, y;
    for(int i = 1; i < n; i++){
        x = B[i];
        y = B[i-1];
        lcp[i] = 0;
        for(int j = step-1; j >=0 && x<n && y<n; j--)
            if(Rank[j][x] == Rank[j][y])
                lcp[i] += (1<<j), x += (1<<j), y += (1<<j);
    }
}
 
void kmp_fail()
{
    fail[1] = 0;
    for(int i = 2, j = 0; i <= pat.length(); i++){
        while(j > 0 and pat[i-1] != pat[j]) j = fail[j];
        fail[i] = (j += pat[i-1] == pat[j]);
    }
}
 
void kmp_match()
{
    mm(q,-1);
    int i, j;
    for(i = 0, j = 0; i < str.length(); i++){
        while(j > 0 and pat[j] != str[i]) j = fail[j];
        j += pat[j] == str[i];
        if(j == pat.length()) q[i-j+1] = i-j+1;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        int ans=0, l_str, l_pat;
        cin >> str >> pat;
        l_str = str.length(), l_pat = pat.length();
        if(1){
            n = l_str;
            build_suffix_array();
            build_lcp();
            kmp_fail();
            kmp_match();
            int l = l_str;
            for(int i = l_str - 1; i >= 0; i--){
                if(q[i] == -1) q[i] = l;
                l = q[i];
            }
//            for(int i=0;i<n;i++) cout<<B[i]<<" ";cout<<endl;
//            for(int i=0;i<n;i++) cout<<q[i]<<" ";cout<<endl;
//            for(int i=0;i<n;i++) cout<<lcp[i]<<" ";cout<<endl;
            for(int i = 0; i < l_str; i++){
                int tmp = min(l_str, q[B[i]]+l_pat-1) - B[i] - lcp[i];
                ans += max(0,tmp);
            }
        }
        cout << "Case " << cas++ << ": " << ans << endl;
    }
    return 0;
}
/*sample
 
*/
