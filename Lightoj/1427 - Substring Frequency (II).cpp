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
 
bitset<500>out[500*500];
int fail[500*500],go[500*500][26],n,state;
vector<string>pat;
 
void build_suffix_trie()
{
    for(int i=0; i<500*500;i++) out[i].reset();
    mm(go,-1);
    mm(fail,-1);
 
    int cur;
    state=0;
    for(int i=0;i<n;i++){
        cur=0;
        char ch;
        for(int j=0;j<pat[i].length();j++){
            ch = pat[i][j]-'a';
            if(go[cur][ch]==-1)
                go[cur][ch] = ++state;
            cur = go[cur][ch];
        }
        out[cur].set(i);
    }
 
    queue<int>q;
    for(int i=0;i<26;i++){
        if(go[0][i]==-1) go[0][i]=0;
        else{
            fail[go[0][i]]=0;
            q.push(go[0][i]);
        }
    }
 
    int node;
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(go[node][i]!=-1){
                int cur_fail = fail[node];
                while(go[cur_fail][i]==-1) cur_fail = fail[cur_fail];
 
                cur_fail = go[cur_fail][i];
                fail[go[node][i]] = cur_fail;
                out[go[node][i]] |= out[cur_fail];
                q.push(go[node][i]);
            }
        }
    }
}
 
int next_state(int idx, int ch)
{
    while(go[idx][ch]==-1) idx = fail[idx];
    return go[idx][ch];
}
 
int ans[505];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,cas=1;
    cin>>tc;
    while(tc--){
        string s,st;
        cin>>n>>s;
        mm(ans,0);
        pat.clear();
        for(int i=0;i<n;i++) cin>>st, pat.pb(st);
        build_suffix_trie();
 
        int cur=0;
        for(int i=0;i<s.length();i++){
            cur = next_state(cur, s[i]-'a');
            if(out[cur].none()) continue;
            for(int j=0;j<=n;j++) ans[j] += out[cur][j];
        }
        cout<<"Case "<<cas++<<":"<<endl;
        for(int i=0;i<n;i++) cout<<ans[i]<<endl;
    }
    return 0;
}
/*sample
 
*/
 
 

