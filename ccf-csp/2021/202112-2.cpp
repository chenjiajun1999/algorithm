//
// Created by Hachikuji on 2022/9/3.
//
#include <bits/stdc++.h>

using namespace std;

// r = N/(n+1) g(x) = x/r

// 0  |2    |5    |8  |10
// 0 1 2 3 4 5 6 7 8 9 -
// 0 0 1 1 1 2 2 2 3 3 -
// 0 0 1 1 2 2 3 3 4 4 -
// 0  |2    |5    |8  |10

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, N;
    cin >> n >> N;

    // 步长
    long long r = N / (n + 1);
    vector<long long> A;

    A.push_back(0);
    for (long long i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        A.push_back(a);
    }
    A.push_back(N);


    long long ans = 0;
    long long right = 0;
    long long dr = r;
    for (long long i = 0; i < A.size() - 1; ++i) {
        for (long long j = A[i]; j < A[i + 1]; j += dr) {

            long long gx = j / r;

            // 可能会连续超
            if (right != 0) {
                dr = right;
                right = 0;
            } else {
                dr = r;
            }

            long long left = A[i + 1] - j;
            if (left < dr) {
                right = dr - left;
                ans += abs(i - gx) * left;
            } else {
                ans += abs(i - gx) * dr;
            }
        }
    }
    cout << ans << endl;
    return 0;

}
