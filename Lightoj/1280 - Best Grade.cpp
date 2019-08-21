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
 
struct sub{
    dbl got,tot,dif;
}ara[20005];
 
bool cmp(sub a,sub b)
{
    if(a.dif==b.dif) return a.tot<b.tot;
    return a.dif<b.dif;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    cin>>tc;
    while(tc--){
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>ara[i].got>>ara[i].tot;
        }
        dbl l=0.0,h=1.0,m;
        for(int i=0;i<30;i++){
            m=(l+h)/2.0;
            for(int j=0;j<n;j++) ara[j].dif=ara[j].got-ara[j].tot*m;
            sort(ara,ara+n,cmp);
            dbl a=0.0,b=0.0;
            for(int j=d;j<n;j++) a+=ara[j].got,b+=ara[j].tot;
            if(a/b>m) l=m;
            else h=m;
        }
        cout<<"Case "<<cas++<<": "<<fixed<<setprecision(12)<<l*100.0<<endl;
    }
    return 0;
}
/*sample
 
*/
