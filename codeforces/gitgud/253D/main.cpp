#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=401;
int n, m, k, pref[mxN][mxN];
ll ans;
string s[mxN];

int query(int lx, int ly, int rx, int ry) {
    int ret=pref[rx][ry];
    if (lx && ly)
        ret+=pref[lx-1][ly-1];
    if (lx)
        ret-=pref[lx-1][ry];
    if (ly)
        ret-=pref[rx][ly-1];
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i=0; i<n; ++i) {
        cin >> s[i];
        for (int j=0; j<m; ++j) {
            pref[i][j]=(s[i][j]=='a');
            if (j)
                pref[i][j]+=pref[i][j-1];
            if (i)
                pref[i][j]+=pref[i-1][j];
            if (i && j)
                pref[i][j]-=pref[i-1][j-1];
        }
    }
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j) {
            vector<int> col[26];
            for (int k=0; k<m; ++k)
                if (s[i][k]==s[j][k])
                    col[s[i][k]-'a'].push_back(k);
            for (int c=0; c<26; ++c) {
                vector<int> v=col[c];
                int l=0, r=0, sz=v.size();
                for (; l<sz; ++l) {
                    if (r<=l)
                        r=l+1;
                    while (r<sz && query(i, v[l], j, v[r])<=k)
                        ++r;
                    --r;
                    ans+=(ll)(r-l);
                }
            }
        }
    cout << ans << '\n';
}

