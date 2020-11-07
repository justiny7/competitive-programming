#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, ans;
pair<int, int> m[200001];

bool smeth(pair<int, int> a, pair<int, int> b) {
    if (a.se!=b.se)
        return a.se<b.se;
    else
        return a.fi<b.fi;
}

int main(void) {
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> m[i].fi >> m[i].se;
    sort(m, m+n, smeth);
    int mint=0;
    for (int i=0; i<n; i++)
        if (m[i].fi>=mint) {
            ans++;
            mint=m[i].se;
        }
    cout << ans << '\n';
}

