#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    int x;
    const int targ=50047984;
    vector<int> v;
    while (cin >> x)
        v.push_back(x);
    int l=0, r=1, cur=v[l]+v[r];
    while (1) {
        if (cur==targ) {
            int mn=INT_MAX, mx=INT_MIN;
            for (int i=l; i<=r; ++i)
                mn=min(mn, v[i]), mx=max(mx, v[i]);
            cout << mn+mx << '\n';
            break;
        }
        if (cur<targ)
            cur+=v[++r];
        else
            cur-=v[l++];
    }
}

