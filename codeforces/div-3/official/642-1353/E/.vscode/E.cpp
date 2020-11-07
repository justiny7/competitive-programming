#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int asdf = 0; asdf < t; asdf++) {
        int n, k;
        cin >> n >> k;
        string seq;
        cin >> seq;

        int seqcnt = 0, moves = 0, endzero = n;
        bool counting = false;
        for (int i = n-1; i >= 0; i--) {
            if (seq[i] == '0')
                endzero--;
            else break;
        }
        //cout << "zeroend: " << endzero << endl;

        for (int i = 0; i < endzero; i++) {
            if (seq[i] == '1' && !counting) {
                seqcnt++;
                counting = true;
            }
            else if (counting) {
                seqcnt++;
                if (seq[i] == '0' && seqcnt%k == 1) {
                    moves++;
                }
                else if (seq[i] == '1' && seqcnt%k != 1) {
                    moves++;
                }
            }
        }

        cout << moves << endl;
    }

    return 0;
}
