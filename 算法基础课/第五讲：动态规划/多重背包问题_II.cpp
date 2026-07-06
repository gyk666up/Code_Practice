//思路有点屌
// #include<bits/stdc++.h>
// using namespace std;

// // 背包最大容量
// const int MAX_V = 2005;
// int dp[MAX_V];

// // 定义一个结构体来存储拆分后的“新物品”
// struct Good {
//     int v, w;
// };

// int main()
// {
//     // 优化输入输出速度
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
//     int N, V;
//     cin >> N >> V;
    
//     vector<Good> goods; // 存放拆分后得到的所有 01 背包物品
    
//     // 1. 读取数据并进行【二进制拆分】
//     for(int i = 1; i <= N; i++)
//     {
//         int v, w, s;
//         cin >> v >> w >> s;
        
//         // k 是每次打包的数量，以 1, 2, 4, 8... 递增
//         for(int k = 1; k <= s; k *= 2) 
//         {
//             s -= k; // 剩余的物品数量减去已经被打包的
//             // 将打好的包作为一个新物品放入列表
//             // 体积和价值都要乘以 k
//             goods.push_back({v * k, w * k}); 
//         }
//         // 如果最后还有剩下的（比如 13 拆了 1,2,4 后剩 6）
//         // 把剩下的单独打包成一个物品
//         if(s > 0)
//         {
//             goods.push_back({v * s, w * s});
//         }
//     }
    
//     // 2. 把拆分后的 goods 列表当作【01 背包】来求解
//     for(auto good : goods) // 遍历所有新物品
//     {
//         // 01 背包：内层循环倒序遍历容量
//         for(int j = V; j >= good.v; j--) 
//         {
//             dp[j] = max(dp[j], dp[j - good.v] + good.w);
//         }
//     }
    
//     cout << dp[V] << "\n";
    
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=2e6+11;
// int n,V;
// //本质上就是把 s 件商品拆分成 1 2 4 8。。。
// struct good
// {
//     int v,w;
// };
// int dp[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>V;
//     vector<good>goods;
//     for(int i=1;i<=n;i++)
//     {
//         int v,w,s;cin>>v>>w>>s;
//         for(int k=1;k<=s;k*=2)
//         {
//             s-=k;
//             goods.push_back({k*v,k*w});
//         }

//         if(s>0)goods.push_back({s*v,s*w});
//     }
//     for(auto good:goods)
//     {
//         for(int j=V;j>=good.v;j--)
//         {
//             dp[j]=max(dp[j],dp[j-good.v]+good.w);
//         }
//     }
//     cout<<dp[V];
//     return 0;
// }

//优化思路：打包
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e6+11;
int n,m;
struct good
{
    int v,w;
};
vector<good>goods;
int dp[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int v,w,s;cin>>v>>w>>s;
        for(int k=1;k<=s;k*=2)
        {
            goods.push_back({k*v,k*w});
            s-=k;
        }
        if(s>0)
        {
            goods.push_back({s*v,s*w});
        }
    }
    for(int i=0;i<goods.size();i++)//注意这个物品数
    {
        for(int j=m;j>=0;j--)
        {
            if(j>=goods[i].v)
            dp[j]=max(dp[j],dp[j-goods[i].v]+goods[i].w);
        }
    }
    cout<<dp[m];
    return 0;
}