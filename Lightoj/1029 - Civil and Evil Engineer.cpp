#define pb push_back
#define Pb pop_back
 
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
 
#define pf1(x) printf("%d\n", x)
 
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007
 
#define ll long long
#define llu unsigned long long
 
#include<limits.h>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
 
#define clr( a, b )     memset((a),b,sizeof(a))
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
 
 
#define fs first
#define sc second
 
///ios_base::sync_with_stdio(false)
 
using namespace std;
 
struct Disjoint_set
{
    int n;
    vector<int>parent,Rank;
    Disjoint_set() {}
    Disjoint_set(int _n)
    {
        n=_n;
        parent=vector<int>(n+2);
        Rank=vector<int>(n+2);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
 
        }
    }
    ///constructor, two types
    /*Disjoint_set(int n):n(n+2),parent(n+2),Rank(n+2)
    {
        for(int i=0; i<=n; i++)
        {
            parent[i]=i;
        }
    }*/
    int findparent(int x)
    {
        if(parent[x]==x) return x;
        else return parent[x]=findparent(parent[x]);
    }
    int mergenodes(int x,int y)
    {
        ///if connected returns false
        int a=findparent(x);
        int b=findparent(y);
        if(a==b) return 0;
        else
        {
            if(Rank[a]>Rank[b]) parent[b]=a;
            else if(Rank[b]>Rank[a]) parent[a]=b;
            else
            {
                parent[a]=b;
                Rank[b]++;
            }
            return 1;
        }
    }
};
 
struct kruskal
{
    int n;
    Disjoint_set D,Dd;
    kruskal(int n): n(n),D(n) {}
    vector< pair<int, pair<int,int> > > edges ;
    void addedge(int x,int y,int w)
    {
        //edges.pb( pair<int, pair<int,int> > (w,pair<int,int>(x,y)) );
        edges.pb ({w,{x,y}});
    }
    int Minst()
    {
        int mst=0;
        sort(edges.begin(),edges.end());
        for(int i=0; i<edges.size(); i++)
        {
            if(D.mergenodes(edges[i].sc.fs,edges[i].sc.sc)) mst+=edges[i].fs;
        }
        return mst;
    }
    int Maxst()
    {
        Disjoint_set Dd(n);
        int mst=0;
        sort(edges.begin(),edges.end());
        for(int i=edges.size()-1; i>=0; i--)
        {
            if(Dd.mergenodes(edges[i].sc.fs,edges[i].sc.sc)) mst+=edges[i].fs;
        }
        return mst;
    }
};
 
int main()
{
    int cas=1,t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n++;
        kruskal K(n);
        while(1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            if(u==0 && v==0 && w==0) break;
            K.addedge(u,v,w);
        }
        int sum=K.Minst()+K.Maxst();
        if(sum%2==0) printf("Case %d: %d\n",cas++,sum/2);
        else printf("Case %d: %d/2\n",cas++,sum);
    }
    return 0;
}
 
