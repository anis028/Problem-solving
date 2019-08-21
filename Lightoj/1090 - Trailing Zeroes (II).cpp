#include<bits/stdc++.h>
#define db(x) printf("%d\n",x)
using namespace std;
 
long long n,r,p,q;
 
int fact(int a,int b)
{
    int x=0;
    while(a>0)
    {
        x+=(a/b);
        a/=b;
    }
    return x;
}
 
long long num(int x)
{
    long long c=0;
    while(p%x==0)
    {
        c++;
        p/=x;
    }
    c*=q;
    c+=fact(n,x)-fact(r,x)-fact(n-r,x);
    return c;
}
int main()
{
    int tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>r>>p>>q;
        cout<<"Case "<<cas++<<": "<<min(num(2),num(5))<<endl;
    }
    return 0;
}
