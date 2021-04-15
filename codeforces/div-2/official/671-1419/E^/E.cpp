#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n, x = n;
    map<int, int> fact;
    set<int> divs;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.insert(i);
            divs.insert(n / i);
        }
        if (i == 1)
            continue;
        while (x % i == 0)
            x /= i, ++fact[i];
    }
    if (x > 1)
        ++fact[x];
    if (fact.size() == 2 && fact.begin()->second == 1 && next(fact.begin())->second == 1) {
        for (auto [p, c] : fact)
            cout << p << " ";
        cout << n << "\n1\n";
        return;
    }
    map<int, vector<int>> mp;
    set<int> have;
    vector<int> v;
    for (auto [p, c] : fact)
        v.push_back(p);
    int sz = v.size();
    for (int i = 0; i < sz; ++i) {
        int a = v[i], b = v[(i + 1) % sz];
        have.insert(a * b);
    }
    for (int i : have)
        divs.erase(i);
    divs.erase(n);
    for (int i : v) {
        vector<int> added;
        for (int j : divs)
            if (j % i == 0)
                added.push_back(j);
        for (int j : added) {
            mp[i].push_back(j);
            divs.erase(j);
        }
    }
    for (int i = 0; i < sz; ++i) {
        int a = v[i], b = v[(i + 1) % sz];
        for (int j : mp[a]) {
            if (!have.count(j)) {
                cout << j << " ";
                have.insert(j);
            }
        }
        if (sz > 2 || i != 1)
            cout << a * b << " ";
    }
    if (!have.count(n))
        cout << n;
    cout << "\n0\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
