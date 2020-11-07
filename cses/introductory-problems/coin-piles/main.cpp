#include <bits/stdc++.h>
using namespace std;

int a, b, t;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a>b)
            swap(a, b);
        if (a==0 && b!=0) {
            cout << "NO\n";
            continue;
        }
        if (a*2<b) {
            cout << "NO\n";
            continue;
        }
        b-=(b-a)*2;
        if (b%3==0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
