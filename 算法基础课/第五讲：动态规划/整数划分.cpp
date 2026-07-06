//$dp[j]$：表示总和为 $j$ 的所有划分方案的数量。
// #include<bits/stdc++.h>
// using namespace std;

// const int MOD = 1e9 + 7;
// const int N = 1005;
// int dp[N];

// int main() 
// {
//     // 优化输入输出
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
//     int n;
//     if (!(cin >> n)) return 0;
    
//     // 初始化边界
//     dp[0] = 1; 
    
//     // 完全背包模板：外层遍历物品（数字 1 到 n）
//     for (int i = 1; i <= n; i++) 
//     {
//         // 内层正序遍历容量，实现无限次拿取
//         for (int j = i; j <= n; j++) 
//         {
//             dp[j] = (dp[j] + dp[j - i]) % MOD;
//         }
//     }
    
//     cout << dp[n] << "\n";
    
//     return 0;
// }



// //方法 2：选择 A：我绝对不用数字 $i$，选择 B：我决定至少用一个数字 i
// // f[i][j] = f[i - 1][j] + f[i][j - i]
// #include <iostream>

// using namespace std;

// const int N = 1e3 + 7, mod = 1e9 + 7;

// int f[N][N];

// int main() {
//     int n;
//     cin >> n;

//     for (int i = 0; i <= n; i ++) {
//         f[i][0] = 1; // 容量为0时，前 i 个物品全不选也是一种方案
//     }

//     for (int i = 1; i <= n; i ++) {
//         for (int j = 0; j <= n; j ++) {
//             f[i][j] = f[i - 1][j] % mod; // 特殊 f[0][0] = 1
//             if (j >= i) f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;
//         }
//     }

//     cout << f[n][n] << endl;
// }


//本质到底用不用i 这个数字
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e3+11;
// const int p=1e9+7;
// int dp[N];
// int n;
// //看出完全背包 dp[j]:凑j的方案数 
// //价值和体
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     dp[0]=1;
//     for(int i=1;i<=n;i++)//变量物品
//     {
//         //for(int j=i;j>=1;j--)
//         for(int j=i;j<=n;j++)//容量
//         {
//             dp[j]=(dp[j]+dp[j-i])%p;
//         }
//     }
//     cout<<dp[n];
//     return 0;
// }




