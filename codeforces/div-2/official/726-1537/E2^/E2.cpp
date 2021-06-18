#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 69;
int n, k, z[N];
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k >> s;

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

    int c = 1;
    for (; c < n; ++c)
        if (c + z[c] >= n || s[c + z[c]] > s[z[c]])
            break;

    for (int i = 0; i < k; ++i)
        cout << s[i % c];
    cout << '\n';
}
