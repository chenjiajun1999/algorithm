//
// Created by hachikuji on 2022/10/7.
//

#include "bits/stdc++.h"

using namespace std;


int ans = INT_MAX;
void dfs(vector<int> &prices, vector<int> &sum, int target, int current,int index) {

    if(current >= target){
        ans = min(current,ans);
        return;
    }

    if(ans == target)
        return;

    if(index == prices.size())
        return;

    if(index >0 && sum[prices.size() - 1] - sum[index - 1] + current < target)
        return;

    if(current >= ans)
        return;

    dfs(prices,sum,target,current+prices[index],index + 1);
    dfs(prices,sum,target,current,index + 1);

}

int main() {

    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    sort(prices.begin(),prices.end());
    vector<int> sum(n);
    sum[0] = prices[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = prices[i];
        sum[i] += sum[i - 1];
    }

    dfs(prices, sum, x, 0,0);
    cout << ans << endl;
    return 0;
}