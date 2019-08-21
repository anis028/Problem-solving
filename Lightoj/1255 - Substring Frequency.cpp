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
 
int pref[2000005],pi[2000005];
 
int compute_prefix( string s, int len)
{
//    cout << s << " " << len << endl;
    int ret = 0, now = pref[0] = -1;
    for( int i = 1 ; i < s.length() ; i++){
//        cout << "index : " << i << endl;
        while( s[now + 1] != s[i] and now != -1)
            now = pref[now];
        if( s[now + 1] == s[i]) pref[i] = ++now;
        else pref[i] = now = -1;
//        cout << now << endl;
        if(now == len - 1) ret++;
    }
    return ret;
}
 
int calc(string str,int len)
{
    int i , j = 0 , ans=0;
    pi[1] = 0 ;
    for ( i = 2 , j = 0 ; i <= str.length() ; i++ )
    {
        while( j > 0 && str[i-1] != str[j] ) j = pi[j];
        pi[i] = (j += (str[i-1] == str[j]) );
        if(j==len) ans++;
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas = 1;
    cin >> tc;
    while( tc-- ){
        string s, pattern, x;
        cin >> s >> pattern;
        x = pattern + "#" + s;
        int l = pattern.length();
        cout << "Case " << cas++ << ": " << calc( x, l ) << endl;
    }
    return 0;
}
/*sample
 
*/
 
