#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    bool f;
    int ans=0, cnt=0;
    map<char, int> cur;
    while (1) {
        getline(cin, s);
        if (s.empty()) {
            if (f)
                break;
            for (char c='a'; c<='z'; ++c)
                ans+=(cur[c]==cnt);
            f=1, cnt=0;
            cur.clear();
            continue;
        }
        ++cnt, f=0;
        for (char c:s)
            ++cur[c];
    }
    cout << ans << '\n';
}

