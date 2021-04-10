#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 69;
int n, a[N], lst[N];
ll ans;
bool seen[N], sub[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        fill(seen + 1, seen + n + 1, 0);
        fill(sub + 1, sub + n + 1, 0);
        ll cnt = 0;
        for (int j = i - 1; j; --j) {
            if (a[j] == a[i])
                break;
            if (!seen[a[j]]) {
                seen[a[j]] = 1;
                ans += cnt++;
            }
            else {
                if (!sub[a[j]]) {
                    sub[a[j]] = 1;
                    --cnt;
                }
            }
        }
    }
    cout << ans << '\n';
}
