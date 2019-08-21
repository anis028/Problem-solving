#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc,cas=1;
    cin>>tc;
    while(tc--){
    double l,w,x;
    cin>>l>>w;
    x=((4.0*(l+w))-sqrt(16.0*(l+w)*(l+w)-48.0*l*w))/24.0;
    cout<<"Case "<<cas++<<": "<<setprecision(12)<<(l-x-x)*(w-x-x)*x<<endl;
    }
    return 0;
}
 
