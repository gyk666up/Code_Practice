// //第一眼感觉是最短路径问题、
// #include<bits/stdc++.h>
// using namespace std;
// int n,m,s,t;
// const int N=1e4+11;
// struct edge
// {
//     int to,w;
// };
// vector<edge>g[N];
// int dist[N];
// typedef pair<int,int>PII;
// //int st[N];
// void Dijkstra(int x)
// {
//     priority_queue<PII,vector<PII>,greater<PII>>q;
//     memset(dist,0x3f,sizeof dist);
//     q.push({0,s});
//     dist[s]=0;
//     while(q.size())
//     {
//         auto t=q.top();q.pop();
//         int d=t.first,u=t.second;
//         for(auto [v,w]:g[u])
//         {
//             if(dist[v]>d+w)
//             {
//                 dist[v]=d+w;
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>s>>t;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//         g[v].push_back({u,w});
//     }
//     Dijkstra(s);
//     cout<<dist[t]<<endl;
//     return 0;
// }

//为什么 Dijkstra / 最短路不合适？
//路径上 最大的拥挤度尽量小
//不是：
// 边权和最小 ❌
// 路径最短 ❌
// **这道题不是“走得最短”，
// 而是“最挤的那一步尽量不挤”

// ⇒ 最小瓶颈路
// ⇒ MST 性质
// ⇒ Kruskal + 并查集**
//在最小生成树中，任意两点之间的路径，其最大边权是所有路径中最小的
// #include <bits/stdc++.h>
// using namespace std;

// struct Edge {
//     int u, v, w;
//     bool operator<(const Edge& e) const {
//         return w < e.w;
//     }
// };

// const int N = 10005;
// int fa[N];

// int find(int x) {
//     if (fa[x] == x) return x;
//     return fa[x] = find(fa[x]);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m, s, t;
//     cin >> n >> m >> s >> t;

//     vector<Edge> edges(m);
//     for (int i = 0; i < m; i++) {
//         cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     }

//     sort(edges.begin(), edges.end());

//     for (int i = 1; i <= n; i++) fa[i] = i;

//     for (auto &e : edges) {
//         int fu = find(e.u);
//         int fv = find(e.v);
//         if (fu != fv) {
//             fa[fu] = fv;
//             //越往后枚举的越大
//             if (find(s) == find(t)) {
//                 cout << e.w;
//                 return 0;
//             }
//         }
//     }
//     return 0;
// }

