//Yay got it second try
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, ans;
vector<int> st, en;
map<int, int> other, rnk;

int main() {
    ifstream cin("crossings.in");
    ofstream cout("crossings.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        st.pb(a);
        en.pb(b);
        other[a]=b;
    }
    sort(st.begin(), st.end());
    sort(en.begin(), en.end());
    for (int i=0; i<n; ++i)
        rnk[other[st[i]]]=i+1;
    int mx=0;
    for (int i=0; i<n; ++i) {
        if (other[st[i]]==en[i] && mx+1==rnk[en[i]])
            ++ans;
        mx=max(mx, rnk[en[i]]);
    }
    cout << ans << '\n';
}

