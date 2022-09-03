#include <bits/stdc++.h>

using namespace std;

// 24 -> t+k ~ t+k+23
// t1 <= t+k+23 => t > t1 - k - c   => t >= t1 - k - c + 1
// t1 >= t+k    => t <= t1 - k

// 使用差分数组 [L,R] + v => d[L]+v,d[R+1]-v
// 第 i 个位置加上 1 的话，从 i 个位置开始后面的数通过前缀和都会加上 1
// 所以在 j + 1 后面要减掉 1

int main() {

    const int MAX = 300000;

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> times(MAX);
    vector<int> queries(m);

    for (int i = 0; i < n; ++i) {
        int t, c;
        cin >> t >> c;
        int t1 = max(1, t - c + 1);
        int t2 = min(MAX - 2, t);
        times[t1]++;
        times[t2 + 1]--;
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    for (int i = 1; i < MAX; i++) {
        times[i] = times[i - 1] + times[i];
    }

    for (auto q:queries) {
        cout << times[q + k] << endl;
    }
    return 0;
}