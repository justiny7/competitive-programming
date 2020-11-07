//Yay worked first try!
//Binary search on first stack to put a plate on
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pis=pair<int, stack<int>>;

int n, tos;
vector<pis> v;

int main() {
    ifstream cin("dishes.in");
    ofstream cout("dishes.out");
    cin >> n;
    for (int t=0; t<n; ++t) {
        int a, lo=0, hi=v.size()-1, best=-1;
        cin >> a;
        if (a<tos)
            return cout << t << '\n', 0;
        while (lo<=hi) {
            int m=lo+hi>>1;
            if (v[m].fi>a)
                best=m, hi=m-1;
            else
                lo=m+1;
        }
        if (~best) {
            while (v[best].se.size() && v[best].se.top()<a) {
                tos=v[best].se.top();
                v[best].se.pop();
            }
            v[best].se.push(a);
        }
        else
            v.push_back(pis(a, stack<int>({a})));
    }
    cout << n << '\n';
}

