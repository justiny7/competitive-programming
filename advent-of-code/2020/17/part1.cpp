#include <bits/stdc++.h>
using namespace std;

const int n=8, D=20;
map<array<int, 3>, bool> mp;

int main() {
    freopen("test.txt", "r", stdin);
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (int j=0; j<n; ++j)
            if (s[j]=='#')
                mp[{i, j, 0}]=1;
    }
    for (int t=0; t<6; ++t) {
        vector<array<int, 3>> rem, add;
        for (int i=-D; i<=D; ++i)
            for (int j=-D; j<=D; ++j)
                for (int k=-D; k<=D; ++k) {
                    int c=0;
                    for (int dx=-1; dx<=1; ++dx)
                        for (int dy=-1; dy<=1; ++dy)
                            for (int dz=-1; dz<=1; ++dz) {
                                if (!dx && !dy && !dz)
                                    continue;
                                int nx=i+dx, ny=j+dy, nz=k+dz;
                                c+=mp[{nx, ny, nz}];
                            }
                    if (mp[{i, j, k}] && c^2 && c^3)
                        rem.push_back({i, j, k});
                    else if (!mp[{i, j, k}] && c==3)
                        add.push_back({i, j, k});
                }
        for (auto v:add)
            mp[v]=1;
        for (auto v:rem)
            mp[v]=0;
    }
    int ans=0;
    for (auto p:mp)
        ans+=p.second;
    cout << ans << '\n';
}

