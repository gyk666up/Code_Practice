// // //1. 排序（按左端点排）
// // //2. 寻找能覆盖当前起点的“最远”区间
// // //3. 更新起点，继续贪心
// // //如果连一个左端点 $\le$ start 的区间都找不到，说明出现了“断层”，永远无法覆盖到终点，直接输出 -1。如果找到了，就把刚才找到的最大右端点 max_r 当作我们新的需要覆盖的起点（即 start = max_r），并且使用的区间数量 +1。
// // //4. 终点检查 每次更新完 start 后，检查一下 start 是否已经 $\ge t$ 了
// // #include <iostream>
// // #include <algorithm>

// // using namespace std;

// // const int N = 100010;

// // // 定义区间结构体
// // struct Range {
// //     int l, r;
// //     // 1. 排序规则：重载小于号，让区间按照【左端点】从小到大排序
// //     bool operator< (const Range &W) const {
// //         return l < W.l;
// //     }
// // } ranges[N];

// // int main() {
// //     // 优化输入输出速度
// //     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
// //     int st, ed;
// //     cin >> st >> ed; // 读取目标覆盖区间的起点和终点
    
// //     int n;
// //     cin >> n;
    
// //     for (int i = 0; i < n; i++) {
// //         int l, r;
// //         cin >> l >> r;
// //         ranges[i] = {l, r};
// //     }

// //     // 1. 排序（按左端点排）
// //     sort(ranges, ranges + n);

// //     int res = 0; // 记录使用的最少区间数量
// //     bool success = false; // 标记是否成功完全覆盖

// //     // 遍历所有区间
// //     for (int i = 0; i < n; i++) {
// //         // 双指针思想的内层指针 j，以及记录当前能延伸的最远右端点 max_r
// //         int j = i, max_r = -2e9; 
        
// //         // 2. 寻找能覆盖当前起点 st 的“最远”区间
// //         // 条件：下一个区间的左端点必须 <= 当前需要的起点 st
// //         while (j < n && ranges[j].l <= st) {
// //             max_r = max(max_r, ranges[j].r);
// //             j++;
// //         }

// //         // 3. 断层检查：如果哪怕是最大的右端点，都够不到现在的起点 st，说明中间断开了
// //         if (max_r < st) {
// //             break; // 彻底没救了，跳出循环
// //         }

// //         // 找到了一截能连上的，使用区间数 +1
// //         res++; 
        
// //         // 4. 终点检查：如果当前拉扯到的最远右端点已经盖过了目标终点，大功告成！
// //         if (max_r >= ed) {
// //             success = true;
// //             break;
// //         }

// //         // 核心贪心：更新新的起点，下一次就要从 max_r 开始往后接了
// //         st = max_r;
        
// //         // 优化：跳过中间已经被 while 循环检查过的无用区间
// //         i = j - 1; 
// //     }

// //     // 输出结果
// //     if (success) cout << res << "\n";
// //     else cout << "-1\n";

// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// struct node
// {
//     int l,r;
//     bool operator<(const node&u)
//     {
//         return l<u.l;
//     }
// }range[N];
// int st,ed;
// int n;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>st>>ed;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>range[i].l>>range[i].r;
//     }
//     sort(range+1,range+1+n);
    
//     // int maxr=-2e9;
//     bool f=0;
//     int res=0;
//     for(int i=1;i<=n;i++)
//     {
//         int maxr=-2e9;//注意这行代码的位置
//         int j=i;
//         while(j<=n&&range[j].l<=st)
//         {
//             maxr=max(maxr,range[j].r);
//             j++;
//         }
//         //这个也很关键
//         if(maxr<st)//拼不起来
//         {
//             break;
//         }
//         res++;
//         if(maxr>=ed)
//         {
//             f=1;
//             break;
//         }
//         st=maxr;
//         i=j-1;
//     }
//     if(f)cout<<res;
//     else cout<<-1;
//     return 0;
// }

//假设目标区间是 [1, 10]。给定的区间是 [1, 4] 和 [6, 10]，中间 [4, 6] 断开了。
//第一轮循环 (i=1)： 找到了 [1, 4]，此时 maxr 被更新为 4。
//循环结尾处，st 被更新为 maxr，也就是 st = 4。第二轮循环 (i=2)： 此时 st = 4。
//遇到下一个区间 [6, 10]，因为它的左端点 6 > st，所以while 循环根本不会执行。
//灾难发生： 因为 while 没执行，maxr 依然保留着上一轮的值（4）。
//接下来执行判断：if(maxr < st) $\rightarrow$ if(4 < 4)，结果是 False！本该触发的断层 break 被完美绕过了！
//死循环： 程序接着往下走，错误地执行了 res++，然后 st = 4（没变），最后 i = j - 1 $\rightarrow$ i = 2 - 1 = 1。紧接着 for 循环自己的 i++ 把 i 又变回了 2。
//程序永远卡在了 i=2 这一步，无限轮回。
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int st,ed;
struct node
{
    int l,r;
    bool operator<(const node&u)
    {
        return l<u.l;
    }
}range[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>st>>ed;
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>range[i].l>>range[i].r;
    sort(range+1,range+1+n);
    int res=0;
    bool f=0;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        int maxr=-2e9;
        while(j<=n&&range[j].l<=st)
        {
            maxr=max(maxr,range[j].r);
            j++;
        }
        if(maxr<st)
        {
            break;
        }
        res++;
        if(maxr>=ed)
        {
            f=1;
            break;
        }
        st=maxr;
        i=j-1;
    }
    if(f)cout<<res;
    else cout<<-1;
    return 0;  
}