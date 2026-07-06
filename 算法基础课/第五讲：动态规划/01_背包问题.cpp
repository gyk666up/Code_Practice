// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1002;
// int v[N],w[N];
// int n,V;
// int dp[N];//dp[i]:体积为 i 的时候价值为
// //int dp[N][N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>V;
//     for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=V;j>=0;j--)
//         {
//             if(j>=v[i])dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
//             // dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
//             // else dp[i][j]=dp[i-1][j];//对于二维的话，这个别忘记
//         }
//     }
//     cout<<dp[V];
//     //cout<<dp[n][V];
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
int dp[N];
int v[N],w[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            if(j>=v[i])
            {
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        }
    }
    cout<<dp[m];
    return 0;
}