//
// Created by DIY on 2022/10/7.
//

#include "bits/stdc++.h"

using namespace std;

struct info {
    int d{};
    int u{};
    int r{};

    info(int d, int u, int r) {
        this->d = d;
        this->u = u;
        this->r = r;
    }
};

int main() {

    int n;
    cin >> n;

    unordered_map<int, vector<pair<int, int>>> danger_areas;
    priority_queue<pair<int, int>> danger_users;
    vector<vector<info>> total_infos;

    for (int i = 0; i < n; i++) {

        int r, m;
        cin >> r >> m;

        for (int j = 0; j < r; j++) {
            int dr;
            cin >> dr;
            //;

            if(danger_areas.count(dr) == 0){
                danger_areas[dr].push_back({i,i+6});
                continue;
            }

            // 连续的要合并
            pair<int,int>& last = danger_areas[dr][danger_areas[dr].size()-1];
            if(last.second >= i)
                last.second = i+6;
            else
                danger_areas[dr].push_back({i,i+6});

        }

        /**
         * 该用户在近 7 日内曾经出现在接收到的漫游数据中，并且近 7 日内有到访某个地区的记录；
         * 该用户在近 7 日内到访的地区在到访的那一日处于风险状态；
         * 上述存在风险的地区自到访日至生成名单当日持续处于风险状态。
         */
        vector<info> infos;
        for (int j = 0; j < m; j++) {
            int d, u, ri;
            cin >> d >> u >> ri;
            infos.emplace_back(info(d, u, ri));
        }
        total_infos.push_back(infos);

        set<int> ans;
        for (int j = i; j >= i - 6 && j >= 0; j--) {
            for (auto msg : total_infos[j]) {
                if (msg.d < i - 6)
                    continue;
                if (danger_areas.count(msg.r) == 0)
                    continue;
                auto day = danger_areas[msg.r];
                for(auto d:day){
                    if(d.first <= msg.d && d.second>= msg.d && d.second>=i)
                        ans.insert(msg.u);
                }
            }
        }


        cout << i << " ";

        for (int an : ans)
            cout << an << " ";

        cout << endl;
    }

    return 0;
}