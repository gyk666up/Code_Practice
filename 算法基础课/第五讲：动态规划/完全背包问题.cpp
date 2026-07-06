// #include<bits/stdc++.h>
// using namespace std;
// const int N=1002;
// int dp[N][N];//dp[i][j]:前 i 个背包中容量为 j 最大的价值
// int n,m;
// int v[N],w[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>v[i]>>w[i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             dp[i][j]=dp[i-1][j];
//             if(j>=v[i])
//             dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+w[i]);//注意这里的 dp[i][j-v[i]]+w[i]
//             //好好理解一下这段代码
//         }
//     }
//     cout<<dp[n][m];
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
int dp[N][N];//表示在只允许从前 i 种物品中选择，且背包容量为 j 的限制下，所能获取的最大总价值。
int v[N],w[N];
int n,m;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=v[i])
            dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    }
    cout<<dp[n][m];
    return 0;
}