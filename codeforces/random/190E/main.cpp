#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// DSU {{{
struct DSU {
    vector<int> dsu;
    void init(int n) {
        dsu.assign(n, -1);
    }
    
    int find(int v) {
        return dsu[v] < 0 ? v : dsu[v] = find(dsu[v]);
    }
    int size(int v) {
        return -dsu[find(v)];
    }
    bool merge(int u, int v) {
        if ((u = find(u)) == (v = find(v)))
            return 0;
        if (dsu[u] < dsu[v])
            swap(u, v);
        dsu[v] += dsu[u], dsu[u] = v;
        return 1;
    }
    bool same_set(int u, int v) {
        return find(u) == find(v);
    }
};
// }}}

const int N = 5e5 + 69;

ll hsh(ll u, ll v) {
    return u * N + v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    set<ll> no;
    while (m--) {
        int u, v;
        cin >> u >> v;

        if (u > v)
            swap(u, v);
        
        no.insert(hsh(u, v));
    }

    DSU d;
    d.init(N);

    set<int> active;
    for (int i = 1; i <= n; ++i)
        active.insert(i);

    while (active.size()) {
        int cur = *active.begin();
        active.erase(cur);

        queue<int> q;
        q.push(cur);
        while (q.size()) {
            int v = q.front();
            q.pop();

            d.merge(cur, v);
            for (auto it = active.begin(); it != active.end(); ) {
                if (no.count(hsh(min(v, *it), max(v, *it))))
                    ++it;
                else {
                    q.push(*it);
                    active.erase(it++);
                }
            }
        }
    }

    map<int, vector<int>> mp;
    for (int i = 1; i <= n; ++i)
        mp[d.find(i)].push_back(i);

    cout << mp.size() << '\n';
    for (auto &[x, v] : mp) {
        cout << v.size();
        for (int i : v)
            cout << " " << i;
        cout << '\n';
    }

}

