// //“失败有收益”的题 =
// //先拿保底 → 再做背包选增量
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, x;
//     cin >> n >> x;

//     vector<long long> dp(x + 1, 0);
//     long long base = 0;

//     for (int i = 1; i <= n; i++) {
//         long long lose, win;
//         int use;
//         cin >> lose >> win >> use;

//         base += lose;  // 保底经验

//         long long val = win - lose;  // 额外收益
//         if (use > x) continue;

//         // 0/1 背包
//         for (int j = x; j >= use; j--) {
//             dp[j] = max(dp[j], dp[j - use] + val);
//         }
//     }

//     long long extra = 0;
//     for (int j = 0; j <= x; j++)
//         extra = max(extra, dp[j]);

//     cout << (base + extra) * 5 << "\n";
//     return 0;
// }


// // 当i>=use时，可以选择打败或者不打败

// // dp[i]=max(dp[i]+lose,dp[i-use]+win)。

// // 当i<use时，无法战胜对方。

// // dp[i]+=lose
// //真没看出来是01背包
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,x;
// const int N=1e3+66;
// int lose[N],win[N],use[N];
// int dp[N];//dp[i] dp[i]表示用i瓶药获得的最多经验。
// //int dp[N][N];//二维
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>x;
//     for(int i=1;i<=n;i++)cin>>lose[i]>>win[i]>>use[i];
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=x;j>=use[i];j--)
//         {
//             dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
//         }
//         for(int j=use[i]-1;j>=0;j--)
//         {
//             dp[j]+=lose[i];
//         }
//     }
//     cout<<5ll*dp[x];
//     // for(int i=1;i<=n;i++)
//     // {
//     //     for(int j=0;j<=x;j++)
//     //     {
//     //         if(j>=use[i])
//     //         dp[i][j]=max(dp[i-1][j]+lose[i],dp[i-1][j-use[i]]+win[i]);
//     //         else
//     //         dp[i][j]+=lose[i];
//     //     }
//     // }
//     // cout<<5*dp[n][x];
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
const int N=1e3+66;
#define int long long 
int n,x;
int lose[N],win[N],use[N];
int dp[N];//用药量不超过i的可以获得的最大经验
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>lose[i]>>win[i]>>use[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=x;j>=0;j--)
        {
            if(j>=use[i])//这里容易写错 dp[j]=max(dp[j],dp[j-use[i]]+win[i])
            dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
            else
            dp[j]+=lose[i];
        }
    }
    cout<<5ll*dp[x];
    return 0;
}