// #include<bits/stdc++.h>
// using namespace std;
// const int N=5000;
// long long dp[N];
// //这样会溢出  用到高精度的知识 如果不会高精度 可以用python来写
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     dp[0]=1;
//     dp[1]=1;
//     int n;cin>>n;
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     cout<<dp[n];
//     return 0;
// }

//python代码
n=int(input())
f = [0 for i in range(0,n+10,1)] 
f[0]=1
f[1]=1
//陷阱
if(n==0):
    print(0)
else:
    for i in range(2,n+1,1):
        f[i]=f[i-1]+f[i-2]
    print(f[n])