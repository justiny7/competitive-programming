/*
ID: justiny7
LANG: C++
TASK: range
*/

/*
    Relatively easy problem - worked on my first try!
    Idea - if you can make a 2x2 of 1s with the top-left corner as the current index in lastmap, store 1 in curmap at the current index
    Then, just set lastmap = curmap, reset curmap, decrease mapsize, and cycle through until the map is all 0s or until mapsize = 2
    (mapsize starts at n)

    If n=250 and it's all 1s, worst-case scenario is 1^2 + 2^2 + 3^2 + ... + 249^2 + 250^2, which is only about 5 million cases, so it'll
    run well in time
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("range.in");
ofstream fout("range.out");

string curmap[251], lastmap[251];
int n, ans[255];

void copymap(int len) {
    for (int i = 0; i < len; i++) {
        lastmap[i] = curmap[i];
        curmap[i] = "";
    }
}

void print(int len) {
    for (int i = 0; i < len; i++)
        cout << curmap[i] << '\n';
    cout << '\n';
}

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> lastmap[i];

    for (int curlen = n; curlen >= 2; curlen--) {
        int zerocount = 0;
        for (int i = 0; i < curlen-1; i++) {
            for (int j = 0; j < curlen-1; j++) {
                if (lastmap[i][j] == '1' && lastmap[i][j+1] == '1' && lastmap[i+1][j] == '1' && lastmap[i+1][j+1] == '1') {
                    curmap[i].append("1");
                    ans[n-curlen+2]++;
                }
                else {
                    curmap[i].append("0");
                    zerocount++;
                }
            }
        }
        if (zerocount == (curlen-1)*(curlen-1))
            break;
        //print(curlen-1);
        copymap(curlen-1);
    }

    for (int i = 2; i <= n; i++)
        if (ans[i] > 0)
            fout << i << " " << ans[i] << endl;

    return 0;
}