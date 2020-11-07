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
    for (int r = 0; r < t; r++) {
        int n;
		cin >> n;
		vector<int> candies;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			candies.push_back(temp);
		}

		int curSize = candies[0];
		int alice = curSize, bob = 0, moves = 1;
		candies.erase(candies.begin());
		bool possible = true;
		bool isBob = true;
		while (candies.size() > 0 && possible) {
			//cout << "size: " << candies.size() << endl;
			moves++;
			int curSum = 0;
			int eaten = 0;
			if (isBob) {
				while (curSum <= curSize && candies.size() != 0) {
					curSum += candies[candies.size()-1];
					candies.pop_back();
					eaten++;
				}
				bob += curSum;
				if (curSum <= curSize) {
					possible = false;
				}
			}
			else {
				while (curSum <= curSize && candies.size() != 0) {
					curSum += candies[0];
					candies.erase(candies.begin());
					eaten++;
				}
				alice += curSum;
				if (curSum <= curSize) {
					possible = false;
				}
			}
			curSize = curSum;
			isBob = !isBob;
		}
		cout << moves << " " << alice << " " << bob << endl;
	}

    return 0;
}
