// #include<bits/stdc++.h>
// using namespace std;

// const int N = 1005;
// int dp[N][N];//$dp[i][j]$：表示将 $A$ 的前 i 个字符，经过最少操作转换为 $B$ 的前 j 个字符，所需要的最少操作次数。

// int main() 
// {
//     // 优化输入输出
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
//     int n, m;
//     string a, b;
    
//     cin >> n >> a;
//     cin >> m >> b;
    
//     // 在字符串前面加上一个占位符，让有效下标从 1 开始
//     a = " " + a;
//     b = " " + b;
    
//     // 初始化边界
//     for(int i = 0; i <= n; i++) dp[i][0] = i;
//     for(int j = 0; j <= m; j++) dp[0][j] = j;
    
//     // 动态规划状态转移
//     for(int i = 1; i <= n; i++) 
//     {
//         for(int j = 1; j <= m; j++) 
//         {
//             if(a[i] == b[j]) 
//             {
//                 dp[i][j] = dp[i-1][j-1];
//             } 
//             else 
//             {                   //插入  删去    替换
//                 dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
//             }
//         }
//     }
    
//     cout << dp[n][m] << "\n";
    
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m;
// const int N=1002;
// int dp[N][N];
// string a,b;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>a;
//     cin>>m>>b;
//     a=" "+a;
//     b=" "+b;
//     for(int i=0;i<=m;i++)dp[0][i]=i;//只能插入
//     for(int i=0;i<=n;i++)dp[i][0]=i;//只能删去
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             if(a[i]==b[j])
//             {
//                 dp[i][j]=dp[i-1][j-1];
//             }
//             else
//             {           //插入 删去  替换
//                 dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
//             }
//         }
//     }
//     cout<<dp[n][m]<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000;
int n,m;
string a,b;
int dp[N][N];//dp[i][j]:前 i，j 个字符匹配最少需要多少个操作
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>a;
    cin>>m>>b;
    a=" "+a;
    b=" "+b;
    for(int i=1;i<=n;i++)dp[i][0]=i;//删除
    for(int i=1;i<=m;i++)dp[0][i]=i;//插入

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])dp[i][j]=dp[i-1][j-1];
            else
            {                   //删去   插入  替换
                dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}