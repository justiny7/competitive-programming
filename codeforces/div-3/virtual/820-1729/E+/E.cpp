#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll query(ll a, ll b) {
    cout << "? " << a << " " << b << endl;

    ll res;
    cin >> res;

    if (res == 0)
        exit(0);

    return res;
}

int main() {
    for (int i = 3; ; ++i) {
        ll a = query(1, i), b = query(i, 1);

        if (a < 0 || b < 0) {
            cout << "! " << i - 1 << endl;
            return 0;
        }
        if (a != b) {
            cout << "! " << a + b << endl;
            return 0 ;
        }
    }
}

