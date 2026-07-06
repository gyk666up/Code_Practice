// //为了让上升子序列尽可能地“长”，我们在向后接数字的时候，应该贪心地让这个序列末尾的数字尽可能地“小”。因为末尾数字越小，后面能接上新数字的概率就越大。
// //q[len] 表示：在所有长度为 len 的上升子序列中，末尾最小的那个数。

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() 
// {
//     // 优化输入输出流，应对大数据量
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     if (!(cin >> n)) return 0;

//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     // q 数组存储不同长度的上升子序列的最小末尾值
//     vector<int> q; 

//     for (int i = 0; i < n; ++i) {
//         int x = a[i];
        
//         // 使用二分查找，在 q 数组中寻找第一个 >= x 的位置
//         auto it = lower_bound(q.begin(), q.end(), x);
        
//         if (it == q.end()) {
//             // 如果没找到 >= x 的数，说明 x 比当前所有末尾值都大
//             // 可以直接加在末尾，使得最长上升子序列的长度 +1
//             q.push_back(x);
//         } else {
//             // 如果找到了，就把那个数替换成更小的 x
//             // 这一步操作不会改变当前最长子序列的长度，但会让末尾数字变小，更有潜力
//             *it = x;
//         }
//     }

//     // q 数组的最终长度，就是最长上升子序列的最大长度
//     cout << q.size() << "\n";

//     return 0;
// }

//跟之前的天梯赛有道题很像
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n;
// const int N=1e5+11;
// int a[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     vector<int>a(n);
//     for(int i=0;i<n;i++)cin>>a[i];
//     vector<int>q;//存不同长度的最长上升序列的末尾，越小潜力越大
//     for(int i=0;i<n;i++)
//     {
//         int x=a[i];
//         //找》=x 的第一个数字
//         auto it=lower_bound(q.begin(),q.end(),x);
//         if(it==q.end())
//         {
//             q.push_back(x);
//         }
//         else *it=x;
//     }
//     cout<<q.size();
//     return 0;
// }
// //如果你以后遇到题目要求求非严格递增子序列（即允许包含相等的元素，例如 1 2 2 3），你只需要把这段代码里的 lower_bound 替换成 upper_bound
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     vector<int>a(n+1);
//     for(int i=1;i<=n;i++)cin>>a[i];
//     vector<int>q;
//     for(int i=1;i<=n;i++)
//     {
//         int x=a[i];
//         auto it=lower_bound(q.begin(),q.end(),x);
//         if(it==q.end())q.push_back(x);
//         else *it=x;
//     }
//     cout<<q.size();
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int a[N];
int dp[N];
int n;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }    
    vector<int>q;//存对应长度的尾数字
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        auto it=lower_bound(q.begin(),q.end(),x);
        if(it==q.end())q.push_back(x);
        else *it=x;
    }
    cout<<q.size();
    return 0;
}