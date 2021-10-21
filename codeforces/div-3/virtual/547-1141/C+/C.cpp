#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n - 1);
    for (int &i : a)
        cin >> i;

    set<int> seen = {0};
    vector<int> res = {0};
    int cur = 0;
    for (int i = 0; i < n - 1; ++i) {
        cur += a[i];
        if (seen.count(cur)) {
            cout << "-1\n";
            return 0;
        }

        seen.insert(cur);
        res.push_back(cur);
    }

    int mn = *seen.begin(), mx = *seen.rbegin();
    if (mx - mn != n - 1) {
        cout << "-1\n";
        return 0;
    }

    int add = 1 - mn;
    for (int i = 0; i < n; ++i)
        cout << res[i] + add << " \n"[i == n - 1];
}

