#include <bits/stdc++.h>
using namespace std;

using ll = long long;

set<ll> incr[9], decr[9];

void gen_incr(string cur = "") {
    if (cur.size() > 8) {
        return;
    }

    if (cur.size()) {
        incr[cur.size()].insert(stoll(cur));
    }
    for (char c = (cur.empty() ? '1' : cur.back()); c <= '8'; c++) {
        cur += c;
        gen_incr(cur);
        cur.pop_back();
    }
}
void gen_decr(string cur = "") {
    if (cur.size() > 8) {
        return;
    }

    if (cur.size()) {
        decr[cur.size()].insert(stoll(cur));
    }
    for (char c = (cur.empty() ? '8' : cur.back()); c >= '1'; c--) {
        cur += c;
        gen_decr(cur);
        cur.pop_back();
    }
}

ll solve(ll x, ll M) {
    if (x < 0) {
        return 0;
    }

    ll p10 = 1, res = 0;
    for (int len = 1; len <= 17; len += 2) {
        int hf = len / 2;

        for (ll mid = 1; mid <= 9; mid++) {
            if ((mid * p10) % M) {
                continue;
            }

            if (len <= to_string(x).size()) {
                ll rt = 0, mx = 0;
                for (ll y : incr[hf]) {
                    if ((y * p10 * 10) % M == 0 && (y % 10 < mid)) {
                        if (y * p10 * 10 > x) {
                            break;
                        }

                        mx = y * p10 * 10;
                        rt++;
                    }
                }
                for (ll y : decr[hf]) {
                    if (y % M == 0 && (y % 10 < mid)) {
                        if (mx + mid * p10 + y <= x) {
                            res += rt;
                        }
                    }
                }
            } else {
                break;
            }
        }

        p10 *= 10;
    }

    // cout << x << " " << res << '\n';
    return res;
}

void solve() {
    ll A, B, M;
    cin >> A >> B >> M;

    cout << solve(B, M) - solve(A - 1, M) << '\n';
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    gen_incr();
    gen_decr();
    incr[0].insert(0);
    decr[0].insert(0);

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}
