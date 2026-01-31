// 以第 i 个元素结尾的最大子段和，要么：
// 把前面的子段接上
// 要么从自己重新开始
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=2e5+11;
int ans=-0x3f3f3f3f;//注意这个初始化啊
int dp[N];//dp[i] = 以 a[i] 结尾的最大连续子段和
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(dp[i-1]<0)dp[i]=a[i];
        else dp[i]=dp[i-1]+a[i];
        ans=max(dp[i],ans);
    }
    cout<<ans;
    //cout<<dp[n];错误的
    return 0;
}