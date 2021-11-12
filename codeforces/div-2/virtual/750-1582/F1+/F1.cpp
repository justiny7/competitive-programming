#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69, K = 569;
int n;
bitset<K> dp[K], res;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    dp[0][0] = 1;
    while (n--) {
        int x;
        cin >> x;

        bitset<K> here;
        for (int i = 0; i < x; ++i)
            here |= dp[i];
        for (int i = 0; i < K; ++i)
            if (here[i])
                dp[x][x ^ i] = 1;
    }

    for (int i = 0; i < K; ++i)
        res |= dp[i];

    cout << res.count() << '\n';
    for (int i = 0; i < K; ++i)
        if (res[i])
            cout << i << " ";
    cout << '\n';

}

