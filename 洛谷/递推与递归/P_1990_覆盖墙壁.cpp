// //不知道该如何去考虑或者是表示一个L型的砖

// //!!!不是很理解 状态转移方程
// #include<bits/stdc++.h>
// using namespace std;
// const int mod=10000;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     if(n==0){cout<<1<<endl;return 0;}
//     else if(n==1){cout<<1<<endl;return 0;}
//     else if(n==2){cout<<2<<endl;return 0;}

//     int dp0=1;
//     int dp1=1;
//     int dp2=2;//dp[2]

//     int s0=1;
//     int s1=2;//s[1]=s[0]+dp[1]
//     int s2=4;//s[2]=s[1]+dp[2]

//     //从3递推到n
//     for(int i=3;i<=n;i++)
//     {
//         //dp[i]=dp[i-1]+dp[i-2]+2*s[i-3]
//         int dp_i=(dp2+dp1+2*s0)%mod;

//         //s[i]=s[i-1]+dp[i]
//         int s_i=(s2+dp_i)%mod;

//         //更新变量 滚动存储
//         dp0=dp1;
//         dp1=dp2;
//         dp2=dp_i;

//         s0=s1;
//         s1=s2;
//         s2=s_i;
//     }
//     cout<<dp2%mod<<endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
int dp[N];//dp[i]:长度为i的方案数
int s[N];//dp的前缀和
const int p=1e4;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    if(n==0)
    {
        cout<<1<<endl;//只有什么也不放这一种方案
        return 0;
    }
    else if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    else if(n==2)
    {
        cout<<2<<endl;
        return 0;
    }
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    s[0]=1;
    s[1]=2;
    s[2]=4;

    //因为L性是2*3 所有从3开始枚举
    //这个状态转移方程是难点！！！
    for(int i=3;i<=n;i++)
    {
        //各种方案之间是互斥的
        dp[i]=dp[i-1]%p+dp[i-2]%p+2*s[i-3]%p;
        s[i]=s[i-1]%p+dp[i]%p;
    }
    cout<<dp[n]%p<<endl;

    return 0;
}