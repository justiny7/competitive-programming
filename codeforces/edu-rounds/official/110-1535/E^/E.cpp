#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 69, L = 20;
int n, q, lift[N][L];
ll amt[N], c[N];

int main() {
    memset(lift, -1, sizeof(lift));
    cin.tie(0)->sync_with_stdio(0);
    cin >> q >> amt[0] >> c[0];
    for (int i = 1; i <= q; ++i) {
        int t; cin >> t;
        if (t & 1) {
            int p, x, y;
            cin >> p >> x >> y;
            amt[i] = x, c[i] = y;
            lift[i][0] = p;
            for (int j = 1; j < L; ++j)
                lift[i][j] = lift[lift[i][j - 1]][j - 1];
        }
        else {
            int v, x;
            cin >> v >> x;
            ll buy = 0, cst = 0;
            while (x > 0) {
                int cur = v;
                for (int j = L - 1; ~j; --j)
                    if (~lift[cur][j] && amt[lift[cur][j]])
                        cur = lift[cur][j];
                ll take = min(amt[cur], (ll)x);
                x -= take, amt[cur] -= take;
                buy += take;
                cst += take * c[cur];
                if (cur == v)
                    break;
            }
            cout << buy << " " << cst << endl;
        }
    }
}
