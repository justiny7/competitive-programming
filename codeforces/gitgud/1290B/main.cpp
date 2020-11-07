#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
string s;
int q, occ[mxN][26];

bool check(int l, int r) {
    int c=0;
    for (int i=0; i<26; ++i)
        if (occ[r][i]-occ[l][i])
            ++c;
    return c>2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> q;
    for (int i=0; i<s.size(); ++i) {
        ++occ[i][s[i]-'a'];
        if (!i)
            continue;
        for (int j=0; j<26; ++j)
            occ[i][j]+=occ[i-1][j];
    }
    while (q--) {
        int l, r;
        cin >> l >> r, --l, --r;
        if (r==l || s[r]^s[l] || check(l, r))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

