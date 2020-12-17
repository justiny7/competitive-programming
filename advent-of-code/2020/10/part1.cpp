#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    int x, mx=0, c1=0, c3=0;
    vector<int> v={0};
    while (cin >> x)
        v.push_back(x), mx=max(mx, v.back());
    v.push_back(mx+3);
    sort(v.begin(), v.end());
    for (int i=1; i<v.size(); ++i) {
        if (v[i]-v[i-1]==1)
            ++c1;
        else if (v[i]-v[i-1]==3)
            ++c3;
    }
    cout << c1*c3 << '\n';
}

