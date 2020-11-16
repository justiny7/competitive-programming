#include <bits/stdc++.h>
using namespace std;

int p, y;
vector<int> primes;
void sieve() {
    vector<bool> prime(1e5+1, 1);
    for (int i=2; i*i<=1e9; ++i)
        if (prime[i]) {
            primes.push_back(i);
            for (long long j=i*i; j*j<=1e9; j+=i)
                prime[j]=0;
        }
}
bool is_prime(int x) {
    for (int i=2; i*i<=x; ++i)
        if (x%i==0)
            return 0;
    return 1;
}
bool ok(int x) {
    if (is_prime(x))
        return 1;
    for (int i:primes)
        if (i<=p && x%i==0)
            return 0;
    return 1;
}

int main() {
    sieve();
    cin.tie(0)->sync_with_stdio(0);
    cin >> p >> y;
    for (; y>p; --y)
        if (ok(y))
            return cout << y << '\n', 0;
    cout << "-1\n";
}

