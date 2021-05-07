#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 69;
int n, o, a[N];

int query(int t, int i, int j, int x) {
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    int ret; cin >> ret;
    return ret;
}

int main() {
    int t; cin >> t;
    while (t--) {
        o = 0;
        cin >> n;
        for (int i = 1; i <= n; i += 2) {
            int p = (i == n ? 1 : i + 1);
            int q = query(2, i, p, 1);
            if (q == 1) {
                o = i;
                break;
            }
            else if (q == 2) {
                if (query(2, p, i, 1) == 1) {
                    o = p;
                    break;
                }
            }
        }
        assert(o);
        for (int i = 1; i <= n; ++i) {
            if (i == o)
                a[i] = 1;
            else
                a[i] = query(1, o, i, n - 1);
        }
        cout << "!";
        for (int i = 1; i <= n; ++i)
            cout << " " << a[i];
        cout << endl;
    }
}
