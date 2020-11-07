#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=16;
int n, cur, ans;
long long b;
vector<int> v;
set<int> seen;

int main() {
    ifstream cin("blink.in");
    ofstream cout("blink.out");
    cin >> n >> b;
    for (int i=1; i<=n; ++i) {
        bool a; cin >> a;
        if (a)
            cur|=(1<<i);
    }
    do {
        v.pb(cur);
        seen.insert(cur);
        int nxt=cur;
        for (int i=1; i<=n; ++i)
            if (cur&(1<<i))
                nxt^=(1<<(i%n+1));
        cur=nxt;
        if (!__builtin_popcount(nxt)) {
            for (int i=0; i<n; ++i)
                cout << "0\n";
            return 0;
        }
    } while (!seen.count(cur) && v.size()<b);
    if (v.size()<b) {
        vector<int> cycle;
        for (int i=0, f=0; i<v.size(); ++i)
            if (f || v[i]==cur) {
                if (!f)
                    b-=i;
                f=1, cycle.pb(v[i]);
            }
        ans=cycle[b%cycle.size()];
    }
    else
        ans=cur;
    for (int i=1; i<=n; ++i)
        cout << ((ans&(1<<i))?1:0) << '\n';
}

