#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 69;
int n; ll ans, o, a[N], b[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i], o += a[i] * b[i];
    ans = o;
    for (int i = 0; i < n; ++i) { //reverse about i
        ll cur = o;
        for (int j = 1; j + i < n && i - j >= 0; ++j) {
            cur -= a[i + j] * b[i + j] + a[i - j] * b[i - j];
            cur += a[i + j] * b[i - j] + a[i - j] * b[i + j];
            ans = max(ans, cur);
        }
    }
    for (int i = 0; i < n - 1; ++i) { //reverse between i and i + 1
        ll cur = o;
        for (int j = 0; j + i + 1 < n && i - j >= 0; ++j) {
            cur -= a[i + j + 1] * b[i + j + 1] + a[i - j] * b[i - j];
            cur += a[i + j + 1] * b[i - j] + a[i - j] * b[i + j + 1];
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
}
