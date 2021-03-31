#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, q, bit[mxN], a[mxN], ans[mxN];
array<int, 3> q_a[mxN];
map<int, int> last_occ;

void upd(int i, int x) {
    for (++i; i<=n; i+=i&(-i))
        bit[i]+=x;
}

int query(int i) {
    int sum=0;
    for (; i>0; i-=i&(-i))
        sum+=bit[i];
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<q; ++i)
        cin >> q_a[i][1] >> q_a[i][0], q_a[i][2]=i;
    sort(q_a, q_a+q); //sort queries by increasing right index
    for (int i=0, j=0; i<n || j<q; ++j) {
        while (i<n && i<=q_a[j][0]-1) { //keep track of rightmost appearance of each a[i] before ending of next query
            if (last_occ.count(a[i]))
                upd(last_occ[a[i]], -1);
            upd(i, 1);
            last_occ[a[i]]=i;
            ++i;
        }
        ans[q_a[j][2]]=query(q_a[j][0])-query(q_a[j][1]-1); //ans to query is sum of distinct a[i]'s inside query range
    }
    for (int i=0; i<q; ++i)
        cout << ans[i] << '\n';
}
