#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n==1) {
            cout << "! 1 1" << endl;
            continue;
        }
        char c;
        vector<int> small, big;
        for (int i=1; i+1<=n; i+=2) {
            cout << "? " << i << " " << i+1 << endl;
            cin >> c;
            if (c=='<')
                small.pb(i), big.pb(i+1);
            else
                small.pb(i+1), big.pb(i);
        }
        if (n&1)
            small.pb(n), big.pb(n);
        int cmin=small[0], cmax=big[0];
        for (int i=1; i<small.size(); ++i) {
            cout << "? " << cmin << " " << small[i] << endl;
            cin >> c;
            if (c=='>')
                cmin=small[i];
        }
        for (int i=1; i<big.size(); ++i) {
            cout << "? " << cmax << " " << big[i] << endl;
            cin >> c;
            if (c=='<')
                cmax=big[i];
        }
        cout << "! " << cmin << " " << cmax << endl;
    }
}

