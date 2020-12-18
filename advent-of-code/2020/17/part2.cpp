//Lol this took so long to run but idrc
#include <bits/stdc++.h>
using namespace std;

const int n=8, D=20;
map<array<int, 4>, bool> mp;

int main() {
    freopen("test.txt", "r", stdin);
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (int j=0; j<n; ++j)
            if (s[j]=='#')
                mp[{i, j, 0, 0}]=1;
    }
    for (int t=0; t<6; ++t) {
        vector<array<int, 4>> rem, add;
        for (int i=-D; i<=D; ++i)
            for (int j=-D; j<=D; ++j)
                for (int k=-D; k<=D; ++k)
                    for (int l=-D; l<=D; ++l) {
                        int c=0;
                        for (int dx=-1; dx<=1; ++dx)
                            for (int dy=-1; dy<=1; ++dy)
                                    for (int dz=-1; dz<=1; ++dz)
                                        for (int dl=-1; dl<=1; ++dl) {
                                        if (!dx && !dy && !dz && !dl)
                                            continue;
                                        int nx=i+dx, ny=j+dy, nz=k+dz, nl=l+dl;
                                        c+=mp[{nx, ny, nz, nl}];
                                    }
                        if (mp[{i, j, k, l}] && c^2 && c^3)
                            rem.push_back({i, j, k, l});
                        else if (!mp[{i, j, k, l}] && c==3)
                            add.push_back({i, j, k, l});
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

