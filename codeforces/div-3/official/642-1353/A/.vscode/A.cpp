#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int asdf = 0; asdf < t; asdf++) {
        int n, m;
        cin >> n >> m;

        if (n == 1)
            cout << "0\n";
        else if (n == 2)
            cout << m << '\n';
        else
            cout << 2*m << '\n';
    }

    return 0;
}