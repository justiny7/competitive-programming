//USACO US Open 2019 Problem 1

/* Big casework problem
 * Solve for some square (flip all cols for each L in the row of that square, and flip all rows for each L in the square's col)
 * If the entire grid is solved, then there are no special cows
 * If the rest grid is solved (not counting the square's rol and col), then that square must be the leftout cow
 * If we have an entire row/col filled with R's, then the left out cow of that row/col is the leftout cow
 * Otherwise, it's either that the unsolved cow is the only unsolved cow in the grid, or there are multiple unsolved cows
 * We'll check (0, 0) for convenience.
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("leftout.in");
ofstream fout("leftout.out");

int n;
bool cows[1001][1001];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << cows[i][j];
        cout << '\n';
    }
}

int howmany(int x1, int y1, int x2, int y2, bool x) { //return how many of x there is in given ranges
    int c = 0;
    for (int i = y1; i <= y2; i++)
        for (int j = x1; j <= x2; j++)
            if (cows[i][j] == x)
                c++;
    return c;
}

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j =0 ; j < n; j++) {
            char c;
            fin >> c;
            cows[i][j] = (c == 'R');
        }
    //print();
    //cout << '\n';
    for (int i = 0; i < n; i++) { //solving (0, 0)
        if (!cows[i][0])
            continue;
        else
            for (int j = 0; j < n; j++)
                cows[i][j] = !cows[i][j];
    }
    for (int i = 0; i < n; i++) {
        if (!cows[0][i])
            continue;
        else
            for (int j = 0; j < n; j++)
                cows[j][i] = !cows[j][i];
    }
    //print();
    if (howmany(0, 0, n-1, n-1, true) == 0) { //Entire grid is 0?
        fout << "-1\n";
        return 0;
    }
    if (howmany(1, 1, n-1, n-1, false) == 0) { //Entire grid except first col and row is 1?
        fout << "1 1\n";
        return 0;
    }
    if (howmany(1, 1, n-1, n-1, true) == n-1) {
        for (int i = 0; i < n; i++) {
            if (howmany(0, i, n-1, i, true) == n-1) { //Entire row is 1 except start?
                fout << i+1 << " 1\n";
                return 0;
            }
            if (howmany(i, 0, i, n-1, true) == n-1) { //Entire col is 1 except start?
                fout << 1 << " " << i+1 << '\n';
                return 0;
            }
        }
        fout << "-1\n";
        return 0;
    }
    if (howmany(1, 1, n-1, n-1, true) > 1) { //More than 1 unsolved cow?
        fout << "-1\n";
        return 0;
    }
    for (int i = 1; i < n; i++) //Find unsolved cow
        for (int j =1; j < n; j++)
            if (cows[i][j])
                fout << i+1 << " " << j+1 << '\n';
    return 0;
}
