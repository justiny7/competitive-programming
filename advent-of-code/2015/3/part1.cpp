#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;

set<pii> vis;

int main() {
    freopen("test.txt", "r", stdin);
    string s; cin >> s;
    int x=0, y=0;
    vis.emplace(x, y);
    for (char c:s) {
        if (c=='^')
            ++y;
        else if (c=='>')
            ++x;
        else if (c=='<')
            --x;
        else
            --y;
        vis.emplace(x, y);
    }
    cout << vis.size() << '\n';
}

