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
 
int tree[1005][1005];
bool vis[1005][1005];
 
 
void update(int x,int y)
{
    while(x<=1001){
        int y1 = y;
        while(y1<=1001){
            tree[x][y1]++;
            y1 +=( y1 & -y1);
        }
        x += (x & -x);
    }
}
 
int query(int x,int y)
{
    int ret=0;
    while(x>0){
        int y1 = y;
        while(y1>0){
            ret += tree[x][y1];
            y1 -=( y1 & -y1);
        }
        x -= (x & -x);
    }
    return ret;
}
 
int main()
{
    int tc=1,cas=1;
    scanf("%d",&tc);
    while(tc--){
        mm(tree,0);
        mm(vis,0);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        while(q--){
            int type;
            scanf("%d",&type);
            if(type){
                int x1,x2,y1,y2;
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2); x1++, y1++, x2++, y2++;
                printf("%d\n",query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1));
            }
            else{
                int x1,y1;
                scanf("%d %d",&x1,&y1);x1++, y1++;
                if(vis[x1][y1]) continue;
                vis[x1][y1]=cas;
                update(x1,y1);
            }
        }
    }
    return 0;
}
/*sample
 
*/

