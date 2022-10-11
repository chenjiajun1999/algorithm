//
// Created by Hachikuji on 2022/9/3.
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, N;
    cin >> n >> N;
    vector<int> A(n + 1);
    //vector<int> F(N);

    for (int i = 1; i < A.size(); ++i) {
        cin >> A[i];
    }

    int index = 1;
    int cur = 0;
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        if (i >= A[index] && index < n + 1) {
            cur++;
            index++;
        }
        //F[N] = cur;
        ans += cur;
    }
    cout << ans;
    return 0;
}
