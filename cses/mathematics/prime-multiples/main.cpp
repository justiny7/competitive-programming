#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int K = 20;
int k; ll n, ans, a[K];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
        cin >> a[i];
    for (int i = 1; i < (1 << k); ++i) {
        int c = __builtin_popcount(i);
        ll m = (c & 1) ? 1 : -1, here = n;
        for (int j = 0; j < k; ++j)
            if (i & (1 << j))
                here /= a[j];
        ans += here * m;
    }
    cout << ans << '\n';
}
