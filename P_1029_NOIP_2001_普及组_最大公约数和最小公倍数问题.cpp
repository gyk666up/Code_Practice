//没思路🤔😑

//方法一 使用自带的函数__gcd()最大公因数
//该题的关键点在于，两个数的积等于它们最大公约数和它们最小公倍数的积。
//公式表示为 a×b=gcd(a,b)×lcm(a,b)

#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int x,y;cin>>x>>y;
    if(x==y)ans--;
    y*=x;
    for(int i=1;i<=sqrt(y);i++)
    {
        if(y%i==0&&__gcd(i,y/i)==x)ans+=2;//交换顺序也可以 因此是两种
    }
    cout<<ans;
    return 0;
}


// //方法2 与方法一一样只是手写gcd函数
// //有一个这样的定律gcd(a,b)=gcd(b,a%b)
// inline int gcd(int x,int y)
// {
//     if(y==0)return x;
//     return gcd(y,x%y);
// }