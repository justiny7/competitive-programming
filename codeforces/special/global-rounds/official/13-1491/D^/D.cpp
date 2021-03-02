#include <bits/stdc++.h>
using namespace std;

void solve() {
    int b, e;
    cin >> b >> e;
    if (b>e) {
        cout << "NO\n";
        return;
    }
    int cur=0;
    bool ok=1;
    for (int i=0; i<31; ++i) {
        if (b&(1<<i))
            ++cur;
        if (e&(1<<i))
            --cur;
        ok&=(cur>=0);
    }
    cout << (ok?"YES":"NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

