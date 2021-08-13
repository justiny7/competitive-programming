#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69, L = 32;
int n, q, cnt[L], rem[L];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        int x, c = 0;
        cin >> x;

        while (x > 1)
            x /= 2, ++c;

        ++cnt[c];
    }

    while (q--) {
        int need, ans = 0;
        cin >> need;

        memset(rem, 0, sizeof(rem));

        for (int i = L - 1; ~i; --i) {
            if (!cnt[i])
                continue;

            int here = 1 << i, take = min(cnt[i], need / here);
            rem[i] += take, cnt[i] -= take;
            need -= take * here;
            ans += take;
        }

        if (need)
            cout << "-1\n";
        else
            cout << ans << '\n';

        for (int i = 0; i < L; ++i)
            cnt[i] += rem[i];
    }
}

