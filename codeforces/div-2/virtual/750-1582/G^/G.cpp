#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 69;
int n, a[N];
ll res;
vector<int> d[N], p[N], st;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (ll i = 2; i < N; ++i) {
        if (d[i].size())
            continue;

        for (ll j = i; j < N; j *= i)
            for (ll k = j; k < N; k += j)
                d[k].push_back(i);
    }

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;

        st.push_back(i);
        for (int x : d[a[i]]) {
            if (c == '*')
                p[x].push_back(i);
            else {
                while (st.size() && (p[x].empty() || p[x].back() < st.back()))
                    st.pop_back();
                if (p[x].size())
                    p[x].pop_back();
            }
        }

        res += st.size();
    }

    cout << res << '\n';
}

