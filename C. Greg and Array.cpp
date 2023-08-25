#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
using namespace std;
 
int main() {
    int n, m, k, count = 1;
    cin >> n >> m >> k;
    vector<long long>el(n), operations(n + 1), query(m + 1);
    unordered_map<int, tuple<int, int, long long>>h;
    for (long long& e : el) 
        cin >> e;
 
    for (int i = 0;i < m;i++) {
        long long l, r, d;
        cin >> l >> r >> d;
        h.insert({ count, make_tuple(l - 1,r,d) });
        count++;
    }
 
    for (int i = 0;i < k;i++) {
        int x, y;
        cin >> x >> y;
        query[x - 1] += 1;
        query[y] -= 1;
    }
 
    for (int i = 1;i < m + 1;i++)
        query[i] += query[i - 1];
 
    for (int i = 1;i <= m;i++) {
        long long l = get<0>(h[i]), r = get<1>(h[i]), d = get<2>(h[i]);
 
        operations[l] += (d * query[i - 1]);
        operations[r] -= (d * query[i - 1]);
    }
 
    for (int i = 1;i < n + 1;i++)
        operations[i] += operations[i - 1];
 
    for (int i = 0;i < el.size();i++) {
        cout << el[i] + operations[i] << endl;
    }
 
}
 