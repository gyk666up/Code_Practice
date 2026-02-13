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


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m,s;
// struct edge
// {
//     int to,w;
// };
// const int N=1e5+66;
// vector<edge>g[N];
// typedef pair<int,int>PII;
// int dist[N];
// bool st[N];
// void Dijkstra(int x)
// {
//     priority_queue<PII,vector<PII>,greater<PII>>q;
//     dist[x]=0;
    
//     //注意这两个顺序不能颠倒，因为是先比较first 后比较second
//     //堆顶“当前距离最小的点”
//     q.push({0,x});//{ 到这个点的最短距离 , 这个点是谁 }
//     while(q.size())
//     {
//         auto[d,x]=q.top();q.pop();

//         if(st[x])continue;

//         st[x]=1;
//         for(auto[v,w]:g[x])
//         {
//             if(dist[v]>d+w)
//             {
//                 dist[v]=d+w;
//                 q.push({dist[v],v});
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
//         g[u].push_back({v,w});//单边
//     }
//     memset(dist,0x3f,sizeof dist);
//     Dijkstra(s);
//     for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m,s;
// const int N=1e5+66;
// struct node
// {
//     int to,w;
// };
// vector<node>g[N];
// bool st[N];
// int dist[N];
// typedef pair<int,int>PII;
// //一个点是在“从堆里第一次弹出时”才确定最短路 只有这时候才能标记st[x]=1;
// void Dijkstra(int x)
// {
//     memset(dist,0x3f,sizeof dist);
//     //st[x]=1;
//     //❌ 你把 st[] 的使用方式写错了
// // ❌ 你过早地把点“锁死”了
// // ❌ 这样会导致最短路算错
//     dist[x]=0;
//     //pair<int,int>PII[d,x]分别是到x点距离 和这个点是x
//     priority_queue<PII,vector<PII>,greater<PII>>q;
//     q.push({0,s});
//     while(q.size())
//     {
//         auto[d,x]=q.top();q.pop();
//         if(st[x])continue;

//         st[x]=1;
//         for(auto[v,w]:g[x])
//         {
//             if(!st[v])
//             {
//                 if(dist[v]>d+w)
//                 {
//                     dist[v]=d+w;
//                     //st[v]=1;
//                     q.push({dist[v],v});
//                 }

//             }
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>s;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }
//     Dijkstra(s);
//     for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
//     return 0;
// }


