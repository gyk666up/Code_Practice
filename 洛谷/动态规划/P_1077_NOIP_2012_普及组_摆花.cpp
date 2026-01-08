//没思路
//不对
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e2+11;
// const int p=1e6+7;
// int dp[N][N];
// int n,m;
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)dp[i][0]=1;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=a[i];j++)
//         dp[i][j]=(dp[i][j],dp[i][j-a[i]]+1);
//     }
//     cout<<dp[n][m];
//     return 0;
// }


// //多重背包
// //dp[i][j] = 用前 i 种花，摆 j 盆的方案数
// #include<bits/stdc++.h>
// using namespace std;
// const int MOD = 1000007;
// const int N = 105;

// int n, m;
// int a[N];
// int dp[N][N];
// //dp[i][j]=k=0∑ai​​dp[i−1][j−k]
// /*dp[i][j] =
//     dp[i-1][j]           // 第 i 种花放 0 盆
//   + dp[i-1][j-1]         // 放 1 盆
//   + dp[i-1][j-2]         // 放 2 盆
//   + ...
//   + dp[i-1][j-a[i]]
// */
// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) cin >> a[i];

//     dp[0][0] = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= m; j++)
//         {
//             //两个限制：  1️⃣ 第 i 种花最多 a[i] 盆 2️⃣ 总共才 j 盆，不能超
//             for (int k = 0; k <= a[i] && k <= j; k++)
//             {
//                 dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
//             }
//         }
//     }

//     cout << dp[n][m];
//     return 0;
// }



