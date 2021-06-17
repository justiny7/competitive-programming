#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, m;
set<pair<int, int>> o, e;
map<pair<int, int>, int> edges;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    while (m--) {
        char op; cin >> op;

        if (op == '+') {
            int u, v; char c;
            cin >> u >> v >> c;

            if (edges.count(make_pair(v, u))) {
                if (edges[make_pair(v, u)] == c)
                    e.emplace(min(u, v), max(u, v));
                else
                    o.emplace(min(u, v), max(u, v));
            }

            edges[make_pair(u, v)] = c;
        }
        else if (op == '-') {
            int u, v;
            cin >> u >> v;

            pair<int, int> cur = {min(u, v), max(u, v)};
            if (e.count(cur))
                e.erase(cur);
            else if (o.count(cur))
                o.erase(cur);

            edges.erase(make_pair(u, v));
        }
        else {
            int k; cin >> k;

            bool f = bool(e.size());
            if (k & 1)
                f |= bool(o.size());

            cout << (f ? "YES" : "NO") << '\n';
        }
    }
}
