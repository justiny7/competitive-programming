#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n<4) {
            cout << "-1\n";
            continue;
        }
        for (int i=(n&1)?n:n-1; i>=1; i-=2)
            cout << i << " ";
        cout << "4 2";
        for (int i=6; i<=n; i+=2)
            cout << " " << i;
        cout << '\n';
    }
}
