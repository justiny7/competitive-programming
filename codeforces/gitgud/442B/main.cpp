#include <bits/stdc++.h>
using namespace std;
using db=double;

const int mxN=101;
int n;
db p[mxN], ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(12) << fixed;
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> p[i];
    sort(p, p+n, greater<db>());
    for (int i=0; i<n; ++i) {
        db cur=0;
        for (int j=0; j<=i; ++j) {
            db c=p[j];
            for (int k=0; k<=i; ++k)
                if (k^j)
                    c*=(1-p[k]);
            cur+=c;
        }
        ans=max(ans, cur);
    }
    cout << ans << '\n';
}

