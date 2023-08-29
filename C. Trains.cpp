#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    long long _gcd = gcd(a, b);
    long long lcm = (a / _gcd) * b;

    long long dasha = lcm / a, masha = lcm / b;

    if (a > b)
        masha--;

    else
        dasha--;

    if (dasha > masha)
        cout << "Dasha";
    else if (dasha < masha)
        cout << "Masha";
    else
        cout << "Equal";

    return 0;
}
