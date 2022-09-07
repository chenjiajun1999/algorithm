//
// Created by Hachikuji on 2022/9/7.
//

#include <bits/stdc++.h>


using namespace std;
typedef long long bint;

struct Node {
    int id{};
    int size{};
    set<bint> AppIds;

    // 选择此时运行计算任务数量最少的计算节点；
    // 选择编号最小的计算节点。
    bool operator<(const Node &n) const {
        return size != n.size ? size < n.size : id <= n.id;
    }
};

int main() {

    int n, m, q;
    cin >> n >> m;

    map<int, set<Node>> parts;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        Node node;
        node.id = i + 2;
        parts[a].insert(node);
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {

        int f, na, paar;
        bint a, pa, paa;
        cin >> f >> a >> na >> pa >> paa >> paar;
    }


    return 0;
}