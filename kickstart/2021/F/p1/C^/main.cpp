#include <bits/stdc++.h>
using namespace std;

using ld = long double;

const ld PI = acos(-1);

ld sq(int x) {
    return ld(x) * ld(x);
}
ld dist(int x1, int y1, int x2, int y2) {
    return sqrt(sq(x1 - x2) + sq(y1 - y2));
}
ld opp(ld x) {
    x += PI;
    if (x > PI)
        x -= PI * 2;
    return x;
}
bool eq(ld a, ld b) {
    return abs(a - b) < 1e-10;
}

bool ccw(array<int, 2> p, array<int, 2> q, array<int, 2> r) {
    return 1LL * (r[1] - p[1]) * (q[0] - p[0]) > 1LL * (q[1] - p[1]) * (r[0] - p[0]);
}
int isect(array<int, 2> p, array<int, 2> q, array<int, 2> r, array<int, 2> s) {
    return (ccw(p, r, s) ^ ccw(q, r, s)) && (ccw(p, q, r) ^ ccw(p, q, s));
}

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    int sx, sy;
    cin >> sx >> sy;

    int ox = 1000037 + sx, oy = 1000039 + sy;

    map<ld, array<int, 2>> mp;
    vector<ld> angle(n);
    for (int i = 0; i < n; ++i) {
        angle[i] = atan2(y[i] - sy, x[i] - sx);
        if (!mp.count(angle[i]) || dist(mp[angle[i]][0], mp[angle[i]][1], sx, sy) > dist(x[i], y[i], sx, sy))
            mp[angle[i]] = {x[i], y[i]};
    }

    ld ans = 1e18;

    auto check = [&](array<int, 2> p, array<int, 2> q) -> int {
        return isect({sx, sy}, {ox, oy}, p, q);
    };
    auto get = [&](array<int, 2> p, array<int, 2> q) -> ld {
        return dist(p[0], p[1], q[0], q[1]);
    };

    // try triangles
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (eq(angle[i], angle[j]) || eq(angle[i], opp(angle[j])))
                continue;

            for (int k = j + 1; k < n; ++k) {
                if (eq(angle[i], angle[k]) || eq(angle[i], opp(angle[k])) ||
                    eq(angle[j], angle[k]) || eq(angle[j], opp(angle[k])))
                    continue;

                array<int, 2> p1 = {x[i], y[i]}, p2 = {x[j], y[j]}, p3 = {x[k], y[k]};
                if (check(p1, p2) + check(p1, p3) + check(p2, p3) == 1)
                    ans = min(ans, get(p1, p2) + get(p1, p3) + get(p2, p3));
            }
        }
    }

    // try quadrilaterals
    for (auto [a1, p1] : mp) {
        for (auto [a2, p2] : mp) {
            if (eq(a1, a2) || eq(a1, opp(a2)))
                continue;

            auto try_get = [&](ld ang, array<int, 2> &p) -> bool {
                auto it = mp.lower_bound(ang);
                if (it != mp.end() && eq(it->first, ang)) {
                    p = it->second;
                    return 1;
                } else if (it != mp.begin() && eq((--it)->first, ang)) {
                    p = it->second;
                    return 1;
                }
                return 0;
            };

            array<int, 2> p3, p4;
            if (try_get(opp(a1), p3) && try_get(opp(a2), p4))
                ans = min(ans, get(p1, p2) + get(p2, p3) + get(p3, p4) + get(p4, p1));
        }
    }

    if (ans > 1e17)
        cout << "IMPOSSIBLE\n";
    else
        cout << setprecision(10) << fixed << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

