#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, a[N];
long long mn;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);
    
    for (int i = 0; i < n; ++i) {
        if (a[i] <= mn + 1)
            mn += a[i];
        else
            break;
    }

    cout << mn + 1 << '\n';
}

