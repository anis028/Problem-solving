#include <bits/stdc++.h>
using namespace std;
 
#define ROOT 0
 
const int MaxN = 60000;
int nxt[MaxN][12];
int eend[MaxN];
bool ans;
 
 
int main()
{
    int tc,p=1;
    cin>>tc;
    while(tc--)
    {
        int n,sz=0;
        ans=true;
        string s;
        cin>>n;
        memset(nxt,-1,sizeof(nxt));
        memset(eend,0,sizeof(eend));
        while(n--)
        {
            cin>>s;
            int node=0,cnt=0;
            for(int i=0; i<s.size(); i++)
            {
                if(nxt[node][s[i]-'0']==-1){
                        cnt++;
                    nxt[node][s[i]-'0']=++sz;
                }
                node=nxt[node][s[i]-'0'];
                if(eend[node]!=0) ans=false;
            }
            if(cnt==0) ans=false;
            ++eend[node];
        }
        cout<<"Case "<<p++<<": ";
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
 
 
 
    return 0;
}
 
/*
 every node will have at most 26 edges.
*/
