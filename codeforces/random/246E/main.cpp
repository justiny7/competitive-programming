#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n, q, ans[N];
string s[N];
vector<int> adj[N], rt;
vector<pair<int, int>> qu[N];

struct dat {
    int sz = 0;
    map<int, set<string>> mp;

    void ins(int d, string x) {
        if (!mp[d].count(x)) {
            mp[d].insert(x);
            ++sz;
        }
    }
};

dat dfs(int v, int d = 0) {
    dat ret;
    ret.ins(d, s[v]);
    for (int u : adj[v]) {
        dat here = dfs(u, d + 1);
        if (here.sz > ret.sz)
            swap(ret, here);
        for (auto [d, x] : here.mp)
            for (auto i : x)
                ret.ins(d, i);
    }
    for (auto [x, i] : qu[v])
        if (ret.mp.count(d + x))
            ans[i] = ret.mp[d + x].size();
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1, p; i <= n; ++i) {
        cin >> s[i] >> p;
        if (!p)
            rt.push_back(i);
        else
            adj[p].push_back(i);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int v, k;
        cin >> v >> k;
        qu[v].emplace_back(k, i);
    }
    for (int v : rt)
        dfs(v);
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
