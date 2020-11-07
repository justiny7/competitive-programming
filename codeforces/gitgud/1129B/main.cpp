#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int k, cur=-1;
vector<int> ans={-1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> k;
    while (cur-ans.size()^k-1) {
        int a=min((int)1e6, k+(int)ans.size()-cur);
        cur+=a, ans.pb(a);
    }
    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); ++i)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

