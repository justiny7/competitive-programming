#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 2e5 + 10;
int n; ll a[mxN], b[mxN * 2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0, j = 0; i < n; ++i, j = (j + 2) % n)
        b[i] = b[i + n] = a[j];
    ll ans = 0, cur = 0;
    for (int i = 0; i < n / 2; ++i)
        cur += b[i];
    for (int i = n / 2; i < n * 2; ++i) {
        cur += b[i];
        ans = max(ans, cur);
        cur -= b[i - n / 2];
    }
    cout << ans << '\n';
}
