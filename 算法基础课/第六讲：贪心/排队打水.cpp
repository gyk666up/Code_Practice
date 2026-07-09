#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int t[N];
int n;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>t[i];
    sort(t+1,t+1+n);
    int ans=0;//第i个人需要等待的时间
    int sum=0;//全部时间
    // for(int i=1;i<=n;i++)
    // {
    //     ans+=(t[i])*(n-i);//需要有 n-1个第一个等待时间
    // }
    // cout<< ans;

    for(int i=1;i<=n;i++)
    {
        sum+=ans;
        ans+=t[i];
    }
    cout<<sum;
    return 0;
}