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
 
int grundy[505][505];
int dx[]={-3,-2,-2,-1,-1,1};
int dy[]={-1,-1,1,-3,-2,-2};
 
bool valid (int x,int y)
{
    if(x>-1 and y>-1 and x<501 and y<501) return true;
    return false;
}
 
int play(int r,int c)
{
    if(r<2 and c<2) return 0;
    int &ret=grundy[r][c];
    if(ret!=-1) return ret;
    ret=0;
    set<int>s;
    for(int i=0;i<6;i++){
        int nr=r+dx[i];
        int nc=c+dy[i];
        if(valid(nc,nr)) s.insert(play(nr,nc));
    }
    while(s.count(ret)) ret++;
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    mm(grundy,-1);
    while(tc--){
        int n,game=0,x,y;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            game^=play(x,y);
        }
        cout<<"Case "<<cas++<<": ";
        if(game) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
/*sample
 
*/
 
