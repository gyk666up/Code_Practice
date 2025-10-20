// //还是不熟
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e3+66;
// struct node
// {
//     int t,d,p;
//     //截止时间在前的优先选择
//     bool operator<(const node &u)
//     {
//         return d<u.d;
//     }
// }dat[N];
// int dp[N][N];
// void solve()
// {
//     memset(dp,0,sizeof dp);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>dat[i].t>>dat[i].d>>dat[i].p;
//     }
//     sort(dat+1,dat+1+n);
//     for(int i=1;i<=n;i++)
//     {
//        for(int j=0;j<=dat[i].d;j++) {
//         if(j < dat[i].t) {
//         dp[i][j] = dp[i-1][j];  // 时间不足，无法选择当前任务
//            } else {
//         dp[i][j] = max(dp[i-1][j], dp[i-1][j-dat[i].t] + dat[i].p);
//     }
// }
//     }
//     int res=-1;
//     for(int i=1;i<=n;i++)
//     {               //是<=!!!
//         for(int j=0;j<=dat[i].d;j++)
//         res=max(res,dp[i][j]);
//     }
//     cout<<res<<endl;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--)solve();
//     return 0;
// }



//二维dp便于理解 一维dp适合大规模数据

#include<bits/stdc++.h>
using namespace std;
const int N=5e3+66;
int f[N];
struct node
{
    int t,d,p;
    //截止时间在前的优先选择
    bool operator<(const node &u)
    {
        return d<u.d;
    }
}dat[N];
void solve()
{
    memset(f,0,sizeof f);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>dat[i].t>>dat[i].d>>dat[i].p;
    sort(dat+1,dat+1+n);
    for(int i=1;i<=n;i++)
    {
       // 逆序遍历避免重复选择同一任务（类似 0-1 背包问题）
       //理解背后的原理
        for(int j=dat[i].d;j>=dat[i].t;j--)
        f[j]=max(f[j],f[j-dat[i].t]+dat[i].p);
    }
    int res=0;
    for(int i=1;i<=5000;i++)
    {
        res=max(f[i],res);
    }
    cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}


















