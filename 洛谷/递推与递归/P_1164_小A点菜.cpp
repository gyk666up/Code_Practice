//暴力
// #include<bits/stdc++.h>
// using namespace std;
// int ans=0;
// const int N=1e3+11;
// int a[N];//菜的价钱
// int n,m;
// void dfs(int x,int cost)
// {
//     if(x>n)
//     {
//         if(cost==m)
//         {
//             ans++;
//         }
//         return;
//     }
//     //对于第x的菜 
//     //两种可能 1：选 2：不选
//     //选
//     //st[x]=1;
//     dfs(x+1,cost+a[x]);

//     //不选
//     //st[x]=0;
//     dfs(x+1,cost);
//     return;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     cin>>a[i];

//     dfs(1,0);
//     cout<<ans;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1e3+11;
// int a[N];
// int dp[N][N];
// //dp[i][j]表示: 前i道菜用光j元钱的办法总数
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             //前 i 个物品凑出 j 的方案数 = 前 i-1 个物品凑出 j 的方案数（不选第 i 个物品） 
//             //+ 1（单独选第 i 个物品，因为它的价值刚好是 j）。
//             if(j==a[i])dp[i][j]=dp[i-1][j]+1;
//             //预算充足 可吃可不吃
//             if(j>a[i])dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
//             if(j<a[i])dp[i][j]=dp[i-1][j];
//         }
//     }
//     cout<<dp[n][m];
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int a[200];
const int N=1e3+11;
int dp[200][N];//dp[i][j]第i中菜 还剩j元的方案数
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j==a[i])dp[i][j]=dp[i-1][j]+1;
            else if(j>a[i])dp[i][j]=dp[i-1][j-a[i]]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][m];
    return 0;
}