// //差分
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// struct node
// {
//     int d,s,t;
// }dat[N];//订单
// int a[N];//每天可借到教室数量
// int diff[N];
// int sum[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     bool flg=1;
//     int id=-1;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>dat[i].d>>dat[i].s>>dat[i].t;
//         //从s到d都要减去d
//         diff[dat[i].s]+=dat[i].d;
//         diff[dat[i].t+1]-=dat[i].d;
//         // a[j] 直接计算为 diff 的前缀和（即累计借用量），并判断其是否为负。
//         //这完全混淆了 “累计借用量” 和 “剩余可用量”，导致判断逻辑颠倒（应该是 初始a[i] < 累计借用量[i] 时不足，而非 累计借用量[i] < 0）。
//         // for(int j=1;j<=n;j++)
//         // {
//         //     a[j]=a[j-1]+diff[j];
//         //     if(a[j]<0)
//         //     {
//         //         flg=0;
//         //         id=i;
//         //         break;
//         //     }
//         // }
//         sum[0]=0;
//         for(int j=1;j<=n;j++)
//         {
//             sum[j]=sum[j-1]+diff[j];
//             if(sum[j]>a[j])
//             {
//                 flg=0;
//                 id=i;
//                 //cout<<"?"<<id<<endl;
//                 break;
//             }
            
//         }
//          //注意这两个点break的使用位置
//         //找到第一个不符合的
//         if(!flg) break; //发现错误立即退出
//     }
//     if(flg)cout<<0<<endl;
//     else cout<<-1<<endl<<id;

//     return 0;
// }

//t了
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 11;

struct node {
    int d, s, t;
} dat[N];

int a[N];      // 初始每天可借教室数量
int diff[N];   // 累计借用量的差分数组
int sum[N];    // 累计借用量（前缀和）

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> dat[i].d >> dat[i].s >> dat[i].t;
    }

    bool flg = true;
    int id = -1;
    // 先计算初始sum（全为0）
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + diff[i];
    }

    for (int i = 1; i <= m; ++i) {
        int d = dat[i].d, s = dat[i].s, t = dat[i].t;
        // 更新差分数组：[s, t]区间增加d的借用量
        diff[s] += d;
        if (t + 1 <= n) {
            diff[t + 1] -= d;
        }

        // 重新计算sum数组的前缀和（从1到n），但只检查[s, t]区间
        // 优化：利用之前的sum，只更新受影响的部分（更高效的方式是重新计算整个sum，但只检查[s,t]）
        sum[0] = 0;
        bool ok = true;
        for (int j = 1; j <= n; ++j) {
            sum[j] = sum[j - 1] + diff[j];
            // 只检查当前订单影响的区间[s, t]
            if (j >= s && j <= t) {
                if (sum[j] > a[j]) {
                    ok = false;
                    id = i;
                    break;
                }
            }
        }

        if (!ok) {
            flg = false;
            break;
        }
    }

    if (flg) {
        cout << 0 << endl;
    } else {
        cout << -1 << endl << id << endl;
    }

    return 0;
}