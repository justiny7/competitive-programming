#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ub upper_bound
using namespace std;
using pii=pair<int, int>;
//Sweepline - got it on 3rd try because I accidentally added enclosed enclosures to active set as well
ifstream fin("painting.in");
ofstream fout("painting.out");

const int mxN=5e4+1;
int n, ans;
set<pii> x, cur;
map<pii, pii> other;

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        other[mp(b, a)]=mp(d, c);
        other[mp(d, c)]=mp(b, a);
        x.insert(mp(a, b)); x.insert(mp(c, d));
    }
    for (auto it=x.begin(); it!=x.end(); ++it) {
        if (cur.count(other[mp(it->se, it->fi)])) {
            cur.erase(mp(it->se, it->fi));
            cur.erase(other[mp(it->se, it->fi)]);
        }
        else {
            auto itr=cur.ub(mp(it->se, it->fi));
            if (itr==cur.begin()) {
                ++ans;
                cur.insert(mp(it->se, it->fi));
            }
            else {
                --itr;
                if (other[*itr].fi<it->se) {
                    ++ans;
                    cur.insert(mp(it->se, it->fi));
                }
            }
        }
    }
    fout << ans << '\n';
}
