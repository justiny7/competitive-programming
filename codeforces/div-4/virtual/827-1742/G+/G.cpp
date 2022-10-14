#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    multiset<pair<int, int>, greater<pair<int, int>>> s;
    vector<int> z;
    for (int i : a)
        s.insert({i, i});

    while (n--) {
        if (s.size()) {
            int x = s.begin()->second;
            s.erase(s.begin());
            cout << x << " ";

            vector<pair<int, int>> add;
            for (auto [v, i] : s) {
                int nx = v & (~x);
                if (nx)
                    add.push_back({nx, i});
                else
                    z.push_back(i);
            }

            s.clear();
            for (auto p : add)
                s.insert(p);
        } else {
            cout << z.back() << " ";
            z.pop_back();
        }
    }

    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}

