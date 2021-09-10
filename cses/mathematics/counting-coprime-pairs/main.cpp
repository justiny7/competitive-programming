#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int V = 1e6 + 69;
int n, cnt[V];

int spf[V], u[V];
void sieve() {
    for (ll i = 2; i < V; ++i) {
        if (!spf[i]) {
            spf[i] = i;
            for (ll j = i * i; j < V; j += i)
                if (!spf[j])
                    spf[j] = i;
        }
    }
}
void mobius() {
    for (int i = 1; i < V; ++i) {
        int cur = i, c = 0;
        while (cur > 1) {
            int nxt = cur / spf[cur];
            if (spf[nxt] == spf[cur])
                break;

            ++c;
            cur = nxt;
        }

        if (cur == 1)
            u[i] = (c & 1) ? -1 : 1;
    }
}

inline ll C2(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    sieve(); mobius();

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    ll ans = 0;
    for (int i = 1; i < V; ++i) {
        ll here = 0;
        for (int j = i; j < V; j += i)
            here += cnt[j];

        ans += C2(here) * u[i];
    }

    cout << ans << '\n';
}

