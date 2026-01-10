// //要始终牢记正难则反的原则
// // 先求U，ans1=M^N
// // 再求B，那么若第一个罪犯有M种宗教可能，那么第二个罪犯如果不能满足越狱条件则必须和第一个宗教不同，
// //就只有（M-1）种，那么第3~N个罪犯也一样，都有（M-1）种情况

// #include <bits/stdc++.h>
// using namespace std;
// using int64 = long long;

// const int MOD = 100003;

// int64 qpow(int64 a, int64 b) {
//     //xmod1=0 更严谨一点
//     int64 res = 1 % MOD;
//     a %= MOD;
//     while (b) {//b & 1：判断 b 是否为奇数,如果当前二进制位是 1,就把当前的 a 乘进答案
//         if (b & 1) res = res * a % MOD;
//         a = a * a % MOD;//每一轮都 平方一次
//         b >>= 1;//b 右移一位
//     }
//     return res;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int64 m, n;
//     cin >> m >> n;

//     if (n == 1) {
//         // 只有一个房间，不可能发生越狱
//         cout << 0 << '\n';
//         return 0;
//     }

//     int64 total = qpow(m, n);
//     int64 safe = m % MOD * qpow(m - 1, n - 1) % MOD;

//     int64 ans = (total - safe) % MOD;
//     if (ans < 0) ans += MOD;

//     cout << ans << '\n';
//     return 0;
// }

// //在 C++ 中，% 可能得到负数，这两行是为了把结果修正回合法的模意义下的非负值 [0, MOD-1]。
// //-2 % 5 == -2   ❌（不是 3）结果和被除数的符号保持一致
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int m,n;
// const int mod=100003;
// int qmi(int a,int b)
// {
//     int res=1%mod;
//     while(b)
//     {
//         if(b&1)//取最低位
//         res=res*a%mod;

//         a=a*a%mod;
//         b>>=1;
//     }
//     return res;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>m>>n;
//     if(n==1)
//     {
//         cout<<0;
//         return 0;
//     }
//     int all=qmi(m,n)%mod;
//     int safe=m%mod*qmi(m-1,n-1)%mod;
//     int ans=(all-safe)%mod;

//     if(ans<0)ans+=mod;//！！！
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int p=100003;
int qmi(int a,int b)
{
    int res=1%p;
    while(b)
    {
        if(b&1)
        {
            res=res*a%p;
        }
        //注意这两行代码的位置
        a=a*a%p;
        b>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m>>n;
    if(n==1)
    {
        cout<<"0";
        return 0;
    }
    int all=qmi(m,n)%p;
    int safe=m%p*qmi(m-1,n-1)%p;
    int ans=(all-safe)%p;
    if(ans<0)ans+=p;
    cout<<ans;
    return 0;
}