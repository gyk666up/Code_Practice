// #include<bits/stdc++.h>
// using namespace std;
// const int N=502;
// int dp[N][N];
// int a[N][N];
// //倒序
// //dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j]
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=i;j++)cin>>a[i][j];
//     }
//     for(int i=n;i>=1;i--)
//     {
//         for(int j=1;j<=i;j++)
//         {
//             dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
//         }
//     }
//     cout<<dp[1][1];
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
int a[N][N],dp[N][N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)cin>>a[i][j];
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i+1][j]+a[i][j],dp[i+1][j+1]+a[i][j]);
        }
    }
    cout<<dp[1][1];
    return 0;
}