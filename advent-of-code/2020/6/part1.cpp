#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    bool f;
    int ans=0;
    set<char> cur;
    while (1) {
        getline(cin, s);
        if (s.empty()) {
            if (f)
                break;
            f=1;
            ans+=cur.size();
            cur.clear();
            continue;
        }
        f=0;
        for (char c:s)
            cur.insert(c);
    }
    cout << ans << '\n';
}

