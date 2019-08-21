#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   pb            push_back
#define   pii           pair<int,int>
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   fs            first
#define   sc            second
#define lim 1000000000000
using namespace std;
 
vector<long long> v,lucky;
map<long long,bool>m;
int sz;
 
 
void gen(long long num)
{
    if(num>lim) return;
    v.pb(num);
    gen(num*10+4);
    gen(num*10+7);
}
 
void geN(int pos,long long num)
{
    for(int i=pos;i<sz;i++)
    {
        long long tmp = num*v[i];
        //cout<<tmp<<endl;
        if(tmp<=0 || tmp>lim) return;
        if(m[tmp]==false) m[tmp]=true,lucky.pb(tmp);
        geN(i,tmp);
    }
}
 
int main()
{
    int tc,cas=1;
    gen(4);
    gen(7);
    sort(v.begin(),v.end());
    sz=v.size();
    geN(0,1);
    sort(lucky.begin(),lucky.end());
    scanf("%d",&tc);
    while(tc--)
    {
        long long a,b;
        scanf("%lld %lld",&a,&b);
        b=upper_bound(lucky.begin(),lucky.end(),b)-lucky.begin();
        a=upper_bound(lucky.begin(),lucky.end(),a-1)-lucky.begin();
        printf("Case %d: %lld\n",cas++,b-a);
    }
    return 0;
}
/*sample
 
*/
