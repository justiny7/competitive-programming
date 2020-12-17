#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> v;
    {
        int x;
        while (cin >> x)
            v.push_back(x);
    }
    int n=v.size();
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            for (int k=j+1; k<n; ++k)
                if (v[i]+v[j]+v[k]==2020) {
                    cout << (long long)v[i]*v[j]*v[k] << '\n';
                    return 0;
                }
}

