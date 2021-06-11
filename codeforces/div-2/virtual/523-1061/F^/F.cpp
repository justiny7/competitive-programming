#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1569;
int n, k, h, qu[N];
vector<int> a;

bool ask(int u, int x, int v) {
    cout << "? " << u << " " << x << " " << v << endl;
    string ret; cin >> ret;
    return (ret == "Yes");
}

int get_leaf() {
    while (1) {
        shuffle(qu, qu + n, rng);
        int v = qu[0], u = qu[1];

        bool f = 1;
        for (int i = 2; i < n; ++i) {
            if (ask(u, v, qu[i])) {
                f = 0;
                break;
            }
        }

        if (f)
            return v;
    }
}
pair<int, int> get_leaves() {
    int v = get_leaf();
    while (1) {
        shuffle(qu, qu + n, rng);
        if (qu[0] == v)
            continue;

        a.clear();
        int u = qu[0], need = 2 * (h - 1) + 1;
        for (int i = 1; i < n; ++i) {
            if (qu[i] == v)
                continue;

            //printf("asking %d with %d and %d\n", qu[i], v, u);
            bool ret = ask(v, qu[i], u);
            if (ret) {
                a.push_back(qu[i]);
                --need;
            }
        }

        if (!need)
            return {u, v};
    }
}
void solve() {
    auto [st, en] = get_leaves();
    vector<int> cur = {st, a[0], en};

    for (int i = 1; i < a.size(); ++i) {
        vector<int> nxt = {cur[0]};
        bool f = 0;

        for (int j = 1; j < cur.size(); ++j) {
            if (!f && ask(cur[j - 1], a[i], cur[j])) {
                nxt.push_back(a[i]);
                f = 1;
            }
            nxt.push_back(cur[j]);
        }

        cur = nxt;
    }

    cout << "! " << cur[h] << endl;
}

int main() {
    cin >> n >> k;
    for (int sz = 1, p = k; sz + p <= n; )
        sz += p, p *= k, ++h;

    iota(qu, qu + n, 1);
    solve();
}
