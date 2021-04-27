#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 59;
int n, c, mp[N * 2];
string s, q(N * 2, ' ');
set<int> ops;

//Segtree {{{
int mn[N * 4], mx[N * 4], lz[N * 4];

inline void push(int l, int r, int v) {
    if (l != r) {
        mn[v << 1] += lz[v];
        mn[v << 1 | 1] += lz[v];
        mx[v << 1] += lz[v];
        mx[v << 1 | 1] += lz[v];
        lz[v << 1] += lz[v];
        lz[v << 1 | 1] += lz[v];
    }
    lz[v] = 0;
}
void upd(int ql, int qr, int x, int l = 0, int r = c - 1, int v = 1) {
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr) {
        mn[v] += x, mx[v] += x, lz[v] += x;
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    upd(ql, qr, x, l, m, v << 1);
    upd(ql, qr, x, m + 1, r, v << 1 | 1);
    mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
    mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    int sum = 0;
    for (int cur = 0, i = 0; i < n; ++i) {
        char x = s[i];
        if (x == 'R')
            ++cur;
        else if (x == 'L')
            cur = max(0, cur - 1);
        else
            ops.insert(cur);
    }
    for (int i : ops)
        mp[i] = c++;
    for (int cur = 0, i = 0; i < n; ++i) {
        char x = s[i];
        if (x == 'R')
            ++cur;
        else if (x == 'L')
            cur = max(0, cur - 1);
        else if (x == '(') {
            if (q[cur] == ')')
                sum += 2, upd(mp[cur], c - 1, 2);
            else if (q[cur] != '(')
                ++sum, upd(mp[cur], c - 1, 1);
        }
        else if (x == ')') {
            if (q[cur] == '(')
                sum -= 2, upd(mp[cur], c - 1, -2);
            else if (q[cur] != ')')
                --sum, upd(mp[cur], c - 1, -1);
        }
        else {
            if (q[cur] == ')')
                ++sum, upd(mp[cur], c - 1, 1);
            else if (q[cur] == '(')
                --sum, upd(mp[cur], c - 1, -1);
        }
        if (x != 'R' && x != 'L')
            q[cur] = x;
        if (mn[1] >= 0 && sum == 0)
            cout << mx[1];
        else
            cout << -1;
        cout << " \n"[i == n - 1];
    }
}
