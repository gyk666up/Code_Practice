// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m;
// const int N=1e6+11;
// int a[N];
// bool check(int x)
// {
//     int ans=0;//记录所获得的木材
//     for(int i=1;i<=n;i++)
//     {
//         if(a[i]<x)continue;
//         ans+=a[i]-x;
//     }
//     //是负相关的关系
//     if(ans>=m)return true;
//     else return false;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     sort(a+1,a+1+n);
//     int l=0,r=a[n]+1;//锯片的范围
//     //枚举锯片的最高高度  //跟以前做过的跳石头那道题很像
//     //锯片的高度越高 所获得的木材数量越少
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))
//             l=mid;
//         else r=mid;
//     }
//     cout<<l<<endl;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int  long long
// int n,m;
// const int N=1e6+11;
// int a[N];
// bool check(int x)
// {
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(a[i]<x)continue;
//         else ans+=a[i]-x;
//     }
//     if(ans>=m)return 1;
//     else return 0;

// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     sort(a+1,a+1+n);
//     int l=0,r=a[n]+1;
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     cout<<l;
//     return 0;
// }



//2025/12/18
#include<bits/stdc++.h>
using namespace std;
int n,m;
#define int long long
const int N=1e6+11;
int a[N];
bool check(int x)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=x)continue;
        ans+=a[i]-x;
    }
    if(ans>=m)return true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int maxa=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    int l=0,r=maxa+1;
    while(l+1!=r)
    {
        int mid=(l+r)/2;//枚举锯片的高度
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}