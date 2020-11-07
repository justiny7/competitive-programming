//Yay worked first try (pbds op xd)
//Idea - everything has to be strictly decreasing from the end
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using pii=pair<int, int>;

ifstream fin("sleepy.in");
ofstream fout("sleepy.out");

const int mxN=1e5+1;
int n, a[mxN];
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
vector<int> ans;

int main() {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i];
    int j=n-2;
    s.insert(a[n-1]);
    for (; j>=0; --j) {
        if (a[j]>a[j+1])
            break;
        s.insert(a[j]);
    }
    for (int i=0; s.size()<n; ++i) {
        int nxt=s.order_of_key(a[i]);
        ans.push_back(nxt+n-s.size()-1);
        s.insert(a[i]);
    }
    fout << ans.size() << '\n';
    for (int i=0; i<ans.size(); ++i) {
        if (i)
            fout << " ";
        fout << ans[i];
    }
    fout << '\n';
}

