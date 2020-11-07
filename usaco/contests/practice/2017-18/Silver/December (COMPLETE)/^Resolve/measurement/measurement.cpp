#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, g, ans;
map<int, int, greater<int>> amt, cows;
struct upd {
    int id, day, delta;
    bool operator<(const upd& u) const {
        return day<u.day;
    }
} a[mxN];

int main() {
    ifstream cin("measurement.in");
    ofstream cout("measurement.out");
    cin >> n >> g;
    for (int i=0; i<n; ++i)
        cin >> a[i].day >> a[i].id >> a[i].delta;
    sort(a, a+n);
    amt[g]=1e9;
    for (int i=0; i<n; ++i) {
        upd u=a[i];
        int before=(cows.count(u.id)?cows[u.id]:cows[u.id]=g),
            maxcnt=amt.begin()->second;
        bool wasmax=(before==amt.begin()->first);
        --amt[cows[u.id]];
        if (!amt[cows[u.id]])
            amt.erase(cows[u.id]);
        cows[u.id]+=u.delta;
        ++amt[cows[u.id]];
        bool ismax=(cows[u.id]==amt.begin()->first);
        if (wasmax^ismax)
            ++ans;
        else if (wasmax && ismax && (amt[cows[u.id]]>1 || maxcnt>1))
            ++ans;
    }
    cout << ans << '\n';
}

