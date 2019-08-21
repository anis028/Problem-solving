#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   vvi           vector<vector<int> >
#define   vi            vector<int>
#define M 201
using namespace std;
string str;
int sg[M],len;
vector<int>p;
int get_sg(int m)
{
    if(m<0) return 0;
    if(sg[m]!=-1) return sg[m];
    bool vis[200]={0};
    for(int i=1;i<=m;i++)
        vis[get_sg(i-3)^get_sg(m-i-2)]=1;
    int i=0;
    while(vis[i]) i++;
    return sg[m]=i;
}
bool cal(int m)
{
    string s=str;
    if(s[m]=='X') return 0;
    s[m]='X';
    for(int i=0;i+2<len;i++)
        if(s[i]=='X'&&s[i+1]=='X'&&s[i+2]=='X') return 1;
    for(int i=0;i+1<len;i++)
        if(s[i]=='X'&&s[i+1]=='X') return 0;
    for(int i=0;i+2<len;i++)
        if(s[i]=='X'&&s[i+2]=='X') return 0;
    int i,j,ans=0;
    bool f=0;
    for(i=0,j=-1;i<len;i++){
        if(s[i]=='X'){
            if(f) ans^=get_sg(i-j-5);
            else{
                ans^=get_sg(i-j-3);
                f=1;
            }
            j=i;
        }
    }
    ans^=get_sg(len-j-3);
    return ans==0;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    memset(sg,-1,sizeof(sg));
    while(tc--){
        cin>>str;
        len=str.length();
        p.clear();
        for(int i=0;i<len;i++)
            if(cal(i)) p.push_back(i+1);
        cout<<"Case "<<cas++<<":";
        if(p.size()){
            for(int i=0;i<p.size();i++)
                cout<<" "<<p[i];
            cout<<endl;
        }
        else cout<<" 0"<<endl;
    }
    return 0;
}
/*sample
 
*/
 

