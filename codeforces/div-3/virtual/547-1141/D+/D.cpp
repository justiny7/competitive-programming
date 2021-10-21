#include <bits/stdc++.h>
using namespace std;

const char q = '?';

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    string s, t;
    cin >> n >> s >> t;

    map<char, vector<int>> ms, mt;
    for (int i = 0; i < n; ++i) {
        ms[s[i]].push_back(i + 1);
        mt[t[i]].push_back(i + 1);
    }

    vector<array<int, 2>> ans;
    for (char c = 'a'; c <= 'z'; ++c) {
        while (ms[c].size() && mt[c].size()) {
            ans.push_back({ms[c].back(), mt[c].back()});
            ms[c].pop_back();
            mt[c].pop_back();
        }

        if (ms[c].empty())
            ms.erase(c);
        if (mt[c].empty())
            mt.erase(c);
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        while (ms[c].size() && mt[q].size()) {
            ans.push_back({ms[c].back(), mt[q].back()});
            ms[c].pop_back();
            mt[q].pop_back();
        }

        if (ms[c].empty())
            ms.erase(c);
        if (mt[q].empty())
            mt.erase(q);
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        while (ms[q].size() && mt[c].size()) {
            ans.push_back({ms[q].back(), mt[c].back()});
            ms[q].pop_back();
            mt[c].pop_back();
        }

        if (ms[q].empty())
            ms.erase(q);
        if (mt[c].empty())
            mt.erase(c);
    }
    while (ms[q].size() && mt[q].size()) {
        ans.push_back({ms[q].back(), mt[q].back()});
        ms[q].pop_back();
        mt[q].pop_back();
    }

    if (ms[q].empty())
        ms.erase(q);
    if (mt[q].empty())
        mt.erase(q);

    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
        cout << u << " " << v << '\n';
}

