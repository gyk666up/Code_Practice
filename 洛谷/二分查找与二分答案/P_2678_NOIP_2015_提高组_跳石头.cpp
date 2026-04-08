// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// #define int long long
// int a[N];
// int L,n,m;
// //  1  2  2  3
// // 10 20 30 40
// bool check(int x)
// {
//     int last=0;//从哪跳过来的
//     int cnt=0;//需要搬走的石头
//     for(int i=1;i<=n;i++)
//     {
//         if(a[i]-a[last]<x)cnt++;//距离太短了（小于最短跳跃距离） 跳不了
//         else last=i;//可以跳
//     }
//     if(L-a[last]<x)cnt++;
//     if(cnt<=m)return 1;
//     else return 0;

// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>L>>n>>m;
//     //a数组代表的是距离起点的距离
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     //遇到二分就排序
//     sort(a+1,a+1+n);
//     //枚举最短跳跃距离->石头数
//     //最短距离越大->搬走的石头数越多
//     int l=0,r=0x3f3f3f3f;
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     cout<<l;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,n,m;
const int N=5e4+11;
int a[N];
bool check(int x)
{
    int last=0;
    int cnt=0;//记录搬走的石头数量
    for(int i=1;i<=n;i++)
    {
        if(a[i]-a[last]<x)cnt++;//太短了，跳不了
        else 
        {
            last=i;
        }
    }
    if(l-a[last]<x)cnt++;//由于终点石头 $L$ 不能动，为了满足“所有跳跃距离都 $\ge x$”这个条件，你唯一的选择就是把 a[last] 这块石头也给搬了

    if(cnt<=m)return true;
    return false;

}
signed main()
{
    cin>>l>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int l=0,r=0x3f3f3f3f;//枚举最短跳跃的距离
    // 2 3 4 5
    // 3 4 4 5
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}
