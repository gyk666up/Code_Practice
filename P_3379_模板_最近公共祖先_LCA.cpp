// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;

// const int MAXN = 5e5 + 10;
// const int LOG = 20;  // 2^20 ≈ 1e6 > 5e5，足够覆盖最大深度

// vector<int> g[MAXN];  // 邻接表存树
// int depth[MAXN];      // 节点深度
// int fa[MAXN][LOG];    // fa[u][k]：u的2^k级祖先

// // BFS预处理depth和fa（避免递归DFS栈溢出）
// void bfs(int root) {
//     queue<int> q;
//     q.push(root);
//     depth[root] = 1;
//     fa[root][0] = 0;  // 根节点的父节点设为0（无意义）
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for (int v : g[u]) {
//             if (v != fa[u][0]) {  // 避免走回父节点
//                 depth[v] = depth[u] + 1;
//                 fa[v][0] = u;
//                 // 递推计算2^k级祖先
//                 for (int k = 1; k < LOG; k++) {
//                     fa[v][k] = fa[fa[v][k-1]][k-1];
//                 }
//                 q.push(v);
//             }
//         }
//     }
// }

// // 查询a和b的LCA
// int lca(int a, int b) {
//     // 保证a的深度 >= b的深度
//     if (depth[a] < depth[b]) swap(a, b);
    
//     // 第一步：将a跳到与b相同深度
//     for (int k = LOG - 1; k >= 0; k--) {
//         if (depth[fa[a][k]] >= depth[b]) {
//             a = fa[a][k];
//         }
//     }
    
//     // 若a和b重合，直接返回
//     if (a == b) return a;
    
//     // 第二步：同时向上跳，直到祖先相同
//     for (int k = LOG - 1; k >= 0; k--) {
//         if (fa[a][k] != fa[b][k]) {
//             a = fa[a][k];
//             b = fa[b][k];
//         }
//     }
    
//     // 最终a和b的父节点就是LCA
//     return fa[a][0];
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);  // 关闭同步，加速输入输出
    
//     int N, M, S;
//     cin >> N >> M >> S;
    
//     // 建边（无向树，双向加边）
//     for (int i = 0; i < N - 1; i++) {
//         int x, y;
//         cin >> x >> y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
    
//     // 预处理
//     bfs(S);
    
//     // 处理查询
//     while (M--) {
//         int a, b;
//         cin >> a >> b;
//         cout << lca(a, b) << '\n';
//     }
    
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n,m,s;
const int N=5e5+11;
const int Log=30;
vector<int>g[N];
int depth[N];//每个点的深度
int fa[N][Log];
void bfs(int x)
{
    fa[x][0]=0;//// 根节点的父节点设为0（无意义）不可以设置成-1 会导致越界内存访问
    depth[x]=1;
    queue<int>q;
    q.push(x);
    while(q.size())
    {
        int x=q.front();q.pop();
        for(int v:g[x])
        {
            if(v!=fa[x][0])
            {
                depth[v]=depth[x]+1;
                fa[v][0]=x;
                for(int k=1;k<Log;k++)
                {
                    fa[v][k]=fa[fa[v][k-1]][k-1];
                }
                q.push(v);
            }
        }
    }
}
int lca(int x,int y)
{
    if(depth[x]<depth[y])swap(x,y);

    //让x往上挑
    for(int k=Log-1;k>=0;k--)
    {
        if(depth[fa[x][k]]>=depth[y])
        x=fa[x][k];
    }
    if(x==y)return x;

    //同时往上挑(为什么这里从大往小跳. 好好想)
    for(int k=Log-1;k>=0;k--)
    {
        //if(depth[fa[x][k]]!=depth[fa[y][k]])
        if (fa[x][k] != 0 && fa[y][k] != 0 && fa[x][k] != fa[y][k]) 
        {
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<n-1;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(s);//预处理
    while(m--)
    {
        int x,y;cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }
    return 0;
}