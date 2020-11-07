#include <bits/stdc++.h>
using namespace std;

int n, b, a;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> b >> a;
    int ca=a, cb=b;
    for (int i=0; i<n; ++i) {
        if (!ca && !cb)
            return cout << i << '\n', 0;
        int c; cin >> c;
        if (c) {
            if (cb && ca<a)
                --cb, ++ca;
            else
                --ca;
        }
        else {
            if (ca)
                --ca;
            else
                --cb;
        }
    }
    cout << n << '\n';
}

