//
// Created by Hachikuji on 2022/9/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long bint;

// 0 1 1 3 5 7
// 0 0 1 1 1 1

// 1 1 1 1 1 1 => 4
// 0 1 1 1 1 1 => 5
// 0 0 0 1 1 1 => 5


// 5 5 5 2 3 4 1000000 1
// 1 0 0 1 0 0 1       0

int main() {

    int m;
    cin >> m;

    // y and result
//    bint y[m], result[m];
    map<bint, pair<bint, bint>> resultMap;
    set<bint> ySet;
    for (int i = 0; i < m; ++i) {
        bint y, result;
        cin >> y >> result;
        ySet.insert(y);

        // first 为 0，second 为 1
        if (result == 0)
            resultMap[y].first++;
        else
            resultMap[y].second++;
    }
    vector<bint> key;
    for (auto y : ySet)
        key.push_back(y);

    // 统计
    for (int i = 1; i < key.size(); ++i) {
        resultMap[key[i]].first += resultMap[key[i - 1]].first;
    }
    for (int i = key.size() - 1; i >= 0; --i) {
        resultMap[key[i]].second += resultMap[key[i + 1]].second;
    }

    bint ans, sum, num = -1;
    for (int i = 0; i < key.size(); ++i) {

        if (i == 0)
            sum = resultMap[key[i]].second;
        else
            sum = resultMap[key[i - 1]].first + resultMap[key[i]].second;

        if (sum >= num) {
            num = sum;
            ans = key[i];
        }
    }

    cout << ans;
    return 0;
}
