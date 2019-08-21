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
 
int pref[1000005];
 
int compute_prefix( string s )
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
    }
    return ret;
}
 
int match(string s, string pat)
{
    int now = -1;
    for(int i = 0; i < s.length(); i++){
        while(now != -1 and pat[now+1] != s[i]) now = pref[now];
        if(pat[now + 1] == s[i]) ++now;
        else now = -1;
    }
    return now + 1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas = 1;
    cin >> tc;
    while( tc-- ){
        string txt, pattern, x;
        cin >> txt;
        pattern = txt;
        reverse( pattern.begin(), pattern.end());
        compute_prefix(pattern);
        cout << "Case " << cas++ << ": " << 2 * txt.length() - match(txt, pattern) << endl;
    }
    return 0;
}
/*sample
 
*/
