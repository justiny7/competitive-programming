#include <bits/stdc++.h>
using namespace std;
//Yay worked first try
ifstream fin("auto.in");
ofstream fout("auto.out");

int n, w;
vector<pair<string, int>> dict;

int main(void) {
    fin >> w >> n;
    dict.resize(w);
    for (int i=0; i<w; ++i)
        fin >> dict[i].first, dict[i].second=i+1;
    sort(dict.begin(), dict.end());
    while (n--) {
        int k;
        string s;
        fin >> k >> s;
        int pos=lower_bound(dict.begin(), dict.end(), make_pair(s, 0))-dict.begin()+k-1;
        if (pos<w && dict[pos].first.size()>=s.size() && dict[pos].first.substr(0, s.size())==s)
            fout << dict[pos].second << '\n';
        else
            fout << "-1\n";
    }
}
