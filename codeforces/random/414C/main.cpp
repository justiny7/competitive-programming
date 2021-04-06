#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int D = 20, N = D << 20;
int n, q, a[N];
ll ans, t[D][2];

void calc(int l = 0, int r = (1 << n), int d = 0) {
    if (d == n)
        return;
    int m = l + r >> 1;
    calc(l, m, d + 1); calc(m, r, d + 1);
    vector<int> here;
    int llst = l, rlst = m;
    for (int i = l, j = m; i < m || j < r; ) {
        if (j == r || (i < m && a[i] < a[j])) {
            if (a[i] != a[llst])
                llst = i;
            here.push_back(a[i]);
            if (a[rlst] != a[i])
                rlst = j;
            t[d][0] += rlst - m;
            ++i;
        }
        else {
            if (a[j] != a[rlst])
                rlst = j;
            here.push_back(a[j]);
            if (a[llst] != a[j])
                llst = i;
            t[d][1] += llst - l;
            ++j;
        }
    }
    for (int i = l; i < r; ++i)
        a[i] = here[i - l];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < (1 << n); ++i)
        cin >> a[i];
    calc();
    for (int i = 0; i < n; ++i)
        ans += t[i][0];
    cin >> q;
    while (q--) {
        int x; cin >> x;
        for (int i = n - x; i < n; ++i) {
            ans += t[i][1] - t[i][0];
            swap(t[i][0], t[i][1]);
        }
        cout << ans << '\n';
    }
}
