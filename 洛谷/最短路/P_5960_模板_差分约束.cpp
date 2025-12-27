// 解一堆不等式
// 变成了：
//dist[i] = 当前已知的 x_i 的最大允许上界
//注意！不是“最短距离”的物理意义，
//而是：x_i 最多只能这么大
// 在一个图里，找一组 dist[]，满足所有：
// dist[v] ≤ dist[u] + w

//每个点的值，不能超过它所有“前驱点 + 边权”的最小值

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 5000 + 5;
// const int INF = 1e9;

// struct Edge {
//     int to, w;
// };

// int n, m;
// vector<Edge> g[N];
// int dist[N], cnt[N];
// bool inq[N];

// bool spfa()
// {
//     queue<int> q;

//     for (int i = 1; i <= n; i++)
//     {
//         dist[i] = 0;//注意这里初始为0！！！
//         cnt[i] = 0;
//         inq[i] = true;
//         q.push(i);
//     }

//     while (!q.empty())
//     {
//         int u = q.front(); q.pop();
//         inq[u] = false;

//         for (auto e : g[u])
//         {
//             int v = e.to, w = e.w;
//             if (dist[v] > dist[u] + w)
//             {
//                 dist[v] = dist[u] + w;
//                 cnt[v]++;
//                 if (cnt[v] >= n) return false; // 负环，无解
//                 if (!inq[v])
//                 {
//                     inq[v] = true;
//                     q.push(v);
//                 }
//             }
//         }
//     }
//     return true;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int c, c2, y;
//         cin >> c >> c2 >> y;
//         g[c2].push_back({c, y});
//     }

//     if (!spfa())
//     {
//         cout << "NO\n";
//         return 0;
//     }

//     for (int i = 1; i <= n; i++)
//         cout << dist[i] << " ";
//     cout << "\n";

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e3+44;
// struct edge
// {
//     int to,w;
// };
// int dist[N];
// int cnt[N];
// int inq[N];
// int n,m;
// vector<edge>g[N];
// bool spf()
// {
//     queue<int>q;
//     for(int i=1;i<=n;i++)
//     {
//         dist[i]=0;
//         cnt[i]=0;
//         q.push(i);
//         inq[i]=1;
//     }
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         for(auto[v,w]:g[x])
//         {
//             if(dist[v]>dist[x]+w)
//             {
//                 dist[v]=dist[x]+w;
//                 cnt[v]++;
//                 inq[v]=0;
//                 if(cnt[v]>=n)return false;

//                 if(!inq[v])
//                 {
//                     inq[v]=1;
//                     q.push(v);
//                 }
//             }
//         }
//     }
//     return true;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int c,c1,y;cin>>c>>c1>>y;
//         g[c1].push_back({c,y});
//     }
//     if(!spf())
//     {
//         cout<<"NO\n";
//         return 0;
//     }
//     for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
//     cout<<'\n';
//     return 0;
// }
