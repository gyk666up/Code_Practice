// //完全背包
// //看数据的范围是开不了二维的
// #include<bits/stdc++.h>
// using namespace std;
// int t,m;
// #define int long long
// const int N=1e7+11;
// int dp[N];//dp[j]前j时间内采到草药的最大值
// int a[N],b[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>t>>m;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>a[i]>>b[i];
//     }
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=0;j<=t;j++)
//         {
//             if(j>=a[i])
//             {
//                 dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
//             }
//         }
//     }
//     cout<<dp[t];
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+11;
int dp[N];
int t,m;
int w[N],v[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=t;j++)
        {
            if(j>=w[i])
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            
        }
    }
    cout<<dp[t];
    return 0;
}