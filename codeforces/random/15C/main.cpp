#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll get(ll x) {
    if (x % 4 == 0)
        return x;
    else if (x % 4 == 1)
        return 1;
    else if (x % 4 == 2)
        return x + 1;
    else
        return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        ans ^= get(x - 1) ^ get(x + y - 1);
    }
    if (ans)
        cout << "tolik\n";
    else
        cout << "bolik\n";
}
