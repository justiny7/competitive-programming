#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        string s=to_string(x);
        cout << ((s[0]-'0')-1)*10+(s.size()*(s.size()+1)/2) << '\n';
    }
}

