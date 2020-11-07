#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, m;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << min(a, b) << " " << max(a, b) << '\n';
    }
}
