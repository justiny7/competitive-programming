#include <bits/stdc++.h>
using namespace std;

int t;

int main(void) {
    cin >> t;
    while (t--) {
        long long y, x, diag, big;
        cin >> y >> x;
        big=max(y, x);
        diag=big*big-big+1;
        if (y==x)
            cout << diag << '\n';
        else if (y>x && y&1)
            cout << diag-(y-x) << '\n';
        else if (y>x && !(y&1))
            cout << diag+(y-x) << '\n';
        else if (y<x && x&1)
            cout << diag-(y-x) << '\n';
        else if (y<x && !(x&1))
            cout << diag+(y-x) << '\n';
    }
}

