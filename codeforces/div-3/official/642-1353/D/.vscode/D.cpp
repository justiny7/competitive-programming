#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int asdf = 0; asdf < t; asdf++) {
        int n;
        cin >> n;
        vector<int> ans (n);
        //int indexes[n+1][n+1]; //# of 0s, where they start
        vector<vector<int>> indexes (n+1);
        indexes[n].push_back(0);
        int counter = n, a = 1;
        while (counter > 0) {
            sort(indexes[counter].begin(), indexes[counter].end());
            for (int i = 0; i < indexes[counter].size(); i++) {
                int index = indexes[counter][i] + counter/2;
                if (counter%2 == 0)
                    index--;
                ans[index] = a;
                a++;
                if (counter%2 == 1) {
                    indexes[counter/2].push_back(indexes[counter][i]);
                    indexes[counter/2].push_back(indexes[counter][i] + counter/2+1);
                }
                else {
                    indexes[counter/2-1].push_back(indexes[counter][i]);
                    indexes[counter/2].push_back(indexes[counter][i] + counter/2);
                }
            }
            counter--;
        }

        for (int i = 0; i < n; i++) {
            if (i != 0)
                cout << " ";
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}