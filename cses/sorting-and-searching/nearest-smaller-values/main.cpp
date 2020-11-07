#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

int n;
stack<pii> st;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << 0;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        while (!st.empty() && a<=st.top().fi)
            st.pop();
        if (i)
            cout << " " << ((st.empty())?0:st.top().se);
        st.push({a, i+1});
    }
    cout << '\n';
}
