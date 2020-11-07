#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    //cout << t;
    for (int b = 0; b < t; b++) {
        int a;
        cin >> a;
		string s = to_string(a);
		vector<pair<int, int>> digs;
		int nonzerocnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '0') {
				nonzerocnt++;
				digs.push_back({s[i] - '0', s.length()-i});
			}
		}
		cout << nonzerocnt << endl;
		for (int i = 0; i < digs.size(); i++) {
			cout << digs[i].first * pow(10, digs[i].second-1) << " ";
		}
		cout << endl;
    }

    return 0;
}
