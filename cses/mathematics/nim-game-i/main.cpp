#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int c=0;
        for (int i=0; i<n; ++i) {
            int a; cin >> a;
            c^=a;
        }
        if (c)
            cout << "first\n";
        else
            cout << "second\n";
    }
}


