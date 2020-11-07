//USACO Silver US Open 2018 Problem 3
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("family.in");
ofstream fout("family.out");

int n, ncnt=1, bessie=1, elsie=2, mom[101];
vector<int> bmom, emom;
map<string, int> names;
map<int, string> names2;

int main(void) {
    fin >> n;
    string a, b;
    for (int i=0; fin >> a >> b; ++i) {
        if (names.find(a)==names.end()) {
            names[a]=ncnt++;
            names2[ncnt-1]=a;
        }
        if (names.find(b)==names.end()) {
            names[b]=ncnt++;
            names2[ncnt-1]=b;
        }
        if (i==0)
            continue;
        mom[names[b]]=names[a];
    }
    for (int i=bessie;; i=mom[i]) {
        //cout << names2[i] << " ";
        bmom.pb(i);
        if (mom[i]==0)
            break;
    }
    //cout << '\n';
    for (int i=elsie;; i=mom[i]) {
        //cout << names2[i] << " ";
        emom.pb(i);
        if (mom[i]==0)
            break;
    }
    //cout << '\n';
    for (int i=0; i<bmom.size(); ++i)
        for (int j=0; j<emom.size(); ++j)
            if (bmom[i]==emom[j]) {
                if (i>1 && j>1)
                    fout << "COUSINS\n";
                else if (i==0) {
                    fout << names2[bessie] << " is the ";
                    for (int k=0; k<j; ++k) {
                        if (k==j-2)
                            fout << "grand-";
                        else if (k==j-1)
                            fout << "mother";
                        else
                            fout << "great-";
                    }
                    fout << " of " << names2[elsie] << '\n';
                }
                else if (j==0) {
                    fout << names2[elsie] << " is the ";
                    for (int k=0; k<i; ++k) {
                        if (k==i-2)
                            fout << "grand-";
                        else if (k==i-1)
                            fout << "mother";
                        else
                            fout << "great-";
                    }
                    fout << " of " << names2[bessie] << '\n';
                }
                else if (i==1 && j==1)
                    fout << "SIBLINGS\n";
                else if (i==1) {
                    fout << names2[bessie] << " is the ";
                    for (int k=1; k<j; ++k) {
                        if (k==j-1)
                            fout << "aunt";
                        else
                            fout << "great-";
                    }
                    fout << " of " << names2[elsie] << '\n';
                }
                else if (j==1) {
                    fout << names2[elsie] << " is the ";
                    for (int k=1; k<i; ++k) {
                        if (k==i-1)
                            fout << "aunt";
                        else
                            fout << "great-";
                    }
                    fout << " of " << names2[bessie] << '\n';
                }
                return 0;
            }
    fout << "NOT RELATED\n";
}
