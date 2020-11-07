#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(int a) {
    if (a == 1)
        return false;
    if (a == 2 || a == 3)
        return true;
    for (int i = 2; i*i <= a; i++) {
        if (a%i == 0)
            return false;
    }
    return true;
}

int smallest_div(int a) {
    for (int i = 2; i*i <= a; i++) {
        if (a%i == 0)
            return i;
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int t;
    cin >> t;
    for (int asdf = 0; asdf < t; asdf++) {
        ll n, k;
        cin >> n >> k;

        if (n%2 == 0) {
            cout << n + 2*k << endl;
        }
        else {
            if (is_prime(n)) {
                n *= 2;
                cout << n + 2*(k-1) << endl;
            }
            else {
                n += smallest_div(n);
                //cout << "smallest div:" << n << '\n';
                cout << n + 2*(k-1) << endl;
            }
        }
    }

    return 0;
}