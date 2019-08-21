#include <bits/stdc++.h>
 
using namespace  std;
 
typedef long long ll;
 
const ll mod = 100000007;
 
#define SZ 1000000+10
 
ll BigMod (ll B, ll P, ll M) {
    ll R = 1 % M;
    while (P > 0) {
        if(P % 2 == 1) {
            R = (R * B) % M;
        }
        P /= 2;
        B = (B * B) % M;
    }
    return R;
}
 
ll nCr (int n, int r, vector <ll>& fact) {
    if(r > n) return 0LL;
    ll ans = fact[n];
    ans = (ans * BigMod(fact[r], mod-2, mod)) % mod;
    ans = (ans * BigMod(fact[n-r], mod-2, mod)) % mod;
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
 
    vector <ll> fact(1000001, 1);
    for (int i = 1; i <= 1000000; i++) {
        fact[i] = ((ll)i * fact[i-1]) % mod;
    }
 
    int t;
    cin >> t;
 
    for (int cs = 0; cs < t; cs++) {
        int k, n;
        cin >> k >> n;
 
        vector <int> low(k), high(k);
 
        for (int i = 0; i < k; i++) {
            cin >> low[i] >> high[i];
        }
 
        ll ans = 0LL;
        int lim = (1 << k);
 
        for (int mask = 0; mask < lim; mask++) {
            int tot = n, cnt = 0;
 
            for (int i = 0; i < k; i++) {
                if (mask & (1<<i)) {
                    tot -= (high[i] + 1);
                    cnt++;
                } else {
                    tot -= low[i];
                }
            }
 
            if (tot < 0) continue;
 
            if (cnt & 1) ans = ans - nCr(tot + k - 1, k - 1, fact);
            else ans = ans + nCr(tot + k - 1, k - 1, fact);
 
            if (ans < 0) ans += mod;
            if (ans >= mod) ans -= mod;
        }
 
        printf("Case %d: %lld\n", cs + 1, ans);
    }
 
    return 0;
}
