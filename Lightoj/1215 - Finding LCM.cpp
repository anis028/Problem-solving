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
 
bitset<1000002>flag;
ll prime[78500],len;
int sieve(int n)
{
    flag.reset();
    for(int i=4; i<=n; i+=2)flag[i]=1;
 
    for(int i=3; i*i<=n; i+=2){
        if(!flag[i]){
            for(int j=i*i; j<=n; j+=(i<<1))
                flag[j]=1;
        }
    }
    int ind=1;
    prime[0]=2;
 
    for(int i=3; i<=n; i+=2)
        if(!flag[i]) prime[ind++]=i;
 
    return ind;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc,cas=1;
    len=sieve(1000001);
    cin>>tc;
    while(tc--){
        ll a,b,l,tmp,ans=1;
        cin>>a>>b>>l;
        int done=0,c1,c2;
        for(int i=0;i<len and (a>1 or b>1);i++){
            c1=0,c2=0,tmp=1;
            while(a%prime[i]==0 || b%prime[i]==0 || l%prime[i]==0){
                if(a%prime[i]==0 || b%prime[i]==0) c1++;
                if(a%prime[i]==0)a/=prime[i];
                if(b%prime[i]==0)b/=prime[i];
                if(l%prime[i]==0)l/=prime[i],c2++;
                tmp*=prime[i];
            }
            ///if(c1+c2>0)cout<<prime[i]<<" "<<c1<<" "<<c2<<endl;
            if(c2>c1) ans*=tmp;
            if(c2<c1){
                done=1;
                break;
            }
        }
 
        cout<<"Case "<<cas++<<": ";
        if(done) cout<<"impossible"<<endl;
        else cout<<ans*l<<endl;
    }
    return 0;
}
/*sample
 
*/
