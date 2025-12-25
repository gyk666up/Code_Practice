//没思路
// 假设我们把树 随便选一个根（通常选 1）
// 考虑一条边：
// u —— v   （假设 v 是 u 的儿子）
// 删掉这条边后，会变成两部分：
// 一边：v 的子树
// 👉 节点数 = sz[v]
// 另一边：剩下的 注意剩下的不是sz[u]
// 👉 节点数 = n - sz[v]
// 所以这条边的费用是：
// cost=c×∣sz[v]−(n−sz[v])∣
// ⚠️ 注意：
// 只要固定方向（父 → 子）
// 每条边只算一次
// #include<bits/stdc++.h>
// using namespace std;

// //当边和边权同时出现时，使用这种数据结构！！！要熟练掌握
// const int N = 1e6 + 5;
// struct Edge {
//     int to;
//     int w;
// };

// int n;
// vector<Edge> g[N];
// long long sz[N];
// long long ans = 0;

// void dfs(int u, int fa)
// {
//     sz[u] = 1;
//     for(auto e : g[u])
//     {
//         int v = e.to;
//         int w = e.w;
//         if(v == fa) continue;
//         dfs(v, u);
//         sz[u] += sz[v];
//         //这里想到了之前的换根公式，但没用，路径统计用差分，（刚刚讲的那个 LCA）全村选址用换根。
//         ans += 1LL * w * llabs(sz[v] - (n - sz[v]));

//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n;
//     for(int i = 1; i < n; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         g[a].push_back({b, c});
//         g[b].push_back({a, c});
//     }

//     dfs(1, 0);
//     cout << ans << "\n";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// int ans;
// int sz[N];//sz[u]以u为根节点的子树大小
// int n;
// typedef struct node
// {
//     int to,w;
// }edge;
// vector<edge>g[N];
// void dfs(int u,int p)
// {
//     sz[u]=1;
//     for( auto [v,w]:g[u])
//     {
//         if(v!=p)
//         {
//             //ans+=w*abs(sz[v]-(n-sz[v]));
//             dfs(v,u);
//             sz[u]+=sz[v];
//             ans+=w*abs(sz[v]-(n-sz[v]));
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y,w;cin>>x>>y>>w;
//         //注意是双向边 容易少写一个
//         g[x].push_back({y,w});
//         g[y].push_back({x,w});
//     }
//     dfs(1,0);
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
#define int long long
struct edge
{
    int to,w;
};
vector<edge>g[N];
int sz[N];//sz 是某条边一侧的点数 并不是“节点子树”
int n;
int ans;
void dfs(int u,int p)
{
    sz[u]=1;
    for(auto[v,w]:g[u])
    {
        if(v!=p)
        {
            dfs(v,u);
            sz[u]+=sz[v];
            //注意这行代码容易写错 v是u的儿子 断开这条边后  [ v 的整棵子树 ] | [ 剩下的所有点 ]
            ans+=w*abs((sz[v]-(n-sz[v])));
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}

