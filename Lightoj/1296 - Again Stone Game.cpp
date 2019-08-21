/// grundy sequence 0 1 0 2 1 3 0 4 2 5 1 6 3 7 0 8 4 9 2 10 5 11 1 12 6 13 3 14 7 15
 
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
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int n,game=0,x;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            while(x%2) x/=2;
            game^=(x/2);
        }
        cout<<"Case "<<cas++<<": ";
        if(game) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
/*sample
 
*/
