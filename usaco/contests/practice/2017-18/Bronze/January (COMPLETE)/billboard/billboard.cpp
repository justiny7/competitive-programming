//USACO Bronze January 2018 Problem 1

#include <bits/stdc++.h>
using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

int bx1, bx2, by1, by2, fx1, fx2, fy1, fy2;

int main(void) {
    fin >> bx1 >> by1 >> bx2 >> by2 >> fx1 >> fy1 >> fx2 >> fy2;
    int w = bx2-bx1, h = by2-by1;
    if (fx1 <= bx1 && fx2 >= bx2) {
        if (fy2 <= by2 && fy1 <= by1)
            h -= fy2-by1;
        else if (fy2 >= by2 && fy1 >= by1)
            h -= by2-fy1;
        else if (fy2 >= by2 && fy1 <= by1) {
            fout << "0\n";
            return 0;
        }
    }
    if (fy1 <= by1 && fy2 >= by2) {
        if (fx2 <= bx2 && fx1 <= bx1)
            w -= fx2-bx1;
        else if (fx2 >= bx2 && fx1 >= bx1)
            w -= bx2-fx1;
    }
    //cout << w << " " << h << '\n';
    w = max(0, w);
    h = max(0, h);
    fout << w*h << '\n';
}
