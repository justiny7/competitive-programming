#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;

ll n, x;
pair<ll, int> a[5001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i=0; i<n; ++i) {
        cin >> a[i].fi;
        a[i].se=i+1;
    }
    sort(a, a+n);
    for (int i=0; i<n; ++i) {
        int l=i+1, r=n-1;
        ll k=x-a[i].fi;
        while (l<r) {
            if (a[l].fi+a[r].fi==k) {
                cout << a[l].se << " " << a[r].se << " " << a[i].se << '\n';
                return 0;
            }
            if (a[l].fi+a[r].fi<k)
                ++l;
            else
                --r;
        }
    }
    cout << "IMPOSSIBLE\n";
}
