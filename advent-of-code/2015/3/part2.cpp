#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;

set<pii> vis;

int main() {
    freopen("test.txt", "r", stdin);
    string s; cin >> s;
    int x1=0, x2=0, y1=0, y2=0, f=1;
    vis.emplace(0, 0);
    for (char c:s) {
        if (c=='^')
            f?++y1:++y2;
        else if (c=='>')
            f?++x1:++x2;
        else if (c=='<')
            f?--x1:--x2;
        else
            f?--y1:--y2;
        f?vis.emplace(x1, y1):vis.emplace(x2, y2);
        f^=1;
    }
    cout << vis.size() << '\n';
}

