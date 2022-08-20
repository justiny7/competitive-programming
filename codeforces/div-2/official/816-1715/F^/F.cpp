#include <bits/stdc++.h>
using namespace std;

using ld = long double;

ld query(vector<array<int, 2>> q) {
    cout << "? " << q.size() << endl;
    for (auto [x, y] : q)
        cout << x << " " << y << endl;

    ld res;
    cin >> res;
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> xq, yq;
    xq.push_back({n + 1, 0});
    yq.push_back({0, m + 1});
    xq.push_back({0, 0});
    yq.push_back({0, 0});
    for (int i = 1; i < m; ++i) {
        xq.push_back({n, i});
        xq.push_back({0, i});
    }
    for (int i = 1; i < n; ++i) {
        yq.push_back({i, m});
        yq.push_back({i, 0});
    }
    xq.push_back({n, m});
    yq.push_back({n, m});
    xq.push_back({n + 1, m});
    yq.push_back({n, m + 1});

    ld x = n * query(xq) - 0.5, y = m * query(yq) - 0.5;
    cout << "! " << x << " " << y << endl;
}

