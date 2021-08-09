#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 69;
int n, m, ans[N][N];
array<int, 3> a[N * N], shift, axis;

int get(int pos, int ind) {
    return ((a[ind][axis[pos]] + shift[pos]) % n + n) % n;
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int ind = i * n + j;

            a[ind][0] = i, a[ind][1] = j;
            cin >> a[ind][2], --a[ind][2];
        }
    }

    shift = {0, 0, 0};
    axis = {0, 1, 2};

    while (m--) {
        char c;
        cin >> c;

        switch(c) {
        case 'L':
            --shift[1];
            break;
        case 'R':
            ++shift[1];
            break;
        case 'U':
            --shift[0];
            break;
        case 'D':
            ++shift[0];
            break;
        case 'I':
            swap(shift[1], shift[2]);
            swap(axis[1], axis[2]);
            break;
        case 'C':
            swap(shift[0], shift[2]);
            swap(axis[0], axis[2]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int ind = i * n + j;
            ans[get(0, ind)][get(1, ind)] = get(2, ind);
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << ans[i][j] + 1 << " \n"[j == n - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

