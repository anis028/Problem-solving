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
 
string str,s1,s2,s3;
 
int Rank[15][15005],step,n,p,q,lcp[15005];
 
struct info{
    int prev,now,ind;
    bool operator < (const info &a)const{
        return prev != a.prev ? prev < a.prev : now < a.now;
    }
}ara[15005];
 
void build_suffix_array()
{
    int jump=1;
    for(int i = 0; i < n; i ++) Rank[0][i] = str[i] - 'A';
    for(step = 1, jump = 1; jump < n; step++, jump <<= 1 ){
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
    int id1, id2, id3, a, b, c, x, y, z, ret=0, tem;
    x = s1.length(), y = s2.length(), z = s3.length();
    for(int i = 1; i < n; i++){
        a = ara[i-1].ind, b = ara[i].ind, c = ara[i+1].ind;
        id1 = min(a, min(b, c));
        id3 = max(a, max(b, c));
        id2 = (a + b + c) - (id1 + id3);
        if(id1 >= x || id2 <= x || id2 > x + y || id3 <= x + y)
            continue;
        tem = 0;
        for(int j = step - 1; j >= 0; j--){
            if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2] == Rank[j][id3] && Rank[j][id1] == Rank[j][id3]){
                tem += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
                id3 += (1 << j);
            }
        }
        ret = max(ret, tem);
    }
    return ret;
}
 
void printpref(int x)
{
    for(int i = x; i < n; i++) cout << str[i];
}
 
void printsa()
{
    for(int i = 0; i < n; i++){
        printf("%d %d: ", i, ara[i].ind);
        printpref(ara[i].ind);
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < n; i++) cout << lcp[i] << " ";
    cout<<endl;
}
 
void build_Lcp(){
    lcp[0]=0;
    for(int i = 1; i < n; i++){
        int id1 = ara[i-1].ind;
        int id2 = ara[i].ind;
        lcp[i]=0;
        for(int j = step-1; j >= 0; j--){
            if(Rank[j][id1] == Rank[j][id2]){
                lcp[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
        }
    }
}
 
int getind(int pos)
{
    if(pos < s1.length()) return 0;
    if(pos > s1.length() && pos <= s1.length() + s2.length()) return 1;
    return 2;
}
 
bool isok(int mid)
{
    int mask = 0;
    for(int i = 1; i < n; i++){
//        cout << "in " << i << " ";
        if(lcp[i] < mid) mask = 0;
        else{
            mask |= (1 << getind(ara[i].ind));
//            cout<< mask <<" ";
            mask |= (1 << getind(ara[i-1].ind));
//            cout << mask <<endl;
            if(mask == 7) return true;
        }
    }
    return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin >> tc;
    while(tc--){
        cin >> s1 >> s2 >> s3;
        str = s1 + "#" + s2 + "#" + s3;
        n = str.length();
        build_suffix_array();
        build_Lcp();
        //printsa();
        int ans = 0, l = 1, r = s1.length();
        while(l <= r){
            int mid = (l + r)/2;
            if(isok(mid)) l = mid + 1;
            else r = mid - 1;
        }
        cout << "Case " << cas++ << ": " << l - 1 << endl;
    }
    return 0;
}
/*sample
1
a
abcabe
abe
*/
