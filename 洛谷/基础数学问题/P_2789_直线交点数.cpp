// #include <iostream>
// #include <unordered_set>
// using namespace std;
// //定义dp[i]为i条直线时所有可能的交点数集合。

// //假设有m条直线互相平行（1 ≤ m ≤ i）
// //剩下的i-m条直线之间任意相交
// //这m条平行线与剩下的i-m条直线每条都会相交，产生 m × (i-m) 个新交点
// int main() {
//     int n;
//     cin >> n;
//     unordered_set<int> dp[26]; // dp[i]存储i条直线的所有可能交点数
//     dp[0].insert(0); // 0条直线时，交点数为0
    
//     //理解一下m=1的含义
//     for (int i = 1; i <= n; ++i) {
//         for (int m = 1; m <= i; ++m) { // 枚举当前平行组的大小m
//             int remaining = i - m;     // 剩余的直线数
//             for (int j : dp[remaining]) {
//                 dp[i].insert(j + m * remaining); // 新增交点数：m * remaining
//             }
//         }
//     }
    
//     cout << dp[n].size() << endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=30;
int main()
{
    unordered_set<int>dp[N];
    int n;cin>>n;
    dp[0].insert(0);
    for(int i=1;i<=n;i++)
    {
        for(int m=1;m<=i;m++)
        {
            int remain=i-m;
            for(int j:dp[remain])//把所有的情况都枚举一下
            {
                dp[i].insert(j+m*remain);
            }
        }
    }
    cout<<dp[n].size();
}