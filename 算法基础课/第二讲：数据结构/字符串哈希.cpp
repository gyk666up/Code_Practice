//超时
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// string s;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     cin>>s;
//     while(m--)
//     {
//         int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
//         l1--,r1--,l2--,r2--;
//         if(s.substr(l1,r1-l1+1)==s.substr(l2,r2-l2+1))cout<<"Yes\n";
//         else cout<<"No\n";
//     }
//     return 0;
// }


#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ULL; // 使用 ULL 利用无符号整数自动溢出特性，相当于 % 2^64

const int N = 100010, P = 131; // P 经验值取 131 或 13331，冲突几率极低

ULL h[N]; // h[i] 存储前缀子串 1~i 的哈希值
ULL p[N]; // p[i] 存储 P^i 的幂次值

// 获取区间 [l, r] 的哈希值
ULL get_hash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    // 优化 I/O 速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    p[0] = 1; // P^0 = 1
    // 预处理前缀哈希数组 h 和次方数组 p
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        // s[i-1] 是因为 string 下标从 0 开始，但我们的哈希下标从 1 开始
        h[i] = h[i - 1] * P + s[i - 1]; 
    }

    // 处理 m 次询问
    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        // 如果两个区间的哈希值相同，说明子串完全相同
        if (get_hash(l1, r1) == get_hash(l2, r2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}