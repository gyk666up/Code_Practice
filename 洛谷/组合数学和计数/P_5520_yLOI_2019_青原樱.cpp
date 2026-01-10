//n个位置  m个幼苗 m-1个空 还有（n-m+1）个位置
//是A(n-m+1,m) 是n-m+1的往前推有m项 不是从m开始 但代码写的又问题 排列组合公式记得有问题
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int t,n,m,p;
// int ans=1;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>t>>n>>m>>p;
//     for(int i=m;i<=n-m+1;i++)
//     {
//         ans=(ans*i)%p;
//     }
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
//C(n-m+1,m)*m! 等价写成A(n-m+1,m) 但这两公式不要搞混
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int type, n, m, p;
    cin >> type >> n >> m >> p;

    int ans = 1;
    for (int i = n - 2*m + 2; i <= n - m + 1; i++) {
        ans = ans * (i % p) % p;
    }

    cout << ans;
    return 0;
}
