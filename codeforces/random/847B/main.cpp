#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=2e5+1;
int n;
vector<vector<int>> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    set<pii> cur;
    int c=-1;
    for (int i=0; i<n; ++i) {
        int a, cc=-1; cin >> a;
        if (cur.empty() || a<cur.begin()->first)
            ans.pb({a}), cc=++c;
        else {
            auto it=cur.lower_bound(pii(a, INT_MIN));
            if (it==cur.begin())
                ans.pb({a}), cc=++c;
            else {
                --it;
                ans[cc=it->se].pb({a});
                cur.erase(it);
            }
        }
        cur.insert(pii(a, cc));
    }
    for (auto& v:ans)
        for (int i=0; i<v.size(); ++i)
            cout << v[i] << (i<v.size()-1?" ":"\n");
}

