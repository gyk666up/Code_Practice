// //我靠 毫无思路！

// //NB
// //我们分析一下题目，既然想要让 n 个数除起来是整数，那么分母自然是越小越好， 
// //最优的情况除了a[2]其余都是分子
// //若最优情况能整除 → 存在对应的括号组合（如 \(a_1/((a_2/a_3)/a_4/\dots/a_n)\)），输出 Yes；
// //若最优情况不能整除 → 所有其他组合都不能整除，输出 No。
// //a1一定是分子 a2一定是分母 之后的元素既可以是分子也可以是分母
//  #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e4+22;
// int a[N];
// int n;
// //欧几里得辗转相除法
// int __gcd(int x,int y)
// {
//     if(y==0)return x;
//     return __gcd(y,x%y);
// }
// bool judge(int *a)
// {
//     for(int i=3;i<=n;i++)
//     {
//         a[2]/=__gcd(a[2],a[i]);
//     }
//     return a[2]==1;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--)
//     {
//         cin>>n;
//         for(int i=1;i<=n;i++)cin>>a[i];

//         a[2]/=__gcd(a[1],a[2]);
//         if(judge(a))cout<<"Yes\n";
//         else cout<<"No\n";

//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e4+11;
// int a[N];
// int n;
// int __gcd(int x,int y)
// {
//     if(y==0)return x;
//     return __gcd(y,x%y);
// }
// bool judge(int a[])
// {
//     for(int i=3;i<=n;i++)
//     {
//         a[2]/=__gcd(a[2],a[i]);
//         //if(a[2]==1)return 1; 写在这里会导致一个点输出错误！！！
//         //为什么呢
//     }
//     if(a[2]==1)return 1;
//     return 0;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--)
//     {
//         cin>>n;
//         for(int i=1;i<=n;i++)cin>>a[i];

//         a[2]/=__gcd(a[1],a[2]);
//         if(judge(a))cout<<"Yes\n";
//         else cout<<"No\n";
//     }
//     return 0;
// }








#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e4+11;
int a[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        bool flg=0;
        for(int i=1;i<=n;i++)
        {
            if(i==2)continue;
            a[2]/=__gcd(a[2],a[i]);
            if(a[2]==1)
            {
                flg=1;
                break;
            }
        }
        if(flg)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}