#include <bits/stdc++.h>
using namespace std;

string s;
set<string> ss={"great", "don't think so", "not bad", "cool", "don't touch me"};

int main() {
    for (int i=0; i<10; ++i) {
        cout << i << endl;
        getline(cin, s);
        if (s=="no")
            continue;
        if (ss.count(s))
            cout << "normal" << endl;
        else
            cout << "grumpy" << endl;
        break;
    }
}

