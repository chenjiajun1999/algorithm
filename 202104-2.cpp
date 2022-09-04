//
// Created by hachikuji on 2022/9/4.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, L, r, t;
    cin >> n >> L >> r >> t;

    int size = n + 2 * r + 1;
    int dn = r + 1;

    int A[size][size], B[size][size];
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));

    for (int i = dn; i < n + dn; ++i) {
        for (int j = dn; j < n + dn; ++j) {
            cin >> A[i][j];
            B[i][j] = 1;
        }
    }

    // 用前缀和算平均数
    for (int i = dn; i < size; ++i) {
        for (int j = dn; j < size; ++j) {
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
            B[i][j] += B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = dn; i < n + dn; ++i) {
        for (int j = dn; j < n + dn; ++j) {

            double a = A[i + r][j + r] - A[i - r - 1][j + r] - A[i + r][j - r - 1] + A[i - r - 1][j - r - 1];
            double b = B[i + r][j + r] - B[i - r - 1][j + r] - B[i + r][j - r - 1] + B[i - r - 1][j - r - 1];
            if (a / b <= t)
                ans++;
        }
    }
    cout << ans;

    return 0;
}