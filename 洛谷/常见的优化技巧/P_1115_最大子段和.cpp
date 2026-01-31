#include<bits/stdc++.h>
using namespace std;
const int N=2e5+66;
#define int long long
int a[N];
int n;
int dp[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=-0x3f3f3f3f;//最大子段和有可能是负数 初始化为负无穷
    for(int i=1;i<=n;i++)
    {
        if(dp[i-1]<0)dp[i]=a[i];//只有前面的最大和为负数 就是个累赘 就不要了
        else dp[i]=dp[i-1]+a[i];

        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}