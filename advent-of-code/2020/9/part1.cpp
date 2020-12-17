#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    int x;
    vector<int> v;
    for (int i=0; i<25; ++i)
        cin >> x, v.push_back(x);
    while (cin >> x) {
        bool f=0;
        for (int i=v.size()-25; i<v.size(); ++i)
            for (int j=i+1; j<v.size(); ++j)
                f|=(x==v[i]+v[j]);
        if (!f) {
            cout << x << '\n';
            break;
        }
        v.push_back(x);
    }
}

