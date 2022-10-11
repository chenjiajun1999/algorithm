//
// Created by Hachikuji on 2022/9/7.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> a(n + 1);
    a[0] = 1;
    for (int i = 0; i < k; ++i) {
        int left, right;
        cin >> left >> right;
        if (a[right] == 0) {
            ans++;
        }
        a[left] = 1;
    }
    cout << ans;
    return 0;
}