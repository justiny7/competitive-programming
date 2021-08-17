#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, a[N], smol[2][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int t = 0; t < 2; ++t) {
        for (int c = 0; c < 2; ++c) {
            stack<array<int, 2>> st;
            for (int i = 0; i < n; ++i) {
                while (st.size() && a[i] <= st.top()[0])
                    st.pop();

                smol[c][i] = (st.size() ? st.top()[1] : -1);
                st.push({a[i], i});
            }

            reverse(a, a + n);
        }

        for (int i = 1; i < n - 1; ++i) {
            if (~smol[0][i] && ~smol[1][n - i - 1]) {
                cout << "3\n" << smol[0][i] + 1 << " " << i + 1 << " " << n - smol[1][n - i - 1] << '\n';
                return 0;
            }
        }

        for (int i = 0; i < n; ++i)
            a[i] *= -1;
    }

    cout << "0\n";
}

