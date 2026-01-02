// //Tarjan 求 SCC = 在 DFS 树上，用栈维护“当前还可能属于同一个 SCC 的点”

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 10005;
// vector<int> g[N];
// int n, m;

// int dfn[N], low[N], timer;
// bool instk[N];
// stack<int> st;

// int scc_cnt;        // SCC 个数
// int scc_size[N];    // 每个 SCC 的大小

// void tarjan(int u)
// {
//     dfn[u] = low[u] = ++timer;
//     st.push(u);
//     instk[u] = true;

//     for (int v : g[u])
//     {
//         if (!dfn[v])
//         {
//             tarjan(v);
//             low[u] = min(low[u], low[v]);
//         }
//         else if (instk[v])//👉 v 不需要、也不可能像无向图那样“特殊判断父节点”，Tarjan SCC 是有向图算法，这是有向图
//         {
//             low[u] = min(low[u], dfn[v]);
//         }
//     }

//     // u 是 SCC 的根
//     if (dfn[u] == low[u])
//     {
//         scc_cnt++;
//         int x;
//         do
//         {
//             x = st.top();
//             st.pop();
//             instk[x] = false;
//             scc_size[scc_cnt]++;
//         } while (x != u);

//         //这段代码不对 首先就是x没初始化，其次u也得弹出来
//         // while(x!=u)
//         // {
//         //     x = st.top();
//         //     st.pop();
//         //     instk[x] = false;
//         //     scc_size[scc_cnt]++;
//         // }


//         //这段代码可以
//         // while (true)
//         // {
//         //     int x = st.top();
//         //     st.pop();
//         //     instk[x] = false;
//         //     scc_size[scc_cnt]++;
//         //     if (x == u) break;
//         // }

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
//     }

//     // 图不一定连通
//     for (int i = 1; i <= n; i++)
//         if (!dfn[i])
//             tarjan(i);

//     int ans = 0;
//     for (int i = 1; i <= scc_cnt; i++)
//         if (scc_size[i] > 1)
//             ans++;

//     cout << ans << "\n";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1e4+11;
// vector<int>g[N];
// int dfn[N],low[N];
// stack<int>stk;
// bool instk[N];
// int timer;
// int scc_size[N];//每个强联通分量的大小
// int ans;
// void tarjan(int u)
// {
//     dfn[u]=low[u]=++timer;
//     stk.push(u);
//     instk[u]=1;
//     for(int i=0;i<g[u].size();i++)
//     {
//         int v=g[u][i];
//         if(!dfn[v])
//         {
//             tarjan(v);
//             low[u]=min(low[u],low[v]);
//         }
//         else if(instk[v])
//         {
//             low[u]=min(low[u],dfn[v]);
//         }
//     }

//     if(dfn[u]==low[u])
//     {
//         ans++;
//         while(1)
//         {
//             int x=stk.top();
//             stk.pop();
//             instk[x]=0;
//             scc_size[ans]++;
//             if(x==u)break;
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=m;i++)
//     {
//         int a,b;cin>>a>>b;
//         g[a].push_back(b);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!dfn[i])tarjan(i);
//     }
//     int cnt=0;
//     for(int i=1;i<=ans;i++)
//     {
//         if(scc_size[i]>1)cnt++;
//     }

//     cout<<cnt;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=1e4+11;
int dfn[N],low[N];
bool instk[N];
int n,m;
int scc_size[N];
int ans;
vector<int>g[N];
int timer;
stack<int>stk;
void tarjan(int u)
{ 
    dfn[u]=low[u]=++timer;
    stk.push(u);
    instk[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(instk[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        ans++;
        while(1)
        {
            int x=stk.top();stk.pop();
            instk[x]=0;
            scc_size[ans]++;
            if(x==u)break;
        }

    }
    
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])tarjan(i);
    }

    int cnt=0;
    for(int i=1;i<=ans;i++)
    {
        if(scc_size[i]>1)cnt++;
    }
    cout<<cnt;
    return 0;
}