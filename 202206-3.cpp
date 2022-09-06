//
// Created by Alberta on 2022/9/6.
//

#include <bits/stdc++.h>

using namespace std;

/**
 * 判断一个角色能否对某个资源执行某个操作的过程是：
 * 检查该角色的操作清单，如果该角色的操作清单中不包含该操作，且该角色的操作清单中也不包含字符串 *，那么不能执行该操作；
 * 检查该角色的资源种类清单，如果该角色的资源种类清单中不包含该资源的种类，且该角色的资源种类清单中也不包含字符串 *，那么不能执行该操作；
 * 检查该角色的资源名称清单，如果该角色的资源名称清单中不包含该资源的名称，且该角色的资源名称清单不是空数组，那么不能执行该操作；
 * 允许执行该操作。
 */

/**
 * 判断一个用户能否执行某个操作的过程是：
 * 检查所有的角色关联的授权对象清单，如果清单中包含该用户的名称，或者该清单中包含该用户所属的某一个用户组的名称，那么选取该角色关联所关联的角色；
 * 对于所有被选取的角色，判断这些角色是否能对该资源执行该操作，如果所有角色都不能执行该操作，那么不能执行该操作；
 * 允许执行该操作。
 */

struct Role {
    string name;
    set<string> apis;
    set<string> srcTypes;
    set<string> srcNames;
};

int main() {

    int n, m, q;
    cin >> n >> m >> q;

    map<string, Role> roles;
    for (int i = 0; i < n; ++i) {
        Role role;
        int nv, no, nn;
        cin >> role.name >> nv;
        for (int j = 0; j < nv; ++j) {
            string api;
            cin >> api;
            role.apis.insert(api);
        }
        cin >> no;
        for (int j = 0; j < no; ++j) {
            string type;
            cin >> type;
            role.srcTypes.insert(type);
        }
        cin >> nn;
        for (int j = 0; j < nn; ++j) {
            string name;
            cin >> name;
            role.srcNames.insert(name);
        }
        roles[role.name] = role;
    }

    map<string, vector<Role>> users;
    map<string, vector<Role>> groups;

    for (int i = 0; i < m; ++i) {

        string name;
        int ns;
        cin >> name >> ns;
        for (int j = 0; j < ns; ++j) {
            string type, roleName;
            cin >> type >> roleName;
            if (type == "u") {
                users[name].emplace_back(roles[roleName]);
            } else {
                groups[name].emplace_back(roles[roleName]);
            }
        }
    }

    // 请求
    for (int i = 0; i < q; ++i) {
        string userName;
        int ng;
        cin >> userName >> ng;
        vector<string> roleNames;
        for (const auto &r:users[userName]) {
            roleNames.emplace_back(r.name);
        }
        for (int j = 0; j < ng; ++j) {
            // 加入用户拥有的角色
            string groupName;
            cin >> groupName;
            for (const auto &r:groups[groupName]) {
                roleNames.emplace_back(r.name);
            }
        }

        string request, type, name;
        cin >> request >> type >> name;
        bool flag = false;
        for (const auto &r:roleNames) {
            if ((!roles[r].srcNames.empty() || roles[r].srcNames.count(name) != 0)
                && roles[r].srcTypes.count(type) != 0
                && roles[r].apis.count("*") != 0 || roles[r].apis.count(request) != 0) {
                flag = true;
                break;
            }
        }
        cout << (flag ? 1 : 0) << endl;
    }

    return 0;
}