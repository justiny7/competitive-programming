#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    if (m % n) {
        cout << "-1\n";
        return 0;
    }

    int c = 0;
    m /= n;
    while (m % 2 == 0)
        m /= 2, ++c;
    while (m % 3 == 0)
        m /= 3, ++c;

    if (m != 1)
        cout << "-1\n";
    else
        cout << c << '\n';
}

