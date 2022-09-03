#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, l, s;
    cin >> n >> l >> s;

    map<pair<int, int>, int> A, B;
    vector<pair<int, int>> key;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        A[{x, y}] = 1;
        key.emplace_back(x, y);
    }

    for (int i = s; i >= 0; i--) {
        for (int j = 0; j <= s; ++j) {
            cin >> B[{i, j}];
        }
    }

    int ans = 0;
    for (auto k:key) {

        int dx = k.first, dy = k.second;
        bool flag = true;

        for (int i = 0; i <= s; ++i) {
            for (int j = 0; j <= s; ++j) {

                if (dx + i > l || dy + j > l || A[{dx + i, dy + j}] != B[{i, j}]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            ans++;
    }

    cout << ans;
    return 0;

}
