#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, m, ans = 1, val[N], pos[N];

void op(int x, int c, int r = -1) {
    if (x > 1 && x - 1 != r)
        ans += c * (pos[x - 1] > pos[x]);
    if (x < n && x + 1 != r)
        ans += c * (pos[x] > pos[x + 1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> val[i], pos[val[i]] = i;

    for (int i = 1; i < n; ++i)
        ans += pos[i] > pos[i + 1];

    while (m--) {
        int a, b;
        cin >> a >> b;

        op(val[a], -1), op(val[b], -1, val[a]);
        swap(pos[val[a]], pos[val[b]]);
        swap(val[a], val[b]);
        op(val[a], 1), op(val[b], 1, val[a]);

        cout << ans << '\n';
    }
}

