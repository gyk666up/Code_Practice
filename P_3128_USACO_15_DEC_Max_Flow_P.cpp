// //思路是什么，一个点到另一端这条路该怎么找（bfs？）
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e4+11;
// vector<int>g[N];
// int n,k;
// //预处理任意两个点的最短距离 
// struct node
// {
//     int x,y;
//     int cnt;
// }edge[N];

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         edge[i].x=x;
//         edge[i].y=y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         bfs(1);
//     }
//     return 0;
// }


// //
// // 1️⃣ 树上路径统计 = LCA + 差分 + DFS 汇总
// // 2️⃣ 路径 (u, v) 的差分公式是：
// //    u++, v++, lca--, fa[lca]--
// // 3️⃣ 所有树上“路径加点 / 加边”的题，第一反应就是这套模板
// #include<bits/stdc++.h>
// using namespace std;

// const int N = 5e4 + 5;
// const int LOG = 17; // 2^16 > 5e4

// int n, k;
// vector<int> g[N];
// int depth[N], fa[N][LOG];
// int cnt[N];
// int ans = 0;

// /* ---------- LCA 预处理 ---------- */
// void dfs1(int u, int p)
// {
//     fa[u][0] = p;
//     depth[u] = depth[p] + 1;

//     for(int i = 1; i < LOG; i++)
//         fa[u][i] = fa[fa[u][i-1]][i-1];

//     for(int v : g[u])
//         if(v != p)
//             dfs1(v, u);
// }

// int lca(int x, int y)
// {
//     if(depth[x] < depth[y]) swap(x, y);

//     for(int i = LOG - 1; i >= 0; i--)
//         if(depth[fa[x][i]] >= depth[y])
//             x = fa[x][i];

//     if(x == y) return x;

//     for(int i = LOG - 1; i >= 0; i--)
//         if(fa[x][i] != fa[y][i])
//             x = fa[x][i], y = fa[y][i];

//     return fa[x][0];
// }


// /* ---------- 差分汇总 ---------- */
// void dfs2(int u, int p)
// {
//     for(int v : g[u])
//         if(v != p)
//         {
//             dfs2(v, u);
//             cnt[u] += cnt[v];
//         }
//     ans = max(ans, cnt[u]);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> k;
//     for(int i = 1; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }

//     dfs1(1, 0); // 以 1 为根

//     while(k--)
//     {
//         int u, v;
//         cin >> u >> v;
//         int w = lca(u, v);

//         //有点难理解
//         //路径两头 +1，LCA 减一次，LCA 的父亲再减一次
//         cnt[u]++;
//         cnt[v]++;
//         cnt[w]--;
//         if(fa[w][0]) cnt[fa[w][0]]--;
//     }

//     dfs2(1, 0);

//     cout << ans << "\n";
//     return 0;
// }



//理解了60%
#include<bits/stdc++.h>
using namespace std;
const int N=5e4+11;
vector<int>g[N];
const int Log=20;
int fa[N][Log];
int n,k;
int depth[N];
int cnt[N];
int ans=0;
//初始化 fa数组 dep数组
void dfs1(int u,int p)
{
    fa[u][0]=p;
    //刚开始这个fa数组没有初始化🤣
    for(int i=1;i<=Log-1;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=p)
        {
            depth[v]=depth[u]+1;
            dfs1(v,u);
        }
    }
}
int lca(int x,int y)
{
    if(depth[x]<depth[y])swap(x,y);
    //让x跳到和y相同的高度
    for(int i=Log-1;i>=0;i--)
    {
        if(depth[fa[x][i]]>=depth[y])
        x=fa[x][i];
    }
    //现在x和y处在相同的高度上
    if(x==y)return x;//说明y是之前x的祖先

    //一块向上跳
    for(int i=Log-1;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i])
        x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
void dfs2(int u,int p)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=p)
        {
            //这两代码的顺序注意一下
            //cnt[u]+=cnt[v];
            dfs2(v,u);
            cnt[u]+=cnt[v];
        }
    }
    ans=max(ans,cnt[u]);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1,0);

    for(int i=0;i<k;i++)
    {
        int s,t;cin>>s>>t;
        cnt[s]++;
        cnt[t]++;
        int w=lca(s,t);
        cnt[w]--;
        if(fa[w][0])cnt[fa[w][0]]--;
    }
    dfs2(1,0);
    cout<<ans;
    return 0;
}