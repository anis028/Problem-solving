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
 
int dp[102][3][3],vis[102];
map<char,int>id;
 
int grundy(int len,int left,int right)
{
    if(len<=0) return 0;
    if(len==1 and left==right and left!=2) return 1;
    if(len==1 and left!=right and left!=2 and right!=2) return 0;
    int &ret=dp[len][left][right];
    if(ret!=-1) return ret;
    ret=0;
    set<int>s;
    for(int i=1;i<=len;i++){
        if(i==1){
            if(left!=1) s.insert( grundy(len-i,1,right) );
            if(left!=0) s.insert( grundy(len-i,0,right) );
        }
        else if(i==len){
            if(right!=1) s.insert( grundy(i-1,left,1) );
            if(right!=0) s.insert( grundy(i-1,left,0) );
        }
        else{
            s.insert( grundy(i-1,left,0)^grundy(len-i,0,right) );
            s.insert( grundy(i-1,left,1)^grundy(len-i,1,right) );
        }
    }
    int x=0;
    while(s.find(x)!=s.end()) x++;
    return ret=x;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    mm(dp,-1);
    id['X']=0;
    id['O']=1;
    id['.']=2;
    while(tc--){
        string s;
        cin>>s;
        int lastpos=-1, game=0,cnt=0;
        char lastchar='.';
        for(int i=0;i<s.length();i++){
            if(s[i]!='.'){
                game^=grundy(i-lastpos-1,id[lastchar],id[s[i]]);
                cnt++;
                lastpos=i;
                lastchar=s[i];
            }
        }
        game^=grundy(s.length()-lastpos-1,id[lastchar],2);
        cout<<"Case "<<cas++<<": ";
        if(game) (cnt%2)? cout<<"No":cout<<"Yes";
        else (cnt%2)? cout<<"Yes":cout<<"No";
        cout<<endl;
    }
    return 0;
}
/*sample
 
*/
 

