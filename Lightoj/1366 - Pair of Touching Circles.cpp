#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define met(a, b) memset(a, b, sizeof(a))
#define maxn 10005
#define maxm 20005
#define INF 0x3f3f3f3f
typedef long long LL;
 
int main()
{
    int T, H, W, t = 1;
    scanf("%d", &T);
    while(T--)
    {
        LL ans = 0;
        scanf("%d %d", &H, &W);
        for(int i=0; i<=W/2; i++)
        {
            for(int j=0; j<=H/2; j++)
            {
                if(i==0 && j==0) continue;
                int d = sqrt(i*i + j*j);
                if(d*d != i*i + j*j) continue;
                for(int r=1; r<d; r++)
                {
                    int x1 = min(-r, i-(d-r)), x2 = max(r, i+(d-r));
                    int y1 = min(-r, j-(d-r)), y2 = max(r, j+(d-r));
                    int x = x2 - x1, y = y2 - y1;
                    if(x > W || y > H) continue;
                    LL ret = (LL)(H-y+1)*(W-x+1);
                    if(i*j) ret *= 2;
                    ans += ret;
                }
            }
        }
        printf("Case %d: %lld\n", t++, ans);
    }
    return 0;
}
