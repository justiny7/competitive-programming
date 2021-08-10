#include <bits/stdc++.h>
using namespace std;

void move(int r, int c) {
    cout << r << " " << c << endl;
}
int read() {
    string s;
    cin >> s;

    if (s == "Done")
        return 2;

    if (s == "Down" || s == "Down-Right" || s == "Down-Left")
        return -1;
    if (s == "Up" || s == "Up-Right" || s == "Up-Left")
        return 1;
    return 0;
}

void solve() {
    int pos = 1;
    for (int i = 1; i <= 8; ++i) {
        if (pos == 9)
            --pos;
        if (pos == 0)
            ++pos;

        move(i, pos);
        if (read() == 2)
            return;

        if (pos < 8) {
            for (pos = (pos > 1) ? 1 : 2; pos <= 8; ++pos) {
                move(i, pos);

                int dir = read();
                if (dir == 2)
                    return;

                if (dir < 0)
                    break;
                else if (dir > 0)
                    pos = (pos == 1 ? 1 : 0);
            }
        } else {
            for (pos = 7; pos; --pos) {
                move(i, pos);

                int dir = read();
                if (dir == 2)
                    return;

                if (dir < 0)
                    break;
                else if (dir > 0)
                    pos = (pos == 8 ? 8 : 9);
            }
        }
    }

    assert(false);
}

int main() {
    int t;
    cin >> t;

    while (t--)
        solve();
}

