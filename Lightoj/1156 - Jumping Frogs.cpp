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
 
vector<int>v;
int flag[205];
 
int check(int lim)
{
//    cout<<"-->"<<lim<<endl;
    mm(flag,0);
    int now=0;
    for(int i=0;i<v.size()-1;){
//        cout<<"at "<<i<<endl;
        int j=i;
        while(v[j+1]-v[i]<=lim and j<v.size()) j++;
//        cout<<"finished at "<<j<<endl;
        if(v[i]==v[j]) return 0;
        flag[j]=1;
        i=j;
    }
    now=v.size()-1;
    for(int i=v.size()-1;i>0;){
//            cout<<"at }}}"<<i<<endl;
        int j=i;
        while(j-1>-1 and v[i]-v[j-1]<=lim ) j--;
        while(flag[j]==1) j++;
//        cout<<"finished at "<<j<<endl;
        if(v[i]==v[j]) return 0;
        i=j;
    }
    return 1;
}
 
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--){
        v.clear();
        v.pb(0);
        int n,d,x;
        scanf("%d %d",&n,&d);
        getchar();
        char c;
        for(int i=0;i<n;i++){
            if(i) getchar();
            c=getchar();
            getchar();
            scanf("%d",&x);
            if(c=='B') v.pb(x),v.pb(x);
            else v.pb(x);
        }
        v.pb(d);
        int lo=1,hi=d,ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(mid)) ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
/*sample
3
1 10
B-5
1 10
S-5
2 10
B-3 S-6
*/
