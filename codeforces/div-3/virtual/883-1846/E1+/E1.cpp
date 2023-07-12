#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int Q = 1e6 + 1;
bool ok[Q];
void go() {
    for (int i = 2; i < Q; ++i) {
        ll p = i, s = p + 1;
        while (s < Q) {
            p *= i;
            s += p;
            
            if (s < Q)
                ok[s] = 1;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << (ok[n] ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    go();

    int t;
    cin >> t;
    while (t--)
        solve();
}

