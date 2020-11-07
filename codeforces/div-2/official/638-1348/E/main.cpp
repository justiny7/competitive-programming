#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;

	long long int bucketCount = 0;

	vector<pair<long long int, long long int>> shrubs (n);

	for (int i = 0; i < n; i++)
		cin >> shrubs[i].first >> shrubs[i].second;

	for (int i = 0; i < n; i++) {
		if ((shrubs[i].first + shrubs[i].second) >= k) {
			bucketCount += (shrubs[i].first + shrubs[i].second) / k;
			long long int curCount = (shrubs[i].first + shrubs[i].second) / k;

			if (i != n-1) {
				if (shrubs[i].first > shrubs[i].second) {
					long long int remainder = shrubs[i].first - k * curCount;
					//cout << "remainder: " << remainder << endl;
					shrubs[i+1].first +=  max((long long int) 0, remainder);

					if (remainder < 0) {
						shrubs[i+1].second += shrubs[i].second + remainder;
					}
					else {
						shrubs[i+1].second += shrubs[i].second;
					}
				}
				else {
					long long remainder = shrubs[i].second - k * curCount;
					shrubs[i+1].second +=  max((long long int) 0, remainder);

					if (remainder < 0) {
						shrubs[i+1].first += shrubs[i].first + remainder;
					}
					else {
						shrubs[i+1].first += shrubs[i].first;
					}
				}
			}
		}
	}
	cout << bucketCount << endl;
	


}