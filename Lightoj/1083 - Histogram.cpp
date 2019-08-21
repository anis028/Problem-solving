#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
 
using namespace std;
 
int t[1000000],ara[30003],n;
 
void build(int node,int b,int e)
{
    if(b==e){
        t[node]=b;
        return;
    }
    int mid=(b+e)/2,lc=node*2,rc=lc+1;
    build(lc,b,mid);
    build(rc,mid+1,e);
    if(ara[t[lc]]>ara[t[rc]]) t[node]=t[rc];
    else t[node]=t[lc];
}
 
int query(int node,int s,int f,int i,int j)
{
    if(s>j or f<i) return -1;
    if(s>=i and f<=j) return t[node];
    int mid=(s+f)/2,lc=node*2,rc=lc+1;
    int x=query(lc,s,mid,i,j);
    int y=query(rc,mid+1,f,i,j);
    if(x==-1) return y;
    if(y==-1) return x;
    if(ara[x]<ara[y]) return x;
    return y;
}
 
long long ans(int b,int e)
{
    if(b>e) return 0;
    if(b==e) return ara[b];
    int ind=query(1,1,n,b,e);
    long long x=max(ans(b,ind-1),ans(ind+1,e));
    return max(x,(long long)(e-b+1)*ara[ind]);
 
}
 
int main()
{
    int tc,p=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(int i=1 ;i<=n;i++) scanf("%d",&ara[i]);
        build(1,1,n);
        printf("Case %d: %lld\n",p++,ans(1,n));
    }
    return 0;
}
/*sample
 
*/
