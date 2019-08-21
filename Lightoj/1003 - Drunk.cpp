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
 
int in[10005];
map<string,int>mp;
queue<int>st;
vector<int> g[10005];
 
void inline init()
{
    mm(in,0);
    mp.clear();
    while(!st.empty()) st.pop();
    for(int i=1;i<10005;i++) g[i].clear();
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        init();
        int n,ind=1,done=0;
        string a,b;
        cin>>n;
        while(n--){
            cin>>a>>b;
            if(mp.find(a)==mp.end()) mp[a]=ind++;
            if(mp.find(b)==mp.end()) mp[b]=ind++;
            in[mp[b]]++;
            g[mp[a]].pb(mp[b]);
//            cout<<a<<":"<<mp[a]<<" "<<b<<":"<<mp[b]<<endl;
        }
        for(int i=1;i<ind;i++){
//            cout<<i<<" - "<<in[i]<<endl;
            if(in[i]==0) st.push(i);
        }
        while(!st.empty()){
            done++;
            int u=st.front(),v;
            for(int i=0;i<g[u].size();i++){
                v=g[u][i];
                in[v]--;
//                cout<<v<<" "<<in[v]<<endl;
                if(in[v]==0) st.push(v);
            }
            st.pop();
        }
        cout<<"Case "<<cas++<<": ";
        if(done==ind-1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
/*sample
 
*/
