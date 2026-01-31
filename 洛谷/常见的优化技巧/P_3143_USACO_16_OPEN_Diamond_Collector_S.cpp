//为什么是两个展柜呢
//而且答案为什么是奇数而不是偶数呢
//理解有偏差

//不只是=k才可以放到一个展柜中，而是《=k可以放到一个展柜中

//你可以选 两个不相交的子集合
//每个展示柜 = 排序后的一段连续区间
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 50005;
// int a[N];
// int len[N];   // len[i]: 以 i 为右端点的合法区间长度
// int pre[N];   // pre[i]: 前 i 个位置里最大的 len

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     long long k;
//     cin >> n >> k;

//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }

//     sort(a + 1, a + n + 1);

//     // 双指针：算 len[i]
//     //“以第 r 个钻石作为最大值时，一个展示柜最多能放多少颗钻石”
//     int l = 1;
//     for (int r = 1; r <= n; r++) {
//         while (a[r] - a[l] > k) {
//             l++;
//         }
//         len[r] = r - l + 1;
//     }

//     // 前缀最大
//     for (int i = 1; i <= n; i++) {
//         pre[i] = max(pre[i - 1], len[i]);
//     }

//     // 枚举第二个区间的右端点
//     int ans = 0;
//     l = 1;
//     for (int r = 1; r <= n; r++) {
//         while (a[r] - a[l] > k) {
//             l++;
//         }
//         // 第二个区间是 [l, r]
//         // 第一个区间只能在 l-1 之前
//         ans = max(ans, (l > 1 ? pre[l - 1] : 0) + (r - l + 1));
//     }

//     cout << ans << "\n";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// const int N=5e4+11;
// int a[N];
// int len[N];//len[i]：以i为右端点的最大区间长度
// int prefix[N];//prefix[i]:前i中区间的最大长度
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     sort(a+1,a+1+n);
//     int l=1;
//     for(int r=1;r<=n;r++)
//     {
//         while(a[r]-a[l]>k)
//         l++;

//         len[r]=r-l+1;
//     }

//     for(int i=1;i<=n;i++)
//     prefix[i]=max(prefix[i-1],len[i]);

//     int ans=0;
//     //枚举第二个区间的右端点
//      l=1;
//     for(int r=1;r<=n;r++)
//     {
//         while(a[r]-a[l]>k)
//         l++;

//         ans=max(ans,(l>0?prefix[l-1]:0)+r-l+1);
//     }
//     cout<<ans;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e4+11;
int a[N];
int len[N];//len[i]以i为右端点区间的最大值
int prefix[N];//prefix[i]前i区间范围内的最大值
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+1+n);
    int l=1;
    for(int r=1;r<=n;r++)
    {
        while(a[r]-a[l]>k)l++;

        len[r]=r-l+1;
    }
    for(int i=1;i<=n;i++)
    {
        prefix[i]=max(prefix[i-1],len[i]);
    }
    int ans=0;
    l=1;
    for(int r=1;r<=n;r++)
    {
        while(a[r]-a[l]>k)l++;
        ans=max(ans,prefix[l-1]+r-l+1);
    }
    cout<<ans;
    return 0;
}