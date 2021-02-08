#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, a[mxN];
vector<int> a0, a1;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<n; ++i) {
        if ((a0.empty() || a0.back()^a[i]) || (a1.empty() || a1.back()^a[i])) {
            if (a1.size() && a[i]==a1.back())
                a0.push_back(a[i]);
            else if (a0.size() && a[i]==a0.back())
                a1.push_back(a[i]);
            else if (a1.empty() || (i<n-1 && a[i+1]==a1.back()))
                a1.push_back(a[i]);
            else
                a0.push_back(a[i]);
        }
    }
    cout << (a0.size()+a1.size()) << '\n';
}

