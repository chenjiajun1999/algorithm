//
// Created by hachikuji on 2022/9/4.
//

#include <bits/stdc++.h>

using namespace std;

// 前缀和 +1 后面的数都会加 1
// 后缀和 +1 前面的数都会加 1

// 先去重
// d[n]
// |  露出前面都 +1       露出前面都 -1
// |     x
// |   x   x               x   x
// |                         x
// |
//  ----------------------------- a[n]

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n + 2);
    A[0] = 0;
    A[n + 1] = 0;

    int P_MAX = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        P_MAX = max(A[i], P_MAX);
    }
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<int> P(P_MAX + 1);

    for (int i = 1; i < A.size() - 1; ++i) {

        if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
            P[A[i]]++;
        }
        if (A[i - 1] > A[i] && A[i + 1] > A[i]) {
            P[A[i]]--;
        }
    }

    int ans = 0, sum = 0;
    for (int i = P_MAX; i >= 0; --i) {
        sum += P[i];
        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}