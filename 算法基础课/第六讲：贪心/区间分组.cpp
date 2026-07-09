// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     return 0;
// }

//

//这个方法不太好理解
// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 100100;

// int n;
// int b[2 * N], idx;

// int main()
// {
//     scanf ("%d", &n);
//     for(int i = 0; i < n; i ++)
//     {
//         int l, r;
//         scanf("%d %d", &l, &r);
//         b[idx ++] = l * 2;//标记左端点为偶数。
//         b[idx ++] = r * 2 + 1;// 标记右端点为奇数。
//     }

//     sort(b, b + idx);

//     int res = 1, t = 0;
//     for(int i = 0; i < idx; i ++)
//     {
//         if(b[i] % 2 == 0) t ++;
//         else t --;
//         res = max(res, t);
//     }
//     printf ("%d\n", res);
//     return 0;
// }

//思路没问题，但是：差分数组的下标代表的是真实坐标，而不是第几个区间。你的循环终点应该是“所有区间中最大的那个坐标”，而不是“区间的个数”。
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int diff[N];
// int a[N];
// int n;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int l,r;cin>>l>>r;
//         diff[l]++;
//         diff[r+1]--;
//     }
//     int res=0;
//     for(int i=1;i<=n;i++)
//     {
//         a[i]=a[i-1]+diff[i];
//         res=max(res,a[i]);
//     }
//     cout<<res;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// int n;
// map<int, int> diff; // 用 map 替代普通数组

// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin >> n;
    
//     // 1. 构建差分
//     for(int i = 1; i <= n; i++)
//     {
//         int l, r;
//         cin >> l >> r;
//         diff[l]++;      // 进入区间，重叠度 +1
//         diff[r + 1]--;  // 离开区间（闭区间所以是 r+1），重叠度 -1
//     }
    
//     int res = 0;
//     int current_overlap = 0; // 相当于你代码里的 a[i]
    
//     // 2. 遍历 map 计算前缀和
//     // map 会自动按照坐标（pos）从小到大遍历
//     for(auto& [pos, val] : diff) 
//     {
//         current_overlap += val; //理解这个对差分求和 本质上和 a[i]=a[i-1]+diff[i]是一样的
//         res = max(res, current_overlap);
//     }
    
//     cout << res << "\n";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>diff;
int n;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    //注意允许区间负数存在
    for(int i=0;i<n;i++)
    {
        int l,r;cin>>l>>r;
        diff[l]++;
        diff[r+1]--;
    }
    int current=0;
    int res=0;
    for(auto [l,t]:diff)
    {
        current+=t;
        res=max(res,current);
    }
    cout<<res;
    return 0;
}