#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 69;
int bit[N];

void upd(int i, int x) {
    for (++i; i < N; i += i & -i)
        bit[i] += x;
}
void upd(int l, int r, int x) {
    upd(l, x);
    upd(r + 1, -x);
}
int query(int i) {
    int ret = 0;
    for (++i; i; i -= i & -i)
        ret += bit[i];
    return ret;
}

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ret; cin >> ret;
    return ret;
}
void guess(int x) {
    cout << "! " << x << endl;
}

int main() {
    int n, t, k, sz = 0;
    bool f = 1;
    cin >> n >> t;
    while (t--) {
        cin >> k;
        if (f) {
            for (; ; ++sz) {
                int c = min(sz * 10 + 10, n);
                upd(sz, sz, c - ask(1, c));
                if (c == n)
                    break;
            }
            f = 0;
        }
        int bl = 0, br = sz;
        while (bl < br) {
            int m = bl + br >> 1;
            if (query(m) >= k)
                br = m;
            else
                bl = m + 1;
        }
        int l = bl * 10 + 1, r = min(n, l + 9);
        while (l < r) {
            int m = l + r >> 1;
            if (m - ask(1, m) >= k)
                r = m;
            else
                l = m + 1;
        }
        guess(l);
        upd(bl, sz, -1);
    }
}
