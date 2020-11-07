//Yay worked first try
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
int n, a[mxN], ans;

int main() {
    ifstream cin("relay.in");
    ofstream cout("relay.out");
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i) { //Shouldn't have to do this the smart way cuz small bounds
        int cur=i;
        vector<bool> vis(n);
        while (cur && !vis[cur])
            vis[cur]=1, cur=a[cur];
        if (!cur)
            ++ans;
    }
    cout << ans << '\n';
}

