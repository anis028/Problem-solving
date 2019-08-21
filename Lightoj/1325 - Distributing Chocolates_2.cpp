#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
typedef long long LL;
 
LL  y , x , k , z , bta , alp , m , gma , p, res ;
 
void exgcd(LL a,LL b,LL& d,LL& x,LL& y){
    if (!b) d=a,x=1LL,y=0LL;
    else exgcd(b,a%b,d,y,x),y-=x*(a/b);
}
 
inline LL Dlog(LL A,LL B,LL C){
    LL tmp=1,cnt=0,D=1;
//    for (int i=0;i<32;i++){
//        if (tmp==B) return i;
//        tmp=tmp*A%C;
//    }
    LL  nothing ;
 
    while ((res=__gcd(A,C))>1){
        if (B%res) return -1;
        B/=res; C/=res;
        D=D*A/res%C;
        cnt++;
    }
//    cout<<"OK\n";
    int sqrtn=ceil(sqrt(C));
    unordered_map<int,int> mp;
    mp.clear();
    LL base=1;
    for (int i=0;i<sqrtn;i++){
        if (mp.find(base)==mp.end())
            mp[base]=i;
        base=base*A%C;
    }
    //cout<<"base : "<<base<<endl;
    for (int i=0;i<sqrtn;i++){
        exgcd(D,C,z,x,y);
        //cout<<D<<" "<<C<<" "<<z<<" "<<x<<" "<<y<<endl;
        int c=C/z;
        x=(x*B/z%c+c)%c;
        //cout<<c<<" "<<x<<endl;
        if (mp.find(x)!= mp.end ()) {
            return  i * sqrtn + cnt + mp [ x ];
        }
        D = D * base % C ;
    }
    return  - 1 ;
}
 
int main(){
    int tc,cas=1;
    cin>>tc;
    while (tc--){
        cin>>x>>k;
        k%=100000007;
        LL ans=Dlog(x,k,100000007);
        if (ans==-1)
            cout<<"No Solution"<<endl;
        else
            cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
}
 
