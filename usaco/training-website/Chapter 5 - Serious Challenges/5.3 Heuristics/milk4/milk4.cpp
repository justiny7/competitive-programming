/*
ID: justiny7
LANG: C++11
TASK: milk4
*/

//Oops took 7 submissions because of stupid bugs
#include <bits/stdc++.h>
#define pb push_back
#define pob pop_back
using namespace std;

ifstream fin("milk4.in");
ofstream fout("milk4.out");

const int mxN=101, mxQ=2e5+1;
int n, q, a[mxN];
vector<int> cur, ans;

void solve(int mx, int i=0, int left=q) {
    if (cur.size()==mx) {
        if (!left) {
            if (ans.empty())
                ans=cur;
            else {
                for (int i=0; i<ans.size(); ++i)
                    if (cur[i]^ans[i]) {
                        if (ans[i]>cur[i])
                            ans=cur;
                        break;
                    }
            }
        }
        return;
    }
    if (i>=n || left<a[i])
        return;
    cur.pb(a[i]);
    for (int j=1; j<=left/a[i]; ++j)
        solve(mx, i+1, left-j*a[i]);
    cur.pob();
    solve(mx, i+1, left);
}

int main() {
    fin >> q >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i];
    sort(a, a+n);
    for (int i=1; i<=n; ++i) {
        solve(i);
        if (!ans.empty()) {
            fout << ans.size();
            for (int i:ans)
                fout << " " << i;
            break;
        }
    }
    fout << '\n';
}

