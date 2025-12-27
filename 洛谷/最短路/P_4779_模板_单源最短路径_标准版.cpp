// //稠图 用Dijkstra
// //朴素Dijkstra n<=2000
// //全t了
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m,s;
// const int N=1e5+66;
// struct edge
// {
//     int to,w;
// };
// int dist[N];//记录起点的距离
// vector<edge>g[N];
// bool st[N];
// void Dijkstra(int s)
// {
//     memset(dist,0x3f,sizeof dist);
//     dist[s]=0;
//     for(int i=1;i<=n;i++)
//     {
//          // 1️⃣ 在所有未确定的点中，找 dist 最小的
//         int ansnode=-1,ansdist=0x3f3f3f3f;
//         for(int j=1;j<=n;j++)
//         {
//             if(!st[j]&&dist[j]<ansdist)
//             {
//                 ansdist=dist[j];
//                 ansnode=j;
//             }
//         }
        
//         // 如果找不到可扩展的点，直接结束
//         if(ansnode==-1)break;
//         st[ansnode]=1;

//         // 3️⃣ 用 选好的点 去松弛它能到达的点

//         for(auto [v,w]:g[ansnode])
//         {
//             if(dist[v]>dist[ansnode]+w)
//             {
//                 dist[v]=dist[ansnode]+w;
//             }
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>s;
//     for(int i=1;i<=m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//         g[v].push_back({u,w});
//     }
//     Dijkstra(s);
//     for(int i=1;i<=n;i++)
//     cout<<dist[i]<<" ";
//     return 0;
// }

//  堆优化n<=1e5+1
//每次从「还没确定最短路的点」中，选一个当前距离最小的点，把它的最短路“定死”，再用它去更新别人。
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// int n, m, s;
// const int N = 1e5 + 66;

// struct edge
// {
//     int to, w;
// };

// vector<edge> g[N];
// int dist[N];
// bool st[N];

// void Dijkstra(int s)
// {
//     memset(dist, 0x3f, sizeof dist);
//     memset(st, 0, sizeof st);

//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
//     // pair: {当前距离, 点}

//     dist[s] = 0;
//     q.push({0, s});

//     while(!q.empty())
//     {
//         auto [d, u] = q.top();
//         q.pop();

//         // 如果这个点已经确定过，跳过
//         if(st[u]) continue;
//         st[u] = true;

//         // 用 u 去松弛邻边
//         for(auto [v, w] : g[u])
//         {
//             if(dist[v] > d + w)
//             {
//                 dist[v] = d + w;
//                 q.push({dist[v], v});
//             }
//         }
//     }
// }

// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//     cin >> n >> m >> s;
//     for(int i = 1; i <= m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         //有向图
//         g[u].push_back({v, w});
//        //g[v].push_back({u, w});
//     }

//     Dijkstra(s);

//     for(int i = 1; i <= n; i++)
//         cout << dist[i] << " ";

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n,m,s;
struct edge
{
    int to,w;
};
const int N=1e5+55;
vector<edge>g[N];

int dist[N];
typedef pair<int,int>PII;
void Dijkstra(int x)
{
    //memset(st,0,sizeof st);
    memset(dist,0x3f,sizeof dist);

    dist[x]=0;

    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,s});//当前距离和这个点

    while(q.size())
    {
        auto t=q.top();q.pop();
        int d=t.first,u=t.second;
        
        for(auto [v,w]:g[u])
        {
            if(dist[v]>d+w)
            {
                dist[v]=d+w;
                q.push({dist[v],v});
            }
        }
    }

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
    return 0;
}