// //对每个点都使用Dijkstra算法，然后比较大小吗？
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=1;
// vector<int>g[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <climits> // 用于LLONG_MAX
// using namespace std;

// const int MAXN = 5e4 + 10; // 适配题目最大数据范围
// vector<int> adj[MAXN];     // 邻接表存储树
// long long sz[MAXN];        // sz[u]：以u为根的子树节点数（用long long避免溢出）
// long long sum_dis[MAXN];   // sum_dis[u]：所有节点到u的距离和
// long long min_sum;         // 最小距离和
// int ans_node;              // 最优节点（距离和最小，编号最小）
// int n;                     // 总节点数

// // 第一次DFS：后序遍历，计算sz和sum_dis[1]（初始根为1）
// void dfs1(int u, int fa) {
//     sz[u] = 1;
//     sum_dis[u] = 0;
//     for (int v : adj[u]) {
//         if (v == fa) continue;
//         dfs1(v, u);
//         sz[u] += sz[v];
//         // 子树v的每个节点到u的距离 = 到v的距离 + 1，故累加sum_dis[v] + sz[v]
//         sum_dis[u] += sum_dis[v] + sz[v];
//     }
// }

// // 第二次DFS：换根DP，推导所有节点的sum_dis，更新最优解
// void dfs2(int u, int fa) {
//     // 更新最优解：距离和更小 或 距离和相同但编号更小
//     if (sum_dis[u] < min_sum || (sum_dis[u] == min_sum && u < ans_node)) {
//         min_sum = sum_dis[u];
//         ans_node = u;
//     }
//     // 遍历所有子节点，推导子节点的距离和
//     for (int v : adj[u]) {
//         if (v == fa) continue;
//         // 换根核心公式：sum_dis[v] = sum_dis[u] - sz[v] + (n - sz[v])
//         sum_dis[v] = sum_dis[u] - sz[v] + (n - sz[v]);
//         dfs2(v, u);
//     }
// }

// int main() {
//     ios::sync_with_stdio(false); // 加速cin/cout
//     cin.tie(nullptr);

//     cin >> n;
//     // 构建邻接表（无向树）
//     for (int i = 0; i < n - 1; ++i) {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     // 初始化最优值
//     min_sum = LLONG_MAX;
//     ans_node = n; // 初始设为最大编号，确保优先选小编号

//     // 两次DFS求解
//     dfs1(1, -1); // 初始根为1，父节点设为-1
//     dfs2(1, -1);

//     // 输出结果
//     cout << ans_node << " " << min_sum << endl;

//     return 0;
// }

// 核心公式(根从u换到v时):
// sum_disv=sum_disu-sz[v]+(n-sz[v])
// ·解释:
// 。当根从u变为v时，v的子树(大小为 sz [v])中所有节点到v的距离比到 u少1，总距离减少 sz[v]。
// 。非v子树的节点(共n-sz [v]个)到v的距离比到 u多1，总距离增加n - sz[v]。
// 。因此，v的距离和 =u的距离和-sz [v]+(n-sz [v])。

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=5e4+66;
vector<int>g[N];
int sum_dist[N];//sum_dist[u]以节点u为根节点的距离和
int siz[N];//每个子树的大小

int ans_node=0x3f3f3f3f;//最佳节点和最短距离
int ans_dist=0x3f3f3f3f;
void dfs1(int u,int fa)
{
    siz[u]=1;
    for(int v:g[u])
    {
        if(v!=fa)
        {
            dfs1(v,u);
            siz[u]+=siz[v];
            //v子树每个点到达u点距离等于到v到距离+1
            //注意这里是累加操作 和下面的注意区别
            sum_dist[u]+=sum_dist[v]+siz[v];
//              sum_dist[u] = sum_dist[v] + siz[v]; 是赋值操作，而非累加操作。
// 原理：节点u的距离和 = 所有子节点v的「子树距离和（sum_dist [v]） + 子树大小（siz [v]，每个节点到 u 多 1）」的总和。
    }
    }
}
void dfs2(int u,int fa)
{
    if(sum_dist[u]<ans_dist||sum_dist[u] == ans_dist&&u<ans_node)
    {
        ans_dist=sum_dist[u];
        ans_node=u;
    }
    //换根公式
    for(int v:g[u])
    {
        if(v!=fa)
        {
            //dfs2(v,u);
            sum_dist[v]=sum_dist[u]-siz[v]+(n-siz[v]);
            dfs2(v,u);//为什么要放在这里！！！
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    //计算节点1的子树大小和距离和
    dfs1(1,-1);

    //计算最佳节点，和最短距离
    dfs2(1,-1);

    cout<<ans_node<<" "<<ans_dist;
    return 0;
}
