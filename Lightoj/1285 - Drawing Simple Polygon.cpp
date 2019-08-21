#include<bits/stdc++.h>
 
#define   db(x)         printf("**%d\n",x)
#define   loop(i,x,n)   for(int i=x;i<n;i++)
#define   pb            push_back
#define   pii           pair<int,int>
#define   ppii          pair<pii,int>
#define   imax          2147483647
#define   pcase(x)      printf("Case %d: ",x)
#define   md            1000000007
#define   mm(x,y)       memset(x,y,sizeof(x))
#define   pf1(x)        printf("%d\n",x)
#define   pf2(x,y)      printf("%d %d\n",x,y)
#define   sf1(x)        scanf("%d",&x)
#define   sf2(x,y)      scanf("%d %d",&x,&y)
#define   fs            first
#define   sc            second
 
using namespace std;
 
vector<ppii>p;
int ans[20005],fx,fy,ind,linear;
 
int c_check(ppii o,ppii a,ppii b)
{
    return (a.fs.fs-o.fs.fs)*(b.fs.sc-o.fs.sc)-(a.fs.sc-o.fs.sc)*(b.fs.fs-o.fs.fs);
}
 
int dist(ppii a,ppii b)
{
    return (a.fs.fs-b.fs.fs)*(a.fs.fs-b.fs.fs)+(a.fs.sc-b.fs.sc)*(a.fs.sc-b.fs.sc);
}
 
bool cmp(ppii a,ppii b)
{
    int x=c_check({{fx,fy},ind},a,b);
    if(x<0) {linear=0;return false;}
    else if(x>0) {linear=0;return true;}
    else if(dist({{fx,fy},ind},a)>dist({{fx,fy},ind},b)) return false;
    return true;
}
 
int main()
{
    int tc,cas=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,x,y;
        p.clear();
        fx=1<<30,fy=1<<30,linear=1;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            if(y<fy)
            {
                ind=i;
                fy=y;
                fx=x;
            }
            else if(y==fy)
            {
                ind=i;
                fx=x;
            }
            p.pb({{x,y},i});
        }
        p.erase(p.begin()+ind);
        sort(p.begin(),p.end(),cmp);
        printf("Case %d:\n",cas++);
        if(linear) printf("Impossible\n");
        else
        {
            p.insert(p.begin(), {{fx,fy},ind});
            for(int i=p.size()-2;i>0;i--)
            if(c_check(p[0],p[i],p[i+1])!=0) {ind=i+1;break;}
 
            printf("%d",p[0].sc);
            for(int i=1;i<ind;i++) printf(" %d",p[i].sc);
            for(int i=p.size()-1;i>=ind;i--) printf(" %d",p[i].sc);
            printf("\n");
        }
    }
    return 0;
}
/*sample
 
*/
