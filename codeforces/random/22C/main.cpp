#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, v;
vector<int> grp;
set<array<int, 2>> have;

void add_edge(int u, int v) {
    if (!have.count({u, v})) {
        have.insert({u, v});
        cout << u << " " << v << '\n';
    }

    if (have.size() == m)
        exit(0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> v;

    if (m < n - 1 || m > 1LL * (n - 1) * (n - 2) / 2 + 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = (v < n ? 1 : 2); grp.size() < n - 1; ++i)
        grp.push_back(i);

    add_edge((v < n ? v : 1), n);

    for (int i = 1; i < n - 1; ++i)
        add_edge(grp[i - 1], grp[i]);

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n - 1; ++j)
            add_edge(grp[i], grp[j]);
}

