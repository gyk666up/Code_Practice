// //没思路🤔😑

// //方法一 使用自带的函数__gcd()最大公因数
// //该题的关键点在于，两个数的积等于它们最大公约数和它们最小公倍数的积。
// //公式表示为 a×b=gcd(a,b)×lcm(a,b)

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int ans=0;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int x,y;cin>>x>>y;
// 这行代码不太容易理解 最下面的那行代码好理解
//     if(x==y)ans--;
//     y*=x;
//     for(int i=1;i<=sqrt(y);i++)
//     {
//         if(y%i==0&&__gcd(i,y/i)==x)ans+=2;//交换顺序也可以 因此是两种
//     }
//     cout<<ans;
//     return 0;
// }


// // //方法2 与方法一一样只是手写gcd函数
// // //有一个这样的定律gcd(a,b)=gcd(b,a%b)
// // inline int gcd(int x,int y)
// // {
// //     if(y==0)return x;
// //     return gcd(y,x%y);
// // }


// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int x,y;cin>>x>>y;
//     y*=x;
//     int ans=0;
//     for(int i=1;i<=sqrt(y);i++)
//     {
//         if(y%i==0&&__gcd(y/i,i)==x)
//         {
//             if(y/i!=i)ans+=2;
//             else ans+=1;
//         }
//     }
//     cout<<ans;
//     return 0;
// }



//这道题掌握的不太好
//有个结论 x*y==最大公约数*最小公倍数
#include<bits/stdc++.h>
using namespace std;
int p,q;
int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cin.tie(0);
    int x,y;cin>>x>>y;
    y*=x;
    int ans=0;
    for(int i=1;i<=sqrt(y);i++)
    {
        //p=i，q=y/i 可以交换，所以是两种情况
        //枚举所有可能的 (P, Q) 乘积组合。
        if(y%i==0&&__gcd(y/i,i)==x)//C++函数库里面有这个__gcd函数
        {
            if(y/i!=i)ans+=2;
            else ans++;
        }
    }
    cout<<ans;
    
    return 0;
}