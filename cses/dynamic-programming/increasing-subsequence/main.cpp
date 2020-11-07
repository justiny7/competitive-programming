#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        auto it=lower_bound(dp.begin(), dp.end(), a);
        if (it==dp.end())
            dp.push_back(a);
        else
            *it=a;
    }
    cout << dp.size() << '\n';
}
