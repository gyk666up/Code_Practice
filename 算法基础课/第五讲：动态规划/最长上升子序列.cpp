// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e3+11;
// int a[N];
// int dp[N];//dp[i]:以 i 为终点的最长上升子序列
// int n;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)dp[i]=1;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=i+1;j<=n;j++)
//         {
//             if(a[j]>a[i])
//             {
//                 dp[j]=max(dp[j],dp[i]+1);
//             }
//         }
//     }
//     int max_=0;
//     for(int i=1;i<=n;i++)max_=max(max_,dp[i]);
//     cout<<max_;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
int dp[N];//dp[i]:以第i 个数字结尾的最长序列
int n;
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[i]>a[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int max_=-0x3f3f3f3f;
    for(int i=1;i<=n;i++)max_=max(dp[i],max_);
    cout<<max_;
    

}