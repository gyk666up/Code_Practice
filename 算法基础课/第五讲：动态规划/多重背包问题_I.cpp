// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int n,v;
// // const int N=102;
// // int dp[N][N][N];
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)cin>>v[i]>>w[i]>>s[i];

// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=0;j<=s[i];j++)
// //         {
// //             for(int k=0;k<=m;k++)
// //             {
// //                 //当前是第i个物品 v[i],w[i],s[i]
// //                 dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k-m[i]]+w[i]);
// //             }
// //         }
// //     }
// //     cout<<dp[n][v];
// //     return 0;
// // }


// //不会

// //本质上就是 01 背后问题，只不过选法变多了 之前只有选和不选现在可以选 0 1，。。。s 共 s+1 种选法
// //一维
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int n,m;
// // const int N=102;
// // int v[N],w[N],s[N];
// // int dp[N];
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)
// //     {
// //         cin>>v[i]>>w[i]>>s[i];
// //     }

// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=m;j>=v[i];j--)
// //         {
// //             for(int k=1;k<=s[i]&&k*v[i]<=j;k++)
// //             {
// //                 dp[j]=max(dp[j],dp[j-k*v[i]]+k*w[i]);
// //             }
// //         }
// //     }
// //     cout<<dp[m];
// //     return 0;
// // }

// //二维
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// const int N = 105; 
// const int MAX_M = 100005; 

// int n, m;
// int v[N], w[N], s[N];

// // 二维数组需要开 [物品种类数量][背包最大容量]
// int dp[N][MAX_M]; 

// signed main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     cin >> n >> m;
    
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> v[i] >> w[i] >> s[i];
//     }

//     // 开始动态规划
//     for(int i = 1; i <= n; i++) // 第一层：遍历前 i 个物品
//     {
//         for(int j = 0; j <= m; j++) // 第二层：遍历背包容量 j
//         {
//             // 【关键点 1】：先把不选当前物品（即选 0 个）的最优解抄过来作为保底
//             dp[i][j] = dp[i-1][j]; 
            
//             // 第三层：尝试选 1 个、2 个...直到上限 s[i] 个
//             for(int k = 1; k <= s[i] && k * v[i] <= j; k++) 
//             {
//                 // 【关键点 2】：注意这里用的是 dp[i-1]，保证是在还没拿过第 i 个物品的状态上进行添加
//                 dp[i][j] = max(dp[i][j], dp[i-1][j - k * v[i]] + k * w[i]);
//             }
//         }
//     }
    
//     cout << dp[n][m];
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=102;
// int n,V;
// int v[N],w[N],s[N];
// int dp[100*N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>V;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>v[i]>>w[i]>>s[i];
//     }

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=V;j>=v[i];j--)
//         {
//             for(int k=1;k<=s[i]&&k*v[i]<=j;k++)
//             {
//                 dp[j]=max(dp[j],dp[j-k*v[i]]+k*w[i]);
//             }
//         }
//     }
//     cout<<dp[V]<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
int v[N],w[N],s[N];
int n,m;
int dp[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i]>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
                for(int k=1;k<=s[i]&&k*v[i]<=j;k++)
                {
                    dp[j]=max(dp[j],dp[j-k*v[i]]+k*w[i]);
                }
        }
    }
    cout<<dp[m];
    return 0;
}