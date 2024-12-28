#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<int> d;
    while (n--) {
        int x;
        cin >> x;
        d.push_back(x);
    }

    while (d.size() && d.back() == 0) {
        d.pop_back();
    }
    while (d.size() && d.front() == 0) {
        d.pop_front();
    }

    if (d.empty()) {
        cout << "0\n";
        return;
    }

    bool f = 0;
    while (d.size()) {
        f |= (d.back() == 0);
        d.pop_back();
    }

    cout << (f ? 2 : 1) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
