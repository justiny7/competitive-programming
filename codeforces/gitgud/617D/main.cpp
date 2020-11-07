#include <bits/stdc++.h>
#define x first
#define y second
#define finish(x) return cout << x << '\n', 0
using namespace std;
using pii=pair<int, int>;

pii a, b, c;
bool fx1, fx2, fx3, fy1, fy2, fy3;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if (a.x==b.x)
        fx1=1;
    if (b.x==c.x)
        fx2=1;
    if (a.x==c.x)
        fx3=1;
    if (a.y==b.y)
        fy1=1;
    if (b.y==c.y)
        fy2=1;
    if (a.y==c.y)
        fy3=1;
    if ((fx1 && fx2) || (fy1 && fy2))
        finish(1);
    if ((fx1 || fx2 || fx3) && (fy1 || fy2 || fy3))
        finish(2);
    if (fx1) {
        if (c.y>max(a.y, b.y) || c.y<min(a.y, b.y))
            finish(2);
        finish(3);
    }
    if (fx2) {
        if (a.y>max(c.y, b.y) || a.y<min(c.y, b.y))
            finish(2);
        finish(3);
    }
    if (fx3) {
        if (b.y>max(a.y, c.y) || b.y<min(a.y, c.y))
            finish(2);
        finish(3);
    }
    if (fy1) {
        if (c.x>max(a.x, b.x) || c.x<min(a.x, b.x))
            finish(2);
        finish(3);
    }
    if (fy2) {
        if (a.x>max(c.x, b.x) || a.x<min(c.x, b.x))
            finish(2);
        finish(3);
    }
    if (fy3) {
        if (b.x>max(a.x, c.x) || b.x<min(a.x, c.x))
            finish(2);
        finish(3);
    }
    finish(3);
}

