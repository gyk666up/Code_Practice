// //纯纯数学题 高中讲的组合排列 不耽误我不会🥶
// //n个球分成r份 然后Arr

// #include <bits/stdc++.h>
// using namespace std;

// //S[n][r]把 n 个不同元素分成 r 个非空、无序集合的方案数
// int main() {
//     int n, r;
//     cin >> n >> r;

//     static int S[11][11] = {0};
//     S[0][0] = 1;

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= i; j++) {
//             S[i][j] = S[i-1][j-1] + j * S[i-1][j];
//         }
//     }

//     int fact = 1;
//     for (int i = 1; i <= r; i++) fact *= i;

//     cout << S[n][r] * fact << endl;
//     return 0;
// }


// //另一种写法
// #include <stdio.h>
// #include <iostream>
// #define ll long long
// using namespace std;

// ll f(int n, int m)
// {
//     if (m <= 0 || n < m)
//         return 0;
//     if (n == m)
//         return 1;
//     else
//         return fun(n-1, m-1) + fun(n-1, m) * m;
// }

// ll fac(int i) // 然而这个函数不用讲什么
// {
//     if (i == 1)
//         return 1;
//     else
//         return i * fac(i - 1);
// }

// int main() // 完美主程序
// {
//     ll n, m;
//     cin >> n >> m;
//     cout<< f(n, m) * fac(m);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=30;
// int S[N][N];//n个球放到r个不同的盒子的方案数量
// int n,r;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>r;
//     S[0][0]=1;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=r;j++)
//         //S[i][j]i个球放到j个盒子中的方案数量
//         //对于第n个球来说 自己可能单独占一个盒子也可能在j个盒子中选一个
//         S[i][j]=S[i-1][j-1]+S[i-1][j]*j;
//     }
//     int fi=1;
//     for(int i=1;i<=r;i++)
//     {
//         fi*=i;
//     }
//     cout<<S[n][r]*fi;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n,r;
const int N=30;
int S[N][N];//s[i][j] n个球放到r个盒子里的情况数
//对于第n个球来说 可以自己单独占最后一个盒子，也可以从前面的r-1个盒子中选一个
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>r;
    int fib=1;
    for(int i=1;i<=r;i++)
    {
        fib*=i;
    }
    S[0][0]=1;
    //答案是S[n][r]*r!
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=r;j++)
        S[i][j]=S[i-1][j-1]+S[i-1][j]*j;
    }
    cout<<S[n][r]*fib;
    return 0;
}