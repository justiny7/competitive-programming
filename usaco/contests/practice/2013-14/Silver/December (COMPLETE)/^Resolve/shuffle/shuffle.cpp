//Yay worked second try after messing up a rotation
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, m, q, ans[mxN], app[mxN];

int main() {
    ifstream cin("shuffle.in");
    ofstream cout("shuffle.out");
    cin >> n >> m >> q;
    for (int i=1; i<=m; ++i) {
        int a; cin >> a;
        app[a]=i;
    }
    for (int i=1; i<=n; ++i)
        app[i]=(i<=m?app[i]:i), ans[i]=i;
    rotate(app+1, app+2, app+n+1);
    int r=n-m+1;
    while (r) { //Binary exponentiation
        if (r&1)
            for (int i=1; i<=n; ++i)
                ans[i]=app[ans[i]];
        int ret[mxN];
        for (int i=1; i<=n; ++i)
            ret[i]=app[i];
        for (int i=1; i<=n; ++i)
            app[i]=ret[app[i]];
        r>>=1;
    }
    rotate(ans+1, ans+m, ans+n+1);
    reverse(ans+1, ans+n+1);
    while (q--) {
        int a; cin >> a;
        cout << ans[a] << '\n';
    }
}

