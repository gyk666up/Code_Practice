// //
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e4+11;
// struct node
// {
//     int  w,s;
//     bool operator<(const node&u)
//     {
//         if(s!=u.s)return s>u.s;
//         else return w>u.w;
//     }
// }row[N];
// int n;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>row[i].w>>row[i].s;
//     }
//     sort(row+1,row+1+n);
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         ans+=(i)
//     }
//     return 0;
// // }

// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 50010;

// // 定义奶牛结构体
// struct Cow {
//     int w, s;
//     // 重载小于号：按照 (重量 + 强壮度) 从小到大排序
//     bool operator<(const Cow &other) const {
//         return (w + s) < (other.w + other.s);
//     }
// } cows[N];

// int main() {
//     // 优化输入输出流
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         cin >> cows[i].w >> cows[i].s;
//     }

//     // 1. 按照我们的贪心策略进行排序
//     sort(cows, cows + n);

//     long long current_weight = 0; // 记录当前牛头顶上的总重量
//     long long max_risk = -2e18;   // 记录全局最大风险，注意初始化为极小值（因为风险可能为负）

//     // 2. 从上到下遍历奶牛，计算风险
//     for (int i = 0; i < n; i++) {
//         // 当前牛的风险 = 头顶总重量 - 自己的强壮度
//         long long risk = current_weight - cows[i].s;
        
//         // 更新全局最大风险
//         max_risk = max(max_risk, risk);
        
//         // 把当前牛的重量累加进去，压给下一头牛
//         current_weight += cows[i].w;
//     }

//     cout << max_risk << "\n";

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=50002;
struct node
{
    int w,s;
    bool operator<(const node&u)
    {
        return s+w<u.s+u.w;//注意这个推导是如何
    }
}row[N];
int n;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>row[i].w>>row[i].s;
    }
    sort(row+1,row+1+n);
    int curr_weight=0;
    int res=-2e9;
    for(int i=1;i<=n;i++)
    {
        int now_=curr_weight-row[i].s;
        res=max(res,now_);
        curr_weight+=row[i].w;
    }
    cout<<res;
    return 0;
}