#include <bits/stdc++.h>
using namespace std;

const int mxN=201;
int n, m, a[mxN], b[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<m; ++i)
        cin >> b[i];
    for (int x=0; x<(1<<9); ++x) {
        bool f=1;
        for (int i=0; i<n; ++i) {
            bool f2=0;
            for (int j=0; j<m; ++j)
                if (((a[i]&b[j])|x)==x)
                    f2=1;
            f&=f2;
        }
        if (f)
            return cout << x << '\n', 0;
    }
}


