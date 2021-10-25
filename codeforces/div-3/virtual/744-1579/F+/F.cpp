#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int ans = 0;
    vector<char> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i])
            continue;

        int v = i;
        vector<int> here;
        while (!vis[v]) {
            here.push_back(a[v]);
            vis[v] = 1;
            (v += d) %= n;
        }

        int sz = here.size();
        int pref = 0, suff = 0;
        for (; pref < sz; ++pref)
            if (!here[pref])
                break;
        for (; suff < sz; ++suff)
            if (!here[sz - suff - 1])
                break;

        if (pref == sz) {
            cout << "-1\n";
            return;
        }

        ans = max(ans, pref + suff);

        for (int i = 1; i < sz; ++i)
            if (here[i])
                here[i] += here[i - 1];
        ans = max(ans, *max_element(here.begin(), here.end()));

    }
    
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

