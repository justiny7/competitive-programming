#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    int ans=0, f=0;
    set<string> have;
    while (1) {
        getline(cin, s);
        if (s.empty()) {
            if (f)
                break;
            else {
                if ((have.size()==8) || (have.size()==7 && !have.count("cid")))
                    ++ans;
                f=1;
                have.clear();
            }
            continue;
        }
        f=0;
        stringstream ss(s);
        string s2;
        while (ss >> s2)
            have.insert(s2.substr(0, 3));
    }
    cout << ans << '\n';
}

