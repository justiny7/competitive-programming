#include <bits/stdc++.h>
using namespace std;

const int MX = 1e9 + 69, R = 1e5 + 69;

vector<int> primes;
bool p[R];
void get_primes() {
    memset(p, 1, sizeof(p));

    primes.push_back(2);
    for (long long i = 2; i * i < MX; i += 2)
        p[i] = 0;

    for (long long i = 3; i * i < MX; i += 2) {
        if (p[i]) {
            primes.push_back(i);
            for (long long j = i * i; j * j < MX; j += i)
                p[j] = 0;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    set<int> s = {1};
    int cur = 1;
    for (int p : primes) {
        while (n % p == 0) {
            cur *= p;
            n /= p;
            if (!s.count(cur)) {
                s.insert(cur);
                cur = 1;
            }

            if (s.size() == 3 && !s.count(n)) {
                cout << "YES\n";

                auto it = s.begin();
                cout << *(++it) << " " << *(++it) << " " << n << '\n';
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    get_primes();

    int t;
    cin >> t;
    while (t--)
        solve();
}

