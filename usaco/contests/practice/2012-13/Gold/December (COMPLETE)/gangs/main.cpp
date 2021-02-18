#include <bits/stdc++.h>
using namespace std;
using pi=pair<int, int>;

int n, m, cows, gang;
vector<int> cnt;

void add(int &g, int &c, int x) {
    if (!c)
        g=x;
    (g==x)?++c:--c;
}
pi sim(int g, int c, vector<int> ct) {
    priority_queue<pi> pq;
    for (int i=2; i<=m; ++i)
        if (ct[i])
            pq.emplace(ct[i], i);
    while (pq.size()) { //add cows from largest gang
        pi p=pq.top(); pq.pop();
        add(g, c, p.second);
        if (--p.first)
            pq.push(p);
    }
    while (ct[1]--)
        add(g, c, 1);
    return pi(g, c);
}

int main() {
    ifstream cin("gangs.in");
    ofstream cout("gangs.out");
    cin >> n >> m;
    cnt.resize(m+1);
    for (int i=1; i<=m; ++i)
        cin >> cnt[i];
    pi ret=sim(0, 0, cnt);
    if (ret.first==1) {
        cout << "YES\n" << ret.second << '\n';
        cows=gang=0;
        for (int t=0; t<n; ++t) {
            int o_gang=gang, o_cows=cows;
            for (int i=1; i<=m; ++i) { //try finding the next lexicographically smallest gang to place
                if (!cnt[i])
                    continue;
                add(gang, cows, i);
                --cnt[i];
                pi cur=sim(gang, cows, cnt);
                if (cur.first==1 && cur.second==ret.second) {
                    cout << i << '\n';
                    break;
                }
                ++cnt[i];
                gang=o_gang, cows=o_cows;
            }
        }
    }
    else
        cout << "NO\n";
}

