// SPFA 判负环的核心思路（一定要记住）
// 关键结论：
// 如果 某个点被松弛 ≥ n 次
// ⇒ 从起点可达的 负环存在
// 为什么？
// 一条最短路最多经过 n-1 条边
// 第 n 次还能变短 ⇒ 一定绕环 ⇒ 且环是负的


// Bellman-Ford 的核心定理（非常重要）
// 对一个有 n 个点的图：
// 一条不包含环的最短路径，最多只会经过 n-1 条边
// 为什么？
// 每经过一条边，至少会到一个“新点”
// 一共就 n 个点

// 🔥 推论（关键）
// 如果你在 第 n 次松弛 时，
// 还能让某个点的距离变小
// 👉 一定经过了环
// 而还能变小
// 👉 这个环一定是负环

// | 数组    | 用在哪      | 含义     | 能否再次更新 |
// | ----- | -------- | ------ | ------ |
// | `st`  | Dijkstra | 最短路已确定 | ❌ 不会   |
// | `inq` | SPFA     | 是否在队列中 | ✅ 可以   |

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 2005;
// const int M = 6005;
// const int INF = 0x3f3f3f3f;

// struct Edge {
//     int to, w;
// };

// vector<Edge> g[N];
// int dist[N], cnt[N];
// bool inq[N];
// int n, m;

// bool spfa_has_negative_cycle()
// {
//     memset(dist, 0x3f, sizeof dist);
//     memset(cnt, 0, sizeof cnt);
//     memset(inq, 0, sizeof inq);

//     queue<int> q;
//     dist[1] = 0;
//     q.push(1);
//     inq[1] = true;

//     while(!q.empty())
//     {
//         int u = q.front(); q.pop();
//         inq[u] = false;

//         for(auto e : g[u])
//         {
//             int v = e.to, w = e.w;
//             if(dist[v] > dist[u] + w)
//             {
//                 dist[v] = dist[u] + w;
//                 cnt[v] = cnt[u] + 1;

//                 if(cnt[v] >= n)
//                     return true;  // 存在从 1 可达的负环

//                 if(!inq[v])
//                 {
//                     q.push(v);
//                     inq[v] = true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;
//     while(T--)
//     {
//         cin >> n >> m;
//         for(int i = 1; i <= n; i++)
//             g[i].clear();

//         for(int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin >> u >> v >> w;
//             if(w >= 0)
//             {
//                 g[u].push_back({v, w});
//                 g[v].push_back({u, w});
//             }
//             else
//             {
//                 g[u].push_back({v, w});
//             }
//         }

//         if(spfa_has_negative_cycle())
//             cout << "YES\n";
//         else
//             cout << "NO\n";
//     }
//     return 0;
// }
 

#include<bits/stdc++.h>
using namespace std;
int t,n,m;
const int N=2e3+66;
struct edge
{
    int to,w;
};
vector<edge>g[N];
int inq[N],cnt[N],dist[N];
bool spfa(int x)
{
    memset(dist,0x3f,sizeof dist);
    memset(inq,false,sizeof inq);
    memset(cnt,0,sizeof cnt);
    queue<int>q;
    q.push(x);
    inq[x]=1;
    dist[x]=0;
    while(q.size())
    {
        int x=q.front();q.pop();
        inq[x]=0;
        for(auto[v,w]:g[x])
        {
            if(dist[v]>dist[x]+w)
            {
                dist[v]=dist[x]+w;
                //cnt[v]++;
                cnt[v]=cnt[x]+1;//👉 它不是“入队次数”，而是：，“到 v 的这条更短路径，比到 x 的路径多走了一条边”
                if(cnt[v]>=n)return true;

                if(inq[v]==0)
                {
                    q.push(v);
                    inq[v]=1;
                }
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=m;i++)
        {
            int u,v,w;cin>>u>>v>>w;
            if(w>=0)
            {
                g[u].push_back({v,w});
                g[v].push_back({u,w});
            }
            else
            {
                g[u].push_back({v,w});
            }
        }
        if(spfa(1))cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}