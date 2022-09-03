#include <bits/stdc++.h>

using namespace std;

// 24 -> t+k ~ t+k+23
// t1 <= t+k+23 => t > t1 - k - 23
// t1 >= t+k    => t <= t1 - k


int main() {

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> events;

    for (int i = 0; i < n; ++i) {
        int t, c;
        cin >> t >> c;
        events.emplace_back(t, c);
    }

    int queries[m];
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }

    multiset<pair<int, int>> eventSet;
    map<pair<int, int>, int> eventMap;

    for (auto e:events) {
        int t = e.first, c = e.second;
        int t1 = t - k - c;
        int t2 = t - k;
        if (eventMap[{t1, t2}] == 0) {
            eventSet.insert({t1, t2});
        }
        eventMap[{t1, t2}]++;

    }

    for (auto q:queries) {
        int ans = 0;

        for (auto e:eventSet) {
            int t1 = e.first, t2 = e.second;
            if (q > t1) {
                if (q <= t2) {
                    ans += eventMap[{t1, t2}];
                }
            }else{
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}