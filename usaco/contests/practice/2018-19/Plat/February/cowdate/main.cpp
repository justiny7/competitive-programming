#include <bits/stdc++.h>
using namespace std;
using db = long double;

const int N = 1e6 + 69;
int n;
db ans, p[N], cp[N], q[N], pref[N]; // cp = compliment, q = pref sum on p[i] / cp[i], pref = pref mul on cp

// Formula for interval [l, r]: (sum of p[i] / cp[i]) * (product of cp[i]), l <= i <= r
db get(int l, int r) {
    return (q[r] - q[l - 1]) * (pref[r] / pref[l - 1]);
}

int main() {
    ifstream cin("cowdate.in");
    ofstream cout("cowdate.out");

    cin >> n;
    pref[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i], p[i] /= 1e6;
        cp[i] = pref[i] = 1 - p[i];
        q[i] = p[i] / cp[i];
        ans = max(ans, p[i]);

        pref[i] *= pref[i - 1];
        q[i] += q[i - 1];
    }

    //for (int i = 0; i <= n; ++i)
    //cout << i << " " << p[i] << " " << cp[i] << " " << pref[i] << " " << q[i] << '\n';

    int l = 1, r = 1;
    while (l <= r) {
        while (r < n && get(l, r + 1) > get(l, r)) {
            ++r;
            //cout << "> " << l << " " << r << " " << get(l, r) << '\n';
        }

        ans = max(ans, get(l, r));
        ++l;
    }

    cout << (int)floor(ans * 1e6) << '\n';
}
