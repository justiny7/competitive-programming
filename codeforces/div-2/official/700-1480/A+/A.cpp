#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        bool f=1;
        for (char &c:s) {
            if (f) {
                if (c=='a')
                    c='b';
                else
                    c='a';
            }
            else {
                if (c=='z')
                    c='y';
                else
                    c='z';
            }
            f^=1;
        }
        cout << s << '\n';
    }
}

