#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> v;
vector<bool> vis;

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    while (1) {
        getline(cin, s);
        if (s.empty())
            break;
        stringstream ss(s);
        string a; int b;
        ss >> a >> b;
        v.emplace_back(a, b);
    }
    vis.resize(v.size());
    int cur=0, ans=0;
    while (!vis[cur]) {
        vis[cur]=1;
        if (v[cur].first=="acc")
            ans+=v[cur].second;
        else if (v[cur].first=="jmp")
            cur+=v[cur].second-1;
        ++cur;
    }
    cout << ans << '\n';
}

