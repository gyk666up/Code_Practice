//这道题重点理解

//这道题的数学背景并没有理解

//每一年还的钱转换到开始的钱 每年钱的和为w0
//这是一开始自己写的
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int w0,w,m;
// bool check(double x)
// {
//     double ans=w0+w*m;//总共要还的钱
//     double a=ans/w0;
//     if(pow(1+x,m)<=a)return true;
//     else return false;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>w0>>w>>m;
//     //应该枚举利率
//     double l=0,r=3.01;
//     while(r-l>1e-4)
//     {
//         double mid=(l+r)/2;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     cout<<fixed<<setprecision(1)<<100*l<<endl;
//     return 0;
// }



// 贷款的本质是，银行借给你一笔钱，你每月还固定金额，直到还清。月利率是银行每月收取的利息率。假设月利率为r（例如，r=0.01表示1%），那么每月还款的现值之和应该等于贷款原值。

// 现值的意思是，未来的钱在今天的价值。因为有利息，所以未来的钱不如现在的钱值钱。例如，如果你下个月还100元，那么这100元在今天的价值是100/(1+r)元。
//将每一年的现值转换成第一年的钱等于贷款金额w0

//贷款利息越大 现值就越小
//3 |2 2 1
//2 3 4 5
//w/(1+r)^i
#include<bits/stdc++.h>
using namespace std;
#define int long long
double w0,w,m;
bool check(double x)
{
    double ans=w/x*(1-1/(pow(1+x,m)));
    if(ans>=w0)return true;
    else return  false;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>w0>>w>>m;
    double l=0,r=3.1;

    //两种方式
    // for(int i=0;i<=100;i++)
    // {
    //     double mid=(l+r)/2;
    //     if(check(mid))l=mid;
    //     else r=mid;
    //     if(r-l<1e-8)
    //     {
    //         break;
    //     }
    // }
    while(r-l>1e-8)
    {
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }

    cout<<fixed<<setprecision(1)<<100*l<<endl;

    return 0;
}