// //顺序怎么解决，还有就是怎样用暴力dfs
// #include<bits/stdc++.h>
// using namespace std;
// int n,w;
// const int p=1e9+7;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;

//     return 0;
// }


//dp[j]=凑出金额j的方案数
//👉 金额在外层循环，纸币在内层循环
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(w + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= w; j++) {
        for (int i = 0; i < n; i++) {
            if (j >= a[i]) {
                dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
            }
        }
    }

    cout << dp[w] << "\n";
    return 0;
}
