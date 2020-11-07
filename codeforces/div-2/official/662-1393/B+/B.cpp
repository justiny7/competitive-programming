#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, q, cnt[mxN];
multiset<int, greater<int>> freq;
set<int> cur;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        ++cnt[a];
    }
    for (int i=1; i<mxN; ++i)
        if (cnt[i])
            freq.insert(cnt[i]), cur.insert(i);
    cin >> q;
    while (q--) {
        char c; int a;
        cin >> c >> a;
        if (cur.count(a))
            freq.erase(freq.find(cnt[a]));
        else
            cur.insert(a);
        if (c=='+')
            ++cnt[a];
        else
            --cnt[a];
        if (cnt[a])
            freq.insert(cnt[a]);
        else
            cur.erase(a);
        bool f=0;
        auto it=freq.begin();
        auto it1=it, it2=it;
        if (freq.size()>1)
            ++it1, it2=it1;
        if (freq.size()>2)
            ++it2;
        if (*it>=4) {
            if (*it>=8 || (freq.size()>1 && ((*it>=6 && *it1>=2) || (*it1>=4)))
                || (freq.size()>2 && *it1>=2 && *it2>=2))
                f=1;
        }
        cout << (f?"YES\n":"NO\n");
        assert(freq.size()==cur.size());
    }
}

