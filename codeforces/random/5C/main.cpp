#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 69;
int n, mx, cnt, dp[N];
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s, n = s.size();

    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '(')
            st.push(i);
        else if (st.size()) {
            int tp = st.top(); st.pop();
            dp[i] = dp[tp - 1] + i - tp + 1;
        }
    }

    mx = *max_element(dp + 1, dp + n + 1);
    for (int i = 1; i <= n; ++i)
        cnt += (dp[i] == mx);

    cout << mx << " " << (mx == 0 ? 1 : cnt) << '\n';
}

