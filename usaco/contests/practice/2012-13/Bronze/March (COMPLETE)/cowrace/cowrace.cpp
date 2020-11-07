//Yay worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
#define ub upper_bound
#define mp make_pair
using namespace std;
using pii=pair<int, int>;

const int mxN=1e4+1;
int n, m, ans;
pair<int, pii> b[mxN], e[mxN];
set<int> times;

int main() {
    ifstream cin("cowrace.in");
    ofstream cout("cowrace.out");
    cin >> n >> m;
    int time=0;
    for (int i=0, pos=0; i<n; ++i) {
        int s, t;
        cin >> s >> t;
        b[i]=mp(time, pii(pos, s));
        times.insert(time);
        pos+=t*s;
        time+=t;
    }
    times.insert(time);
    time=0;
    for (int i=0, pos=0; i<m; ++i) {
        int s, t;
        cin >> s >> t;
        e[i]=mp(time, pii(pos, s));
        times.insert(time);
        pos+=t*s;
        time+=t;
    }
    times.insert(time);
    times.erase(0);
    int front=0;
    for (int t:times) {
        int bi=ub(b, b+n, mp(t, mp(-1, -1)))-b-1,
            ei=ub(e, e+m, mp(t, mp(-1, -1)))-e-1;
        int bpos=b[bi].se.fi+b[bi].se.se*(t-b[bi].fi),
            epos=e[ei].se.fi+e[ei].se.se*(t-e[ei].fi);
        int cur=(bpos==epos?0:(bpos>epos?1:2));
        if (front && cur && front^cur)
            ++ans;
        if (cur)
            front=cur;
    }
    cout << ans << '\n';
}

