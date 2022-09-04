//
// Created by Hachikuji on 2022/9/3.
//
#include <bits/stdc++.h>

using namespace std;

// r = N/(n+1) g(x) = x/r
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, N;
    cin >> n >> N;
    int r = N / (n + 1);
    vector<int> A(n + 1);

    for (int i = 1; i < A.size(); ++i) {
        cin >> A[i];
    }

    int index = 1;
    int f = 0;
    int g = 0;
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        if (i >= A[index] && index < n + 1) {
            f++;
            index++;
        }
        g = i / r;
        ans += abs(g - f);
    }
    cout << ans;
    return 0;

}
