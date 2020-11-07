#include <bits/stdc++.h>
using namespace std;

const int mxN=51;
int n, k, a[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n, greater<int>());
    for (int i=0; i<min(n, k); ++i)
        cout << "1 " << a[i] << '\n';
    k-=min(k, n);
    int cur=1, cur2=1;
    while (k) {
        cout << cur+1;
        for (int i=0; i<cur; ++i)
            cout << " " << a[i];
        cout << " " << a[cur2++] << '\n';
        if (cur2==n)
            ++cur, cur2=cur;
        --k;
    }
}

