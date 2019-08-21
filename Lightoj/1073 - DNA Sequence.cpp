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
 
int tc,cas=1,vis[16][(1<<16)+4],dp[16][(1<<16)+4],n,fail[16][105],pre[16][16];
string s[16];
 
void calc_fail(int idx)
{
    fail[idx][1]=0;
    for(int i=2,j=0; i<=s[idx].length();i++){
        while(j>0 and s[idx][i-1]!=s[idx][j]) j=fail[idx][j];
        fail[idx][i]= (j += s[idx][i-1]==s[idx][j]);
    }
}
 
int calc_match(int id1,int id2)
{
    int i,j;
    for(i=0,j=0;i<s[id1].length();i++){
        while(j>0 and s[id2][j]!=s[id1][i]) j=fail[id2][j];
        j+=s[id2][j]==s[id1][i];
        if(j==s[id2].length()) return 0;
    }
    return s[id2].length()-j;
}
 
int rec(int last,int mask)
{
    if(mask+1 == (1<<n)) return 0;
    int &ret = dp[last][mask];
    if(vis[last][mask]==cas) return ret;
    vis[last][mask]=cas;
    ret = 300000000;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        ret=min(ret, rec(pre[last][i]?i:last, mask|(1<<i))+pre[last][i]);
    }
    return ret;
}
 
void print(int last,int mask)
{
    if(mask+1 == (1<<n)){cout<<endl;return;}
    string minstr="Z";
    int minidx;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        if(rec(last,mask) == rec(pre[last][i]?i:last, mask|(1<<i))+pre[last][i]){
            string tmp = pre[last][i]?s[i].substr(s[i].length()-pre[last][i]):"";
            if(minstr > tmp){
                minstr=tmp;
                minidx=i;
            }
        }
    }
    cout<<minstr;
    print(minstr==""?last:minidx, mask|(1<<minidx));
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>s[i];
        sort(s,s+n);
        for(int i=0;i<n;i++) calc_fail(i);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                pre[i][j]=calc_match(i,j);
 
        int ans=20*200, first;
        for(int i=0;i<n;i++){
            int tmp = rec(i,(1<<i)) + s[i].length();
            if(tmp<ans){
                ans=tmp;
                first=i;
            }
        }
        cout<<"Case "<<cas<<": "<<s[first];
        print(first,1<<first);
        cas++;
    }
    return 0;
}
/*sample
 
*/
