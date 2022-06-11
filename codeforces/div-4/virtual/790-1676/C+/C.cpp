#include <bits/stdc++.h>
using namespace std;

int cost(string a, string b) {
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        int aa = a[i] - 'a', bb = b[i] - 'a';
        if (aa < bb)
            swap(aa, bb);
        res += aa - bb;
    }

    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (string &s : a)
        cin >> s;

    int res = INT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            res = min(res, cost(a[i], a[j]));

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


