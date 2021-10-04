#include <bits/stdc++.h>
using namespace std;

// even length
// --> set in AND = unset in XOR

const int N = 1e6 + 69, L = 20;
int n, ans, a[N], pref[N];
int lst[2][N]; // lst[i][j] = last time we saw j on even/odd position

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // for each bit, check if it can be an upper bound
    for (int i = L, msk = 0; ~i; msk |= (1 << i--)) {
        // i has to be set in entire subarray, xor of bits greater than i must be 0
        // cout << i << " " << bitset<10>(msk) << '\n';
        for (int j = 1; j <= n; ++j)
            pref[j] = pref[j - 1] ^ (a[j] & msk);

        // for (int j = 1; j <= n; ++j)
            // cout << pref[j] << " \n"[j == n];

        memset(lst, -1, sizeof(lst));
        for (int l = 1, r = 1; l <= n; ++l) {
            if (!(a[l] & (1 << i)))
                continue;

            r = l;
            while (r + 1 <= n && (a[r + 1] & (1 << i)))
                ++r;

            lst[(l - 1) & 1][0] = l - 1;
            for (int j = l; j <= r; ++j) {
                if (lst[j & 1][pref[j] ^ pref[l - 1]] < l - 1)
                    lst[j & 1][pref[j] ^ pref[l - 1]] = j;
                else
                    // cout << "! " << j << '\n',
                    ans = max(ans, j - lst[j & 1][pref[j] ^ pref[l - 1]]);
            }

            l = r;
        }

        // cout << ans << '\n';
    }

    cout << ans << '\n';
}

