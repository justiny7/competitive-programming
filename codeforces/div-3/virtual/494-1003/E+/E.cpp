#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 69;
int n, d, k, deg[N], dep[N];
set<int> ok;
vector<int> adj[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> d >> k;

    if (d >= n) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i <= d; ++i) {
        adj[i].push_back(i + 1);
        ++deg[i], ++deg[i + 1];

        if (deg[i] > k) {
            cout << "NO\n";
            return 0;
        }
    }
    
    for (int i = 1; i <= d + 1; ++i) {
        dep[i] = min(i - 1, d + 1 - i);
        if (deg[i] < k && dep[i] > 0)
            ok.insert(i);
    }

    int cur = d + 2;
    while (ok.size() && cur <= n) {
        int v = *ok.begin();

        adj[v].push_back(cur);
        adj[cur].push_back(v);
        ++deg[v], ++deg[cur];
        dep[cur] = dep[v] - 1;

        if (deg[v] == k)
            ok.erase(v);
        if (deg[cur] < k && dep[cur] > 0)
            ok.insert(cur);

        ++cur;
    }

    if (cur <= n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        for (int u : adj[i])
            if (i < u)
                cout << i << " " << u << '\n';
}

