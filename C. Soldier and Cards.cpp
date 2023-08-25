#include <iostream>
#include <deque>
#include <utility>
using namespace std;
 
int main() {
	int cards, k1, k2;
	cin >> cards;
	deque<int>cards1, cards2;
	cin >> k1;
	for (int i = 0;i < k1;i++) {
		int temp;
		cin >> temp;
		cards1.push_back(temp);
	}
	cin >> k2;
	for (int i = 0;i < k2;i++) {
		int temp;
		cin >> temp;
		cards2.push_back(temp);
	}
	int rounds = 0;
	while (cards1.size() && cards2.size()) {
		if (cards1.front() > cards2.front()) {
			int temp = cards1.front();
			cards1.pop_front();
			cards1.push_back(cards2.front());
			cards1.push_back(temp);
			cards2.pop_front();
		}
		else {
			int temp = cards2.front();
			cards2.pop_front();
			cards2.push_back(cards1.front());
			cards2.push_back(temp);
			cards1.pop_front();
		}
		rounds++;
		if (rounds > 10000) {
			cout << -1;
			return 0;
		}
	}
	if (cards1.size()) cout << rounds << " " << 1;
	else cout << rounds << " " << 2;
}