// //跟上面那道题代码一模一样
//好好理解和上一道题的区别
// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 100010;

// struct Range {
//     int l, r;
//     // 按右端点从小到大排序
//     bool operator< (const Range &W) const {
//         return r < W.r;
//     }
// } ranges[N];

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     if (!(cin >> n)) return 0;

//     for (int i = 0; i < n; i ++ ) {
//         cin >> ranges[i].l >> ranges[i].r;
//     }

//     sort(ranges, ranges + n);

//     int res = 0;
//     int ed = -2e9; 

//     for (int i = 0; i < n; i ++ ) {
//         // 当前区间的开头，严格晚于上一个选定区间的结尾
//         if (ranges[i].l > ed) {
//             res ++ ;           // 选中该区间
//             ed = ranges[i].r;  // 更新“已被占用的最右边界”
//         }
//     }

//     cout << res << endl;
//     return 0;
// }

// //按照最短点做
// #include <bits/stdc++.h>
// using namespace std;

// // 定义最大区间数量
// const int MAX_N = 1e5 + 10;

// int n, cnt, ed; // 输入的区间数量，已选择的区间数量，当前已选择区间的右端点
// struct Range // 区间结构体
// {
//     int l, r; // 区间的左端点和右端点
//     bool operator<(const Range &ws) const // 重载 < 运算符，用于排序区间
//     {
//         return l < ws.l; // 按照左端点进行升序排序
//     }
// } range[MAX_N]; // 存储区间的数组

// int main()
// {
//     // 输入区间数量
//     cin >> n;

//     // 循环读取每个区间的左端点和右端点
//     for (int i = 0; i < n; i++)
//     {
//         cin >> range[i].l >> range[i].r;
//     }

//     // 对区间按照左端点进行升序排序
//     sort(range, range + n);

//     // 初始化已选择区间的右端点为第一个区间的右端点
//     ed = range[0].r;

//     // 初始化已选择区间的数量为1
//     cnt = 1;

//     // 遍历排序后的区间数组，从第二个区间开始
//     for (int i = 1; i < n; i++)
//     {
//         // 如果当前区间的左端点小于等于已选择区间的右端点
//         if (range[i].l <= ed)
//         {
//             // 更新已选择区间的右端点为当前区间的右端点和已选择区间的右端点中的较小值
//             ed = min(ed, range[i].r);//代码在逻辑上抛弃了那个长得拖沓的区间，保留了短小精悍的区间
//         }
//         else
//         {
//             // 如果当前区间的左端点大于已选择区间的右端点
//             // 更新已选择区间的右端点为当前区间的右端点
//             ed = range[i].r;

//             // 增加已选择区间的数量
//             cnt++;
//         }
//     }

//     // 输出已选择区间的数量
//     cout << cnt << endl;

//     return 0;
// }

