#include <bits/stdc++.h>
using namespace std;

const int mxN=16;
int n, lst;
bool vis[1<<mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cout << string(n, '0') << '\n';
    vis[0]=1;
    for (int i=1; i<(1<<n); ++i) {
        for (int j=0; j<n; ++j) {
            if (!vis[lst^(1<<j)]) {
                lst^=(1<<j);
                for (int k=n-1; ~k; --k)
                    cout << bool(lst&(1<<k));
                cout << '\n';
                vis[lst]=1;
                break;
            }
        }
    }
}

