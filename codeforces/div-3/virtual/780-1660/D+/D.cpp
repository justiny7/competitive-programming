#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> cur;
    int res = 0;
    int res_lf = n, res_rt = 0;

    for (int i = 0; i <= n; ++i) {
        int x;

        if (i < n)
            cin >> x;
        else
            x = 0;

        if (x == 0) {
            // cout << "> ";
            // for (int j : cur)
                // cout << j << " ";
            // cout << '\n';

            int c = 0;
            int m = 1;
            for (int j : cur) {
                if (abs(j) == 2)
                    ++c;
                if (j < 0)
                    m *= -1;
            }

            int lf = 1, ind = 0;
            int sz = cur.size();
            if (m < 0) {
                int reml = 0, remr = 0;
                int indl = 0, indr = sz - 1;
                for (; indl < sz; ++indl) {
                    if (abs(cur[indl]) == 2)
                        ++reml;
                    if (cur[indl] < 0)
                        break;
                }
                for (; ~indr; --indr) {
                    if (abs(cur[indr]) == 2)
                        ++remr;
                    if (cur[indr] < 0)
                        break;
                }

                if (reml > remr) {
                    c -= remr;
                    lf = 0;
                    ind = sz - indr;
                } else {
                    c -= reml;
                    ind = indl + 1;
                }
            }

            // cout << "! " << c << " " << lf << " " << ind << '\n';

            if (c > res) {
                res = c;
                if (lf) {
                    // cout << "here\n";
                    res_lf = ind + i - cur.size();
                    res_rt = n - i;
                } else {
                    res_rt = ind + n - i;
                    res_lf = i - cur.size();
                }
            }

            cur.clear();
        } else {
            cur.push_back(x);
        }
    }

    cout << res_lf << " " << res_rt << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

