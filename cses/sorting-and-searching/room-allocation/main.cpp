#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

int n;
vector<pii> ans;
pair<pii, int> ppl[200001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        ppl[i]={{a, b}, i};
    }
    sort(ppl, ppl+n);
    int cur=1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    for (int i=0; i<n; ++i) {
        pii p=pq.top();
        if (ppl[i].fi.fi>p.fi) {
            ans.push_back({ppl[i].se, p.se});
            pq.pop();
            pq.push({ppl[i].fi.se, p.se});
        }
        else {
            ans.push_back({ppl[i].se, ++cur});
            pq.push({ppl[i].fi.se, cur});
        }
    }
    cout << cur << '\n';
    sort(ans.begin(), ans.end());
    for (int i=0; i<n; ++i) {
        if (i)
            cout << " ";
        cout << ans[i].se;
    }
    cout << '\n';
}

