//
// Created by Hachikuji on 2022/9/7.
//

#include <bits/stdc++.h>


using namespace std;
typedef long long bint;

struct Node {

    int id{};
    int partId{};
    multiset<bint> appIds;

    /**
     * 选择此时运行计算任务数量最少的计算节点；
     * 选择编号最小的计算节点。
     * @param n
     * @return
     */
    bool operator<(const Node &n) const {

        int size1 = appIds.size();
        int size2 = n.appIds.size();
        return size1 != size2 ? size1 < size2 : id < n.id;
    }
};

int main() {

    int n, m, q;
    cin >> n >> m;

    set<Node> nodes;
    map<int, set<bint>> parts;

    for (int i = 1; i <= n; ++i) {
        int partId;
        cin >> partId;

        Node node;
        node.id = i;
        node.partId = partId;
        nodes.insert(node);
        parts[partId].insert(node.id);

    }

    cin >> q;
    /**
     * na 计算节点亲和性，必须在指定可用区上
     *
     * pa 计算任务亲和性，必须和指定应用的计算任务在同一可用区上
     * 要求能通过 appId 找到对应的可用区
     *
     * paa 计算任务反亲和性，不能和指定应用的计算任务在同一个计算节点上
     *
     * paar 计算任务亲和性，1 => 必须满足 0  => 尽量满足
     */

    vector<vector<int>> answer;
    for (int i = 0; i < q; ++i) {

        int f, na, paar;
        bint a, pa, paa;
        cin >> f >> a >> na >> pa >> paa >> paar;

        vector<int> ans;
        for (int j = 0; j < f; j++) {

            Node target;
            for (auto &node : nodes) {

                if ((na == 0 || na == node.partId)
                    && (pa == 0 || parts[node.partId].count(pa) != 0)
                    && (paa == 0 || node.appIds.count(paa) == 0)) {
                    target = node;
                    break;
                }
            }
            /**
             * 在这个阶段，先根据计算任务的要求，过滤出所有满足要求的计算节点。
             * 如果不存在这样的计算节点，并且指定了计算任务反亲和性要求，并且计算任务反亲和性要求是尽量满足的，
             * 那么去掉计算任务反亲和性要求，再过滤一次。如果还不存在，就认为该计算任务的要求无法满足，该计算任务无法分配。
             */
            if (target.id == 0 && paar == 0 && paa != 0) {
                for (auto &node : nodes) {
                    if ((na == 0 || na == node.partId)
                        && (pa == 0 || parts[node.partId].count(pa) != 0)) {
                        target = node;
                        break;
                    }
                }
            }

            // 找到
            if (target.id != 0) {
                nodes.erase(target);
                target.appIds.insert(a);
                parts[target.partId].insert(a);
                nodes.insert(target);
            }
            ans.push_back(target.id);
        }

        answer.push_back(ans);
    }

    for (const auto &ans:answer) {
        for (auto a : ans) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}