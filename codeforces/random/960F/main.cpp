#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, ans;

//ST {{{
struct ST {
    struct node {
        int val;
        node *lc, *rc;
        node() : lc(nullptr), rc(nullptr), val(0) {}
        void upd(int i, int x, int l, int r) {
            if (l == r) {
                val = x;
                return;
            }
            int m = l + r >> 1;
            if (i <= m) {
                if (!lc)
                    lc = new node();
                lc->upd(i, x, l, m);
            }
            else {
                if (!rc)
                    rc = new node();
                rc->upd(i, x, m + 1, r);
            }
            val = 0;
            if (lc)
                val = max(val, lc->val);
            if (rc)
                val = max(val, rc->val);
        }
        int query(int lq, int rq, int l, int r) {
            if (r < lq || l > rq)
                return 0;
            if (l >= lq && r <= rq)
                return val;
            int m = l + r >> 1, ret = 0;
            if (lc)
                ret = max(ret, lc->query(lq, rq, l, m));
            if (rc)
                ret = max(ret, rc->query(lq, rq, m + 1, r));
            return ret;
        }
    };

    node *root = new node();
    void upd(int i, int x) {
        root->upd(i, x, 0, N);
    }
    int query(int l, int r) {
        return root->query(l, r, 0, N);
    }
} t[N];
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int u, v, w, ret;
        cin >> u >> v >> w;
        ret = t[u].query(0, w - 1);
        t[v].upd(w, ret + 1);
        ans = max(ans, ret + 1);
    }
    cout << ans << '\n';
}
