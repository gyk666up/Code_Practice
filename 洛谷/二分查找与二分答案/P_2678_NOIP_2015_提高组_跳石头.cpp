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

// #include<bits/stdc++.h>
// using namespace std;
// int L,n,m;
// const int N=5e4+11;
// int a[N];
// bool check(int x)
// {
//     int cnt=0;//需要搬走的石头
//     int last=0;
//     for(int i=1;i<=n;i++)
//     {
//         //注意是小于不是小于等于
//         if(a[i]-a[last]<x)
//         {
//             //距离小于最短距离 需要搬走
//             cnt++;
//         }
//         else last=i;
//     }
//     if(L-a[last]<x) cnt++;
//     if(cnt<=m)return true;
//     return false;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>L>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
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



