//Had to look at solution for hint
#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
#define mp make_pair
using namespace std;
using pii=pair<int, int>;

ifstream fin("piepie.in");
ofstream fout("piepie.out");

const int mxN=2e5+1;
int n, d, a[mxN], b[mxN], cnt[mxN];
multiset<pii> ma, mb;
queue<int> q;

int main() {
    memset(cnt, -1, sizeof(cnt));
    fin >> n >> d;
    for (int i=0; i<n*2; ++i)
        fin >> a[i] >> b[i], a[i]*=-1, b[i]*=-1;
    for (int i=0; i<n; ++i) {
        if (a[i+n])
            mb.insert(mp(a[i+n], i+n));
        else
            q.push(i+n), cnt[i+n]=1;
        if (b[i])
            ma.insert(mp(b[i], i));
        else
            q.push(i), cnt[i]=1;
    }
    while (!q.empty()) {
        int i=q.front(); q.pop();
        if (i<n)
            while (1) {
                auto it=mb.lb(mp(a[i], -1));
                if (it==mb.end() || a[it->se]>a[i]+d)
                    break;
                cnt[it->se]=cnt[i]+1;
                q.push(it->se);
                mb.erase(it);
            }
        else
            while (1) {
                auto it=ma.lb(mp(b[i], -1));
                if (it==ma.end() || b[it->se]>b[i]+d)
                    break;
                cnt[it->se]=cnt[i]+1;
                q.push(it->se);
                ma.erase(it);
            }
    }
    for (int i=0; i<n; ++i)
        fout << cnt[i] << '\n';
}
