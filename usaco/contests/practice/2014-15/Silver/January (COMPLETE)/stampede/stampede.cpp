#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

//I need to practice more sweepline
ifstream fin("stampede.in");
ofstream fout("stampede.out");

int n;
vector<pii> vec;

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        int x, y, r;
        fin >> x >> y >> r;
        vec.push_back({-1*(x+1)*r, y});
        vec.push_back({-1*x*r, -y});
    }
    sort(vec.begin(), vec.end());
    set<int> cur, vis;
    for (int i=0; i<vec.size();) {
        int next=i;
        for (; next<vec.size() && vec[i].fi==vec[next].fi; ++next) {
            if (vec[next].se<0)
                cur.erase(vec[next].se*-1);
            else
                cur.insert(vec[next].se);
        }
        if (!cur.empty())
            vis.insert(*cur.begin());
        i=next;
    }
    fout << vis.size() << '\n';
}

