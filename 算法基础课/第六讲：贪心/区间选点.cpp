// //直观感受：“寻找最急迫的区间”
// // 从物理意义上讲：

// // 左端点只代表区间什么时候开始，它不能告诉你区间什么时候结束。一个很早开始的区间，可能很晚才结束（比如 [1, 100]），它一点都不“着急”。

// // 右端点代表了区间的死亡时间。按右端点排序，意味着我们总是挑出最快要结束、最急迫的区间。为了不漏掉它，我们必须在它“死掉”的最后一刻（它的右端点）插上一根针。这样不仅保住了这个急迫的区间，还能顺带刺穿后面跟过来的其他区间。
// // #include <iostream>
// // #include <algorithm>

// // using namespace std;

// // const int N = 100010;

// // // 定义一个结构体来存储区间
// // struct Range {
// //     int l, r;
// //     // 重载小于号，告诉 sort 函数我们要按右端点升序排列
// //     bool operator< (const Range &W) const {
// //         return r < W.r;
// //     }
// // } ranges[N];

// // int main() {
// //     // 优化输入输出流
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int n;
// //     if (!(cin >> n)) return 0;

// //     for (int i = 0; i < n; i ++ ) {
// //         cin >> ranges[i].l >> ranges[i].r;
// //     }

// //     // 1. 按右端点从小到大排序
// //     sort(ranges, ranges + n);

// //     int res = 0;               // 记录需要的点的总数
// //     int ed = -2e9;             // 记录上一个选出的点的位置，初始化为负无穷

// //     // 2. 遍历所有区间
// //     for (int i = 0; i < n; i ++ ) {
// //         // 如果当前区间的左端点，严格大于上一个放下的点
// //         // 说明当前区间没有被覆盖，必须新加一个点
// //         if (ranges[i].l > ed) {
// //             res ++ ;           // 新增一个点
// //             ed = ranges[i].r;  // 贪心策略：把这个新点放在当前区间的右端点
// //         }
// //     }

// //     cout << res << endl;
// //     return 0;
// // }

// //很巧妙
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// struct node
// {
//     int l,r;
//     bool operator<(const node&u)
//     {
//         return r<u.r;
//     }
// }range[N];
// int n;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>range[i].l>>range[i].r;
//     }
//     sort(range+1,range+1+n);
//     int res=0;
//     int ed=-2e9;
//     for(int i=1;i<=n;i++)
//     {
//         //区间没有覆盖
//         if(range[i].l>ed)
//         {
//              res++;
//              ed=range[i].r;
//         }
//     }
//     cout<<res;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int n;
struct node
{
    int l,r;
    bool operator<(const node&u)
    {
        return r<u.r;
    }
}range[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>range[i].l>>range[i].r;
    sort(range+1,range+1+n);
    int res=0;
    int ed=-2e9;
    for(int i=1;i<=n;i++)
    {
        if(range[i].l>ed)//和前一个区间没有重合
        {
            res++;
            ed=range[i].r;
        }
    }
    cout<<res;
    return 0;
}