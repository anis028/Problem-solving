#include<bits/stdc++.h>
 
#define   pb            push_back
#define   pii           pair<int,int>
#define   imax          2147483647
#define   md            1000000007
#define   fs            first
#define   sc            second
 
using namespace std;
 
int treex[200009],treey[200009];
 
void updatex(int node,int b,int f,int at,int val)
{
    if( b>at || f<at ) return;
    if(b==f){treex[node]+=val; return;}
    int mid=b+(f-b)/2,lc=node*2,rc=lc+1;
    updatex(lc,b,mid,at,val);
    updatex(rc,mid+1,f,at,val);
    treex[node]= treex[lc]+treex[rc];
}
 
int queryx(int node,int b,int f,int val)
{
    if(b==f) return b;
    int mid=b+(f-b)/2,lc=node*2,rc=lc+1;
    if(treex[lc]>=val) return queryx(lc,b,mid,val);
    else return queryx(rc,mid+1,f,val-treex[lc]);
}
 
void updatey(int node,int b,int f,int at,int val)
{
    if( b>at || f<at ) return;
    if(b==f){treey[node]+=val; return;}
    int mid=b+(f-b)/2,lc=node*2,rc=lc+1;
    updatey(lc,b,mid,at,val);
    updatey(rc,mid+1,f,at,val);
    treey[node]= treey[lc]+treey[rc];
}
 
int queryy(int node,int b,int f,int val)
{
    if(b==f) return b;
    int mid=b+(f-b)/2,lc=node*2,rc=lc+1;
    if(treey[lc]>=val) return queryy(lc,b,mid,val);
    else return queryy(rc,mid+1,f,val-treey[lc]);
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(treex,0,sizeof(treex));
        memset(treey,0,sizeof(treey));
        int m,n,q,x,y,w;
        scanf("%d %d %d",&m,&n,&q);
        while(q--)
        {
            scanf("%d %d %d",&x,&y,&w);
            updatex(1,1,m,x,w);
            updatey(1,1,n,y,w);
        }
        x=treex[1];
        x/=2;
        if(treex[1]&1) x++;
        y=treey[1];
        y/=2;
        if(treey[1]&1) y++;
        printf("Case %d: %d %d\n",cas++,queryx(1,1,m,x),queryy(1,1,n,y));
    }
    return 0;
}
/*sample
   
*/
 
