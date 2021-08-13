#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    set<int, greater<>> have;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        ++cnt[x];
        have.insert(x);
    }

    if (n < 6) {
        cout << "0 0 0\n";
        return;
    }

    vector<int> cur;
    for (int i : have)
        cur.push_back(i);

    int g = cnt[cur[0]], s = 0, b = 0;
    int ptr = 1;
    while (ptr < cur.size() && s <= g) {
        s += cnt[cur[ptr]];
        ++ptr;
    }
    while (ptr < cur.size() && g + s + b + cnt[cur[ptr]] <= n / 2) {
        b += cnt[cur[ptr]];
        ++ptr;
    }

    if (g >= s || g >= b || s + g + b > n / 2)
        cout << "0 0 0\n";
    else
        cout << g << " " << s << " " << b << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

