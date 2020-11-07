#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    if (x==2 || x==5 || x==7)
        return 1;
    if (x%2==0)
        return 0;
    for (int i=3; i*i<=x; i+=2)
        if (x%i==0)
            return 0;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> ans;
    for (int i=2; i<=n; ++i)
        if (is_prime(i)) {
            int a=i;
            while (a<=n)
                ans.push_back(a), a*=i;
        }
    cout << ans.size() << '\n';
    for (int i:ans)
        cout << i << " ";
    cout << '\n';
}

