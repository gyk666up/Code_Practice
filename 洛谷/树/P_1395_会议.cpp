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





// //2025/12/21 感觉良好，尽管没有完全写出来，但对比之前已经进步很多了
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=5e4+11;
// vector<int>g[N];
// int siz[N];
// int sum_dist[N];//记录以u为根节点的距离和
// int ans_node;
// int ans_dist;
// void dfs1(int u,int fa)
// {
//     siz[u]=1;//记得初始化
//     sum_dist[u]=0;
//     for(int i=0;i<g[u].size();i++)
//     {
//         int v=g[u][i];
//         if(v!=fa)
//         {
//             dfs1(v,u);
//             siz[u]+=siz[v];

//             //以v为根节点的子树中每个节点到u比v+1
//             sum_dist[u]+=sum_dist[v]+siz[v];
//         }
//     }
// }
// void dfs2(int u,int fa)
// {
//     //距离相同编号更小或者距离更小
//     if(sum_dist[u]<ans_dist||(sum_dist[u]==ans_dist&&u<ans_node))
//     {
//         ans_dist=sum_dist[u];
//         ans_node=u;
//     }

//     //换根公式
//     for(int i=0;i<g[u].size();i++)
//     {
//         int v=g[u][i];
//         if(v!=fa)
//         {
//             sum_dist[v]=sum_dist[u]-siz[v]+n-siz[v];
//             dfs2(v,u);
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     //注意是n-1
//     for(int i=1;i<=n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
    
//     //计算以1为根节点的sum_dist和子树的大小
//     dfs1(1,-1);

//     ans_dist=0x3f3f3f3f;
//     ans_node=0x3f3f3f3f;
//     //计算以每个节点为根的距离和
//     dfs2(1,-1);
//     cout<<ans_node<<" "<<ans_dist;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e4+66;
// vector<int>g[N];
// int n;
// int siz[N];//siz[i]以i为根节点的子树大小
// int sum_dist[N];//sum_dist[i]:以i为根节点的距离和
// int dist=0x3f3f3f3f;
// int ans=0x3f3f3f3f;
// //第一遍 DFS：算“以 1 为根”的子树信息
// //第二遍 DFS：只能用公式推，绝对不能再调用第一遍 DFS
// void dfs(int x,int fa)
// {
//     siz[x]=1;
//     sum_dist[x]=0;

//     for(int i=0;i<g[x].size();i++)
//     {
//         int y=g[x][i];
//         if(y!=fa)
//         {
//             dfs(y,x);

//             siz[x]+=siz[y];
//             sum_dist[x]+=sum_dist[y]+siz[y];
//         }
//     }
// }
// void dfs2(int x,int fa)
// {
//     if(dist>sum_dist[x]||(dist==sum_dist[x]&&x<ans))
//     {
//         dist=sum_dist[x];
//         ans=x;
//     }

//     for(int i=0;i<g[x].size();i++)
//     {
//         int y=g[x][i];
//         if(y!=fa)
//         {
//             sum_dist[y]=sum_dist[x]-siz[y]+(n-siz[y]);
//             dfs2(y,x);//别写错了是调用dfs2
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     dfs(1,0);
    
//     //for(int i=1;i<=n;i++)cout<<siz[i];
    
//     dfs2(1,0);
//     cout<<ans<<" "<<dist;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=5e4+11;
// int siz[N];
// int sum_dist[N];
// vector<int>g[N];
// int dist=0x3f3f3f3f,ans=0x3f3f3f3f;
// void dfs(int u,int fa)
// {
//     siz[u]=1;
//     sum_dist[u]=0;

//     for(int i=0;i<g[u].size();i++)
//     {
//         int v=g[u][i];
//         if(v!=fa)
//         {
//             dfs(v,u);
//             siz[u]+=siz[v];
//             sum_dist[u]+=sum_dist[v]+siz[v];
//         }
//     }
// }
// void dfs1(int u,int fa)
// {
//     if(sum_dist[u]<dist||(sum_dist[u]==dist&&u<ans))
//     {
//         dist=sum_dist[u];
//         ans=u;
//     }

//     for(int i=0;i<g[u].size();i++)
//     {
//         int v=g[u][i];
//         if(v!=fa)
//         {

//             sum_dist[v]=sum_dist[u]-siz[v]+(n-siz[v]);
//             dfs1(v,u);

//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=0;i<n-1;i++)
//     {
//         int a,b;cin>>a>>b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     dfs(1,0);

//     dfs1(1,0);

//     cout<<ans<<" "<<dist;
//     return 0;
// }


