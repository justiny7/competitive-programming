#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
int n, q;
int spf[N], u[N];
vector<int> d[N];
ll a[N], b[N];

/*
b[i] = u[1] * a[i] + u[2] * a[i * 2] + u[3] * a[i * 3] + ...
*/

void prep() {
    for (int i = 1; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * 2; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    for (int i = 1; i < N; i++) {
        int x = i, c = 0;
        while (x != 1) {
            if (spf[x] == spf[x / spf[x]]) {
                c = -1;
                break;
            }

            x /= spf[x], c++;
        }

        if (c != -1) {
            u[i] = (c & 1) ? -1 : 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    prep();

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            b[i] += a[j] * u[j / i];
            d[j].push_back(i);
        }
    }

    while (q--) {
        int t, i;
        cin >> t >> i;

        if (t == 1) {
            int x;
            cin >> x;

            for (int j : d[i]) {
                int c = i / j;
                b[c] += (x - a[i]) * u[j];
            }

            a[i] = x;
        } else {
            cout << b[i] << '\n';
        }
    }
}

