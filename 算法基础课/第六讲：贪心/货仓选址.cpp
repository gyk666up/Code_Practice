// //不对
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=1e6+11;
// // int a[N];
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int n;cin>>n;
// //     double x=0;
// //     for(int i=1;i<=n;i++)
// //     {
// //         cin>>a[i];
// //         x+=a[i];
// //     }
// //     int ans=0;
// //     x/=n;
// //     for(int i=1;i<=n;i++)
// //     {
// //         ans+=abs(a[i]-x);
// //     }
// //     cout<<ans;
// //     return 0;
// // }

// //这道题的答案其实只有一个核心结论：货仓建在所有商店坐标的中位数处，距离之和最小。
// #include <iostream>
// #include <algorithm>
// #include <cmath>

// using namespace std;

// const int N = 100010;
// int a[N];

// int main() {
//     // 优化输入输出流
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     // 1. 将商店坐标从小到大排序
//     sort(a, a + n);

//     // 2. 寻找中位数坐标
//     // 如果 n 是奇数，a[n/2] 正好是最中间的元素
//     // 如果 n 是偶数，a[n/2] 是中间两个元素的偏右那个，也是完全合法的最优解
//     int mid = a[n / 2];

//     long long res = 0; // 距离之和可能会超出 int 范围，推荐用 long long
    
//     // 3. 计算所有商店到中位数货仓的距离之和
//     for (int i = 0; i < n; i++) {
//         res += abs(a[i] - mid);
//     }

//     cout << res << "\n";

//     return 0;
// }

