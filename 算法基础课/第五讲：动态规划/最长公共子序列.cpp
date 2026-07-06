// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int n,m;
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     return 0;
// // }


// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// const int MAXN = 1005;
// int dp[MAXN][MAXN];

// int main() 
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m;
//     if (!(cin >> n >> m)) return 0;

//     string A, B;
//     cin >> A >> B;

//     // 【核心技巧】：在开头拼接一个空字符，使有效下标从 1 开始
//     // 这样在计算 dp[i-1][j-1] 时，就算 i=1，i-1 也是 0，直接对应默认的 0，不会越界！
//     A = " " + A; 
//     B = " " + B;

//     // 外层遍历字符串 A 的每个字符
//     for (int i = 1; i <= n; i++) 
//     {
//         // 内层遍历字符串 B 的每个字符
//         for (int j = 1; j <= m; j++) 
//         {
//             if (A[i] == B[j]) 
//             {
//                 // 如果字符相等，直接继承左上角的值并 +1
//                 dp[i][j] = dp[i-1][j-1] + 1;
//             } 
//             else 
//             {
//                 // 如果不等，取左边（删掉 B[j]）和上边（删掉 A[i]）的最大值
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//     }

//     // 最终的答案就存储在矩阵的最右下角
//     cout << dp[n][m] << "\n";

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
int dp[N][N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    string a,b;cin>>a>>b;
    a=" "+a;
    b=" "+b;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}