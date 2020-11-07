#include <bits/stdc++.h>
using namespace std;

const int mxN=1e6+1;
int n, m, z[mxN], ans;
string s, t;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t;
    n=s.size(), m=t.size();
    for (int i=0, l=0, r=0; i<n; ++i) {
        z[i]=max(0, min(r-i+1, z[i-l]));
        while (z[i]<m && i+z[i]<n && t[z[i]]==s[i+z[i]])
            ++z[i], l=i, r=i+z[i]-1;
        if (z[i]==m)
            ++ans;
    }
    cout << ans << '\n';
}
