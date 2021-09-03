#include <bits/stdc++.h>
using namespace std;

const int N = 4e6 + 69;
long long suff[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, MD;
    cin >> n >> MD;

    suff[n] = 1;
    for (int i = n - 1; i; --i) {
        int here = suff[i + 1];

        for (int j = 2; i * j <= n; ++j) {
            (here += suff[i * j]) %= MD;
            if ((i + 1) * j <= n)
                (here += MD - suff[(i + 1) * j]) %= MD;
        }

        suff[i] = (here + suff[i + 1]) % MD;
        // cout << i << " " << here << " " << suff[i] << '\n';
    }

    cout << (MD + suff[1] - suff[2]) % MD << '\n';
}

