#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    map<int, int> mp;
    for (int i : a)
        ++mp[i];

    vector<array<int, 2>> vals;
    for (auto [x, c] : mp)
        vals.push_back({x, c});

    int lans = -1, rans = -1, l = -1, r = -1;
    for (int i = 0; i < vals.size(); ++i) {
        if (vals[i][1] < k) {
            l = r = -1;
            continue;
        }

        if (i > 0 && vals[i][0] != vals[i - 1][0] + 1)
            l = r = -1;

        if (l < 0)
            l = vals[i][0];
        r = vals[i][0];

        if (r - l >= rans - lans) {
            lans = l;
            rans = r;
        }
    }

    if (~lans)
        cout << lans << " " << rans << '\n';
    else
        cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


