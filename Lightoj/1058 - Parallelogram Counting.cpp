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
 
vector<pii>v,l;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int ans=0,n,x,y;
        v.clear(),l.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            v.pb({x,y});
        }
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                x=v[i].fs+v[j].fs;
                y=v[i].sc+v[j].sc;
                l.pb({x,y});
            }
        }
        sort(l.begin(),l.end());
        int ind=0;
        pii line;
        while(ind<l.size()){
            line=l[ind];
            n=1;
            while(ind+1<l.size() and l[ind+1]==line){
                n++;
                ind++;
            }
            ind++;
            ans+=((n*(n-1))/2);
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
/*sample
 
*/
