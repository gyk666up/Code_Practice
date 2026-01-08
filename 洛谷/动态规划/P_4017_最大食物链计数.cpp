// #include<bits/stdc++.h>
// using namespace std;
// //有多少条合法食物链，最后一个生物是 x
// const int N=5e5+11;
// vector<int>g[N];
// int in_degree[N];
// int out_degree[N];
// int n,m;
// int dp[N];//dp[i] 用来存储以生物 i 结尾的最大食物链数量。
// const int p=80112002;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int u,v;cin>>u>>v;
//         g[v].push_back(u);
//         in_degree[u]++;
//         out_degree[v]++;
//     }
//     //拓扑排序初始化 入度为0
//     queue<int>q;
//     for(int i=1;i<=n;i++)
//     {
//         if(in_degree[i]==0)
//         {
//             q.push(i);
//             dp[i]=1;
//         }
//     }
//     while(q.size())
//     {
//         int u=q.front();q.pop();

//         for(int v:g[u])
//         {
//             dp[v]=(dp[v]+dp[u])%p;
//             in_degree[v]--;
//             if(in_degree[v]==0)
//             {
//                 q.push(v);
//             }
//         }
//     }

//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(out_degree[i]==0)
//         {
//             ans=(ans+dp[i])%p;
//         }
//     }
//     cout<<ans;

//     return 0;
// }






