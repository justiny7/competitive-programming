#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using pii=pair<int, int>;
using ordered_set=tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k, a[200001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    ordered_set s;
    for (int i=0; i<k; ++i)
        s.insert({a[i], i});
    for (int i=k; i<=n; ++i) {
        cout << (s.find_by_order((k+1)/2-1))->first << " ";
        if (i==n)
            break;
        s.erase({a[i-k], i-k});
        s.insert({a[i], i});
    }
    cout << '\n';
}
