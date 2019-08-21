#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 +10;
const int MOD = 1e6 + 7;
LL a[MAXN];
LL sum[MAXN];
int main()
{
    int t, kcase = 1;
    scanf("%d", &t);
    while(t--) {
        int K, C, n, v;
        scanf("%d%d%d%d", &K, &C, &n, &v);
        a[1] = v;
        for(int i = 2; i <= n; i++) {
            a[i] = (a[i-1] * K % MOD + C) % MOD;
        }
        sort(a+1, a+n+1);
        LL ans = 0;
        sum[0] = 0;
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i-1] + a[i];
        }
        for(int i = 1; i <= n; i++) {
            ans += sum[n] - sum[i] - 1LL * (n - i) * a[i];
        }
        printf("Case %d: %lld\n", kcase++, ans);
    }
    return 0;
}
