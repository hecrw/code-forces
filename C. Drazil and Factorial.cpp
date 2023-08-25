#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
	string num, result = "";
	int n;
	cin >> n>>num;
	for (char c : num) {
		if (c - '0' == 4) result += "322";
		else if (c - '0' == 6) result += "53";
		else if (c - '0' == 8) result += "7222";
		else if (c - '0' == 9) result += "7332";
		else if (c - '0' != 1 && c - '0' != 0) {
			result += c;
		}
	}
	sort(result.begin(), result.end());
	for (int i = result.size() - 1;i >= 0;i--) cout << result[i];
}