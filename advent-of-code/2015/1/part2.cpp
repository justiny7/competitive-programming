#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    string s; cin >> s;
    int ans=0, cur=1;
    for (char c:s) {
        cur+=(c=='('?1:-1);
        if (cur==-1)
            return cout << ans << '\n', 0;
        ++ans;
    }
}

