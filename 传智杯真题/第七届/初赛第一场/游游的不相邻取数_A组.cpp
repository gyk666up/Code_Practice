// //没思路
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=1e3+11;
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     return 0;
// }

//先跳过吧

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // 存储每个数字含有的 2 和 5 的数量
    vector<int> c2(n), c5(n);
    int max_c5_sum = 0; // 记录理论上最多能有多少个 5

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        // 榨干这个数字里的 2
        while (val % 2 == 0) {
            c2[i]++;
            val /= 2;
        }
        // 榨干这个数字里的 5
        while (val % 5 == 0) {
            c5[i]++;
            val /= 5;
        }
        max_c5_sum += c5[i];
    }

    // dp0[j] 表示不选当前数，有 j 个 5 时，最多能有多少个 2
    // dp1[j] 表示选当前数，有 j 个 5 时，最多能有多少个 2
    // 初始化为 -1 表示这个状态目前达不到 (不能是 0，因为 0 代表有 0 个 2，也是一种合法状态)
    vector<int> dp0(max_c5_sum + 1, -1);
    vector<int> dp1(max_c5_sum + 1, -1);
    
    // 初始边界：一个数都不选的时候，有 0 个 5 和 0 个 2
    dp0[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<int> next_dp0(max_c5_sum + 1, -1);
        vector<int> next_dp1(max_c5_sum + 1, -1);

        for (int j = 0; j <= max_c5_sum; j++) {
            // 1. 本轮不选第 i 个数：前一个数选或不选都可以，取较大值
            if (dp0[j] != -1 || dp1[j] != -1) {
                next_dp0[j] = max(dp0[j], dp1[j]);
            }
            
            // 2. 本轮要选第 i 个数：前一个数必须【不选】
            // 并且必须保证现在的 j 至少大于等于当前数字自带的 5 的数量 (c5[i])
            if (j >= c5[i] && dp0[j - c5[i]] != -1) {
                next_dp1[j] = dp0[j - c5[i]] + c2[i];
            }
        }
        // 滚动更新数组
        dp0 = next_dp0;
        dp1 = next_dp1;
    }

    // 统计最终答案：遍历所有可能的 5 的数量 j
    int ans = 0;
    for (int j = 0; j <= max_c5_sum; j++) {
        int max_2 = max(dp0[j], dp1[j]); // 不管最后一个数选没选，看最多能拿到多少个 2
        if (max_2 != -1) {
            // 0 的数量取决于 2 和 5 中较少的那一个
            ans = max(ans, min(j, max_2));
        }
    }

    cout << ans << "\n";
    return 0;
}