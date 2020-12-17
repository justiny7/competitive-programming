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
    int n=v.size(), cur, ans;
    vis.resize(n);
    for (int i=0; i<n; ++i) {
        cur=ans=0;
        fill(vis.begin(), vis.end(), 0);
        bool f=0;
        if (v[i].first=="nop")
            f=1, v[i].first="jmp";
        else if (v[i].first=="jmp")
            f=1, v[i].first="nop";
        while (!vis[cur] && cur<n) {
            vis[cur]=1;
            if (v[cur].first=="acc")
                ans+=v[cur].second;
            else if (v[cur].first=="jmp")
                cur+=v[cur].second-1;
            ++cur;
        }
        if (cur==n)
            break;
        if (f)
            v[i].first=(v[i].first=="jmp"?"nop":"jmp");
    }
    cout << ans << '\n';
}

