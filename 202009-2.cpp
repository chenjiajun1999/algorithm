//
// Created by Alberta on 2022/9/5.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, t, xl, yd, xr, yu;
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;

    vector<vector<pair<int, int>>> trails;
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> trail;
        for (int j = 0; j < t; ++j) {
            int x, y;
            cin >> x >> y;
            trail.emplace_back(x, y);
        }
        trails.emplace_back(trail);
    }

    int ans[2] = {0};
    for (const auto &trail:trails) {
        bool flag = false;
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < trail.size(); i++) {
            int x = trail[i].first, y = trail[i].second;
            if (x <= xr && x >= xl && y <= yu && y >= yd) {
                flag = true;
                if (i == 0)
                    continue;
                int xp = trail[i - 1].first, yp = trail[i - 1].second;
                if (xp <= xr && xp >= xl && yp <= yu && yp >= yd) {
                    count++;
                    maxCount = max(maxCount, count);
                } else {
                    count = 1;
                }

            }
        }
        if (maxCount >= k)
            ans[1]++;
        if (flag)
            ans[0]++;
    }

    cout << ans[0] << endl;
    cout << ans[1] << endl;
    return 0;
}