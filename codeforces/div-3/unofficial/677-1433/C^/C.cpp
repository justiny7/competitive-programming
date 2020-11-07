#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> s;
        vector<int> v(n);
        for (int &i:v)
            cin >> i, s.insert(i);
        if (s.size()==1) {
            cout << "-1\n";
            continue;
        }
        int targ=*s.rbegin();
        for (int i=0; i<n; ++i)
            if (v[i]==targ && ((i && v[i-1]<v[i]) || (i<n-1 && v[i+1]<v[i]))) {
                cout << i+1 << '\n';
                break;
            }
    }
}

