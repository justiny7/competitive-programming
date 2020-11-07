#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

ifstream fin("msched.in");
ofstream fout("msched.out");

const int mxN=1e4+1;
int n, ans;
pii cows[mxN];
priority_queue<int> pq;

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> cows[i].se >> cows[i].fi;
    sort(cows, cows+n, greater<pii>());
    int cur=0;
    for (int i=mxN-1; i>0; --i) {
        while (cur<n && cows[cur].fi>=i)
            pq.push(cows[cur].se), ++cur;
        if (!pq.empty())
            ans+=pq.top(), pq.pop();
    }
    fout << ans << '\n';
}
