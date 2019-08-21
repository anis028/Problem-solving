#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   m0d           1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define   lim           1000000000
using namespace std;
 
struct point
{
    long long x,y;
    bool operator < (const point &p) const
    {
        return x<p.x || (x==p.x && y<p.y);
    }
};
 
long long cross (point o,point a,point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double dist (point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
 
long long dot (point o,point a,point b)
{
    return (a.x-o.x)*(b.x-o.x)+(a.y-o.y)*(b.y-o.y);
}
 
vector<point> hull(vector<point> p)
{
    long long n=p.size(),k=0;
    vector<point>H(2*n);
    sort(p.begin(),p.end());
    for(int i=0; i<n; i++)
    {
        while(k>=2 && cross(H[k-2],H[k-1],p[i]) <= 0) k--;
        H[k++]=p[i];
    }
    for(int i=n-2,t=k+1; i>=0; i--)
    {
        while(k>=t && cross(H[k-2],H[k-1],p[i]) <= 0) k--;
        H[k++]=p[i];
    }
    H.resize(k-1);
    return H;
}
 
int main()
{
    int n,tc,cas=1;
    cin>>tc;
    while(tc--)
    {
        point p;
        vector<point> v1,v2;
        cin>>n;
        v1.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%lld %lld",&p.x,&p.y);
            v1.pb(p);
        }
        v2=hull(v1);
        //for(int i=0;i<v3.size();i++) cout<<v3[i].x<<" "<<v3[i].y<<endl;
        printf("Case %d: ",cas++);
        if(v2.size()<3) cout<<"0"<<endl;
        else
        {
            double ans=200.0,x,a,b;
            int sz=v2.size();
//            cout<<sz<<endl;
            for(int i=2; i<sz; i++)
            {
                a=dist(v2[i-2],v2[i-1]);
                b=dist(v2[i-1],v2[i]);
 
                x=acos(((double)dot(v2[i-1],v2[i],v2[i-2]))/(a*b));
                x=(x/acos(-1.0))*180.0;
                ans= min(x,ans);
            }
            a=dist(v2[sz-2],v2[sz-1]);
            b=dist(v2[sz-1],v2[0]);
            x=acos(((double)dot(v2[sz-1],v2[0],v2[sz-2]))/(a*b));
            x=(x/acos(-1.0))*180.0;
            ans= min(x,ans);
            a=dist(v2[sz-1],v2[0]);
            b=dist(v2[0],v2[1]);
            x=acos(((double)dot(v2[0],v2[1],v2[sz-1]))/(a*b));
            x=(x/acos(-1.0))*180.0;
            ans= min(x,ans);
            cout<<fixed<<setprecision(12)<<ans<<endl;
        }
    }
    return 0;
}
/*sample
45
4
0 0
10 0
10 10
2 1
*/
