#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;

string ts(char a, char b) {
    return (string(1, a)+string(1, b));
}

bool ok(char a, char b, char c, string str) {
    return (ts(a, b)!=str && ts(b, c)!=str && (n>1 && ts(c, a)!=str || n==1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s >> t;
    if (t[0]^t[1] && s[0]^s[1]) {
        for (char c='a'; c<='c'; ++c)
            for (char c2='a'; c2<='c'; ++c2)
                for (char c3='a'; c3<='c'; ++c3) {
                    if (c==c2 || c==c3 || c2==c3)
                        continue;
                    if (ts(c, c2)!=s && ts(c2, c3)!=s && ts(c, c2)!=t && ts(c2, c3)!=t) {
                        cout << "YES\n";
                        for (int i=0; i<n; ++i)
                            cout << c;
                        for (int i=0; i<n; ++i)
                            cout << c2;
                        for (int i=0; i<n; ++i)
                            cout << c3;
                        cout << '\n';
                        return 0;
                    }
                }
    }
    for (char c='a'; c<='c'; ++c)
        for (char c2='a'; c2<='c'; ++c2)
            for (char c3='a'; c3<='c'; ++c3) {
                if (c==c2 || c==c3 || c2==c3)
                    continue;
                if (ok(c, c2, c3, s) && ok(c, c2, c3, t)) {
                    cout << "YES\n";
                    for (int i=0; i<n; ++i)
                        cout << c << c2 << c3;
                    cout << '\n';
                    return 0;
                }
            }
    cout << "NO\n";
}

