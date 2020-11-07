#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, x, l, r;
pair<int, int> a[200001];

int main(void) {
    cin >> n >> x;
    if (n==1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i=0; i<n; ++i) {
        cin >> a[i].fi;
        a[i].se=i+1;
    }
    r=n-1;
    sort(a, a+n);
    while (a[l].fi+a[r].fi!=x) {
        if (a[l].fi+a[r].fi>x) {
            if (r-1>l)
                r--;
            else {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        else {
            if (l+1<r)
                l++;
            else {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    cout << a[l].se << " " << a[r].se << '\n';
}

