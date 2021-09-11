#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 69;
int pref[N];

void solve() {
    int a, b;
    cin >> a >> b;

    if (pref[a - 1] == b)
        cout << a << '\n';
    else if ((pref[a - 1] ^ b) == a)
        cout << a + 2 << '\n';
    else
        cout << a + 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i < N; ++i)
        pref[i] = pref[i - 1] ^ i;

    int t;
    cin >> t;
    while (t--)
        solve();
}

