#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
vector<int> ans;
vector<array<int, 2>> adj[1 << N];

void dfs(int v = 0) {
    while (adj[v].size()) {
        auto [u, w] = adj[v].back();
        adj[v].pop_back();
        ans.push_back(w);
        dfs(u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    cout << string(--n, '0');

    int msk = (1 << n) - 1;
    for (int i = 0; i < (1 << n); ++i) {
        adj[i].push_back({(i << 1) & msk, 0});
        adj[i].push_back({((i << 1) | 1) & msk, 1});
    }

    dfs();

    for (int i : ans)
        cout << i;
    cout << '\n';
}

