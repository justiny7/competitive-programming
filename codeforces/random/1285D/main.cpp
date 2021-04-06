#include <bits/stdc++.h>
using namespace std;

int go(vector<int> &cur, int bit) {
    if (bit < 0)
        return 0;
    if (cur.empty())
        return INT_MAX;
    vector<int> yes, no;
    for (int &i : cur) {
        if (i & (1 << bit))
            yes.push_back(i);
        else
            no.push_back(i);
    }
    int here = (no.size() && yes.size()) ? (1 << bit) : 0;
    return min(go(yes, bit - 1), go(no, bit - 1)) + here;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    cout << go(a, 30) << '\n';
}
