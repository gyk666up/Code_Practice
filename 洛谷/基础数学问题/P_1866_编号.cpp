// //这不就是数学上的乘法原理吗
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n;
// const int p=1e9+7;
// const int N=100;
// int a[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     sort(a+1,a+1+n);
//     int sum=1;
//     //已经选过的数就不可以再选了?这个怎么解决 用sort

//     //第一个a【1】种 第二个a[2]-1种
//     for(int i=1;i<=n;i++)
//     {
//         ////这一行是错误的 原因是在于运算顺序 sum*=(a[i]-(i-1))%p;
//         sum*=(a[i]-(i-1));
//         sum%=p;
//     }
//     cout<<sum%p;
//     return 0;
// }






// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=60;
// int a[N];
// int ans=0;
// const int p=1e9+7;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=0;i<n;i++)cin>>a[i];
//     sort(a,a+n);//这行代码很细节
//     int sum=1;
//     for(int i=0;i<n;i++)
//     {
//         sum*=(a[i]-i);
//         sum%=p;
//     }
//     cout<<sum;
//     return 0;
// }


//没什么大问题 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=52;
int a[N];
const int p=1e9+7;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);//这个是关键
    int res=1;
    for(int i=1;i<=n;i++)
    {
        res*=a[i]-i+1;
        res%=p;
    }
    cout<<res;
    return 0;
}