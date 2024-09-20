#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    auto query = [&](string s) {
        cout << "? " << s << endl;
        int res;
        cin >> res;
        return res;
    };

    string s = "";
    while (s.size() < n) {
        int q = query(s + "1");

        if (s == "" && q == 0) {
            cout << "! " << string(n, '0') << endl;
            return;
        }

        if (q == 1) {
            s += '1';
            continue;
        }

        q = query(s + "0");
        if (q == 1) {
            s += '0';
        } else {
            break;
        }
    }

    while (s.size() < n) {
        int q = query("1" + s);
        if (q == 1) {
            s = "1" + s;
        } else {
            s = "0" + s;
        }
    }

    cout << "! " << s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
