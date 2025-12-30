// // //想到之前做过的一道题，联通块的个数变化>=2说明是关键节点
// // //好像不太对 那个是关键节点 这个是关键线路
// // #include<bits/stdc++.h>
// // using namespace std;
// // int n,m;
// // const int N=150;
// // // vector<int>g[N];
// // typedef pair<int,int>PII;
// // vector<PII>ans;
// // struct Edge
// // {
// //     int x,y;
// // };
// // int fa[N];
// // int lian;
// // vector<Edge>edge;
// // int find(int x)
// // {
// //     if(fa[x]==x)return x;
// //     return fa[x]=find(fa[x]);
// // }
// // void merge(int x,int y)
// // {
// //     int xx=find(x),yy=find(y);
// //     if(xx==yy)return ;
// //     fa[yy]=xx;
// // }
// // bool is_key(int id)
// // {
// //     int cnt=0;
// //     for(int i=1;i<=n;i++)fa[i]=i;
// //     for(int i=0;i<m;i++)
// //     {
// //         if(i==id)continue;
// //         if(find(edge[i].x)!=find(edge[i].y))
// //         {
// //             merge(edge[i].x,edge[i].y);
// //         }
// //     }
// //     for(int i=1;i<=n;i++)
// //     {
// //         if(fa[i]==i)cnt++;
// //     }
// //     if(lian-cnt>=2)return true;
// //     return false;
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)fa[i]=i;
// //     for(int i=0;i<m;i++)
// //     {
// //         int x,y;cin>>x>>y;
// //         edge.push_back({x,y});
// //         merge(x,y);
// //     }
// //     for(int i=1;i<=n;i++)if(fa[i]==i)lian++;
// //     //可能的边
// //     for(int i=0;i<edge.size();i++)
// //     {
// //         if(is_key(i))
// //         {
// //             ans.push_back({edge[i].x,edge[i].y});
// //         }
// //     }
// //     sort(ans.begin(),ans.end());
// //     //cout<<ans.size();
// //     for(auto[a,b]:ans)
// //     {
// //         cout<<a<<" "<<b;
// //     }
// //     return 0;
// // }


// //算法思路：Tarjan 求桥(割边)
// //在 DFS 树中，一个节点的时间戳一定小于他的子树中的所有节点。
// //割边 / 桥一定是“单独的一条边”,那种叫边割集（Edge Cut）
// //low[u]能回溯到的最早时间 dfn[u]（到达时间）

// //有点费脑子啊
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 155;
// vector<int> g[N];
// int n, m;
// int dfn[N], low[N], timer;
// vector<pair<int,int>> bridges;

// void tarjan(int u, int parent)
// {
//     dfn[u] = low[u] = ++timer;
//     for (int v : g[u])
//     {
//         if (!dfn[v])
//         {
//             tarjan(v, u);
//             low[u] = min(low[u], low[v]);//回溯的时候更新

//             // 判桥条件 孩子无论如何翻不过父亲这座大山 这种肯定是一个桥
//             if (low[v] > dfn[u])
//             {
//                 int a = min(u, v);
//                 int b = max(u, v);
//                 bridges.push_back({a, b});
//             }
//         }
//         else if (v != parent)//有其他路回去
//         {
//             low[u] = min(low[u], dfn[v]);
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }

//     // 图是连通的，从 1 开始 DFS 即可
//     tarjan(1, 0);
//     //for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i,i);//图可能不连通，初始时fa是i不会出现问题

//     sort(bridges.begin(), bridges.end());

//     for (auto [a, b] : bridges)
//     {
//         cout << a << " " << b << "\n";
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=160;
vector<int>g[N];
int dfn[N],low[N];
int n,m;
int timer=0;
vector<PII>bridge;
void tarjan(int u,int p)
{
    dfn[u]=low[u]=++timer;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);

            if(low[v]>dfn[u])
            {
                int a=min(u,v);
                int b=max(u,v);
                bridge.push_back({a,b});
            }
        }
        else if(v!=p)
        {
            low[u]=min(low[u],low[v]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    tarjan(1,0);
    sort(bridge.begin(),bridge.end());
    for(int i=0;i<bridge.size();i++)
    {
        cout<<bridge[i].first<<" "<<bridge[i].second<<endl;
    }
    return 0;
}