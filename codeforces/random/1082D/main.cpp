#include <bits/stdc++.h>
using namespace std;

const int mxN=501;
int n, d, a[mxN];
vector<int> links, singles;
vector<pair<int, int>> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        if (a[i]==1)
            singles.push_back(i);
        else
            links.push_back(i);
    }
    if (links.empty())
        return cout << "NO\n", 0;
    d=links.size()-1;
    for (int i=1; i<links.size(); ++i) {
        ans.emplace_back(links[i], links[i-1]);
        --a[links[i]], --a[links[i-1]];
    }
    if (singles.size()==1) {
        ans.emplace_back(singles[0], links[0]);
        --a[links[0]];
        ++d;
    }
    else if (singles.size()) {
        ans.emplace_back(singles[0], links[0]);
        --a[links[0]];
        if (!a[links.back()])
            return cout << "NO\n", 0;
        ans.emplace_back(singles[1], links.back());
        --a[links.back()];
        d+=2;
        for (int i=2, j=0; i<singles.size(); ++i) {
            while (j<links.size() && !a[links[j]])
                ++j;
            if (j==links.size())
                return cout << "NO\n", 0;
            ans.emplace_back(singles[i], links[j]);
            --a[links[j]];
        }
    }
    cout << "YES " << d << '\n';
    cout << ans.size() << '\n';
    for (auto p:ans)
        cout << p.first << " " << p.second << '\n';
}

