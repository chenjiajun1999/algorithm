//
// Created by Hachikuji on 2022/9/6.
//

#include <bits/stdc++.h>

typedef long long bint;

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bint n, a, b;
    cin >> n >> a >> b;

    map<bint, bint> A;
    map<bint, bint> B;

    vector<bint> AKey;
    vector<bint> BKey;

    for (int i = 0; i < a; ++i) {
        int key, value;
        cin >> key >> value;
        AKey.emplace_back(key);
        A[key] = value;
    }
    for (int i = 0; i < b; ++i) {
        int key, value;
        cin >> key >> value;
        BKey.emplace_back(key);
        B[key] = value;
    }

    bint ans = 0;
    vector<bint> key;
    key = AKey.size() <= BKey.size() ? AKey : BKey;

    for (auto k : key) {
        ans += A[k] * B[k];
    }

    cout << ans;


    return 0;
}
