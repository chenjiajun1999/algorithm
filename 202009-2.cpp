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

    vector<pair<int, int>> box;
    for (int i = 0; i < 2; ++i) {
        int x, y;
        cin >> x >> y;
        box.emplace_back(x, y);
    }


    return 0;
}