#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int asdf = 0; asdf < t; asdf++) {
        ll n, m;
        cin >> n >> m;
        ll p;
        if ((n*m)%2 == 1)
        	p = n*m+1;
        else
        	p = n*m;
        cout << p/2 << '\n';
    }

    return 0;
}