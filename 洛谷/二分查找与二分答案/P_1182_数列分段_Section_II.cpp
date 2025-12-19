// //这道题没思路

// //思路：先不考虑分段的次数的 从最小的和枚举到最大的和 看哪个和满足指定分段次数m相等

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m;
// const int N=1e5+11;
// int a[N];
// //段数 3 |2  2  1
// //和 10 20 30 40
// bool check(int x)
// {
//     //因为至少有一段 这个total=1很容易错
//     int sum=0,total=1;//每段的和  段数
//     for(int i=1;i<=n;i++)
//     {
//         //枚举每一个数
//         if(sum+a[i]<=x)sum+=a[i];
//         else 
//         {
//             sum=a[i];
//             total++;
//         }
//     }
//     if(total>m)return true;
//     else return false;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     int l=0,r=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         l=max(l,a[i]);
//         r+=a[i];
//     }
//     //注意这里 l和r要在区域的两端 且两端不可以是可行点
//     l--,r++;
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     cout<<r;
//     return 0;
    
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=1e5+11;
int a[N];
bool check(int x)
{
    int cnt=1,sum=0;//段数至少为1 
    for(int i=1;i<=n;i++)
    {
        if(sum+a[i]<=x)
        {
            sum+=a[i];
        }
        else
        {
            cnt++;
            sum=a[i];
        }
    }
    if(cnt>m)return 1;
    else return false;
}
// 5 |3  3  2
// 1 2  3  4
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int l=0,r=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l=max(a[i],l);//注意这里是最大值
        r+=a[i];
    }
    l--,r++;
    //最大就是一段 最小就是数组中最大的元素
    //注意这里可不能排序！！！ 否则分组的时候就会对结果产生影响
    //sort(a+1,a+1+n);
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<r;
    return 0;
    
}