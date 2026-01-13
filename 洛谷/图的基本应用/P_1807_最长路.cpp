// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1502;
// vector<pair<int,int>>g[N];
// int dp[N];//记录1到其它点的距离

// #define INF -0x3f3f3f3f
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }
    
//     fill(dp+1,dp+1+n,INF);
//     dp[1]=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(dp[i]==INF)continue;//从1到不了这个点
//         for(auto [v,w]:g[i])
//         {
//             if(dp[v]<dp[i]+w)
//             {
//                 dp[v]=dp[i]+w;
//             }
//         }
//     }
//     cout<<(dp[n]==INF?-1:dp[n]);
//     return 0;
// }



// //这道题看着简单，但卡了挺久的还 注意两种方法的区别
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1502;
// struct edge
// {
//     int to,w;
// };
// vector<edge>g[N];
// int dist[N];//记录1到i点的距离
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     //注意这里初始化为负无穷，求最长边 
//     //初始化为正无穷，求最短边 
//     memset(dist,-0x3f,sizeof dist);
//     dist[1]=0;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }   
//     queue<int>q;
//     q.push(1);
//     // //这样求的是最短路径
//     // while(q.size())
//     // {
//     //     int x=q.front();q.pop();
//     //     for(auto [v,w]:g[x])
//     //     {
//     //         if(dist[v]>dist[x]+w)
//     //         {
//     //             dist[v]=dist[x]+w;
//     //             //cout<<"dist[v]"<<"="<<dist[v];
//     //             q.push(v);
//     //         }
//     //     }
//     // }
//     dist[1]=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(dist[i]<-1e9)continue;
//         for(auto[v,w]:g[i])
//         {
//             if(dist[v]<dist[i]+w)
//             {
//                 dist[v]=dist[i]+w;
//             }
//         }
//     }
//     //注意这个表达式的顺序，要想正确的表达需要加上括号来限制
//     cout<<((dist[n]<-1e9)?-1:dist[n]);//这里是小于-1e9!!!
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+666;
// int dist[N];
// struct edge
// {
//     int to,w;
// };
// vector<edge>g[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }
//     memset(dist,-0x3f,sizeof dist);
//     dist[1]=0;
//     queue<int>q;
//     q.push(1);
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         for(auto[v,w]:g[x])
//         {
//             if(dist[v]<dist[x]+w)
//             {
//                 dist[v]=dist[x]+w;
//                 q.push(v);
//             }
//         }
//     }
//     if(dist[n]<-1e9)cout<<-1;
//     else cout<<dist[n];
//     return 0;
// }


