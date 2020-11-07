#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (ll)((c-a)*(d-b)+1) << '\n';
    }
}
