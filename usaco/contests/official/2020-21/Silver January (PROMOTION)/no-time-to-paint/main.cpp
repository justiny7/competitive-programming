#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+5;
int n, q, pref[mxN], suff[mxN], lst[26], psum[26][mxN];
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> s;
    for (int i=0; i<n; ++i) {
        ++psum[(s[i]-'A')][i];
        if (i) {
            for (int j=0; j<26; ++j)
                psum[j][i]+=psum[j][i-1];
        }
    }
    { //calculate pref
        memset(lst, -1, sizeof(lst));
        for (int i=0; i<n; ++i) {
            int c=(s[i]-'A');
            if (~lst[c]) {
                bool f=0;
                for (int j=0; j<c; ++j)
                    f|=bool(psum[j][i]-psum[j][lst[c]]);
                if (f)
                    ++pref[i];
            }
            else
                ++pref[i];
            lst[c]=i;
            if (i)
                pref[i]+=pref[i-1];
        }
    }
    { //calculate suff
        memset(lst, -1, sizeof(lst));
        for (int i=n-1; ~i; --i) {
            int c=(s[i]-'A');
            if (~lst[c]) {
                bool f=0;
                for (int j=0; j<c; ++j)
                    f|=bool(psum[j][lst[c]]-psum[j][i]);
                if (f)
                    ++suff[i];
            }
            else
                ++suff[i];
            lst[c]=i;
            if (i<n-1)
                suff[i]+=suff[i+1];
        }
    }
    while (q--) {
        int l, r, ret=0;
        cin >> l >> r, --l, --r;
        if (l)
            ret+=pref[l-1];
        if (r<n-1)
            ret+=suff[r+1];
        cout << ret << '\n';
    }
}

