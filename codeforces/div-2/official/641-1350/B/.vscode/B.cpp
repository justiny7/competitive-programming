#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool in[200001];

//From GeeksForGeeks
ll gcd (ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a, b);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int len;
    cin >> len;
    vector<ll> vec;
    for (int i = 0; i < len; i++) {
        ll a;
        cin >> a;
        if (!in[a]) {
            vec.push_back(a);
            in[a] = true;
        }
    }
    len = vec.size();
    ll curLcm, GCD = -1;
    for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) {
            curLcm = (lcm(vec[i], vec[j]));
            if (j == 1)
                GCD = curLcm;
            //cout << "lcm of " << vec[i] << " and " << vec[j] << '\n';
            //cout << "lcm: " << curLcm << '\n';
            if (curLcm % GCD != 0)
                GCD = gcd(GCD, curLcm);
            if (GCD == 1) {
                cout << "1\n";
                return 0;
            }
            //cout << "gcd: " << GCD << '\n';
        }
    }
    if (GCD == -1)
        GCD = vec[0];
    cout << GCD << endl;

    return 0;
}