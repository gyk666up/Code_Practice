// // #include<bits/stdc++.h>
// // using namespace std;
// // int n,m;
// // const int N=2e4+11;
// // vector<int>g[N];
// // vector<int>ans;
// // int dfn[N],low[N];
// // int timer;
// // void tarjan(int u,int p)
// // {
// //     dfn[u]=low[u]=++timer;
// //     for(int i=0;i<g[u].size();i++)
// //     {
// //         int v=g[u][i];
// //         if(dfn[v]==0)
// //         {
// //             tarjan(v,u);
// //             low[u]=min(low[u],low[v]);

// //             if(low[v]>=dfn[u])
// //             {
// //                 ans.push_back(u);
// //             }
// //         }
// //         else if(v!=p)
// //         {
// //             low[u]=min(low[u],low[v]);
// //         }
// //     }
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     for(int i=0;i<m;i++)
// //     {
// //         int x,y;cin>>x>>y;
// //         g[x].push_back(y);
// //         g[y].push_back(x);
// //     }
// //     for(int i=1;i<=n;i++)
// //     {
// //         if(dfn[i]==0)tarjan(i,i);
// //     }
// //     //tarjan(1,0);
// //     sort(ans.begin(),ans.end());
// //     cout<<ans.size();
// //     for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
// //     return 0;
// // }


// #include <bits/stdc++.h>
// using namespace std;

// const int N = 20005;
// vector<int> g[N];
// int dfn[N], low[N], timer;
// bool cut[N];
// int n, m;

// void tarjan(int u, int parent)
// {
//     dfn[u] = low[u] = ++timer;
//     int child = 0;

//     for (int v : g[u])
//     {
//         if (!dfn[v])
//         {
//             child++;
//             tarjan(v, u);
//             low[u] = min(low[u], low[v]);

//             // 非根割点判定   注意这里是>= 而且u是割点
//             if (parent != 0 && low[v] >= dfn[u])
//                 cut[u] = true;
//         }
//         else if (v != parent)
//         {
//             low[u] = min(low[u], dfn[v]);
//         }
//     }

//     // 根割点判定  只有两个节点的话不存在割点
//     if (parent == 0 && child >= 2)
//         cut[u] = true;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }

//     for (int i = 1; i <= n; i++)
//         if (!dfn[i])
//             tarjan(i, 0);

//     vector<int> ans;
//     for (int i = 1; i <= n; i++)
//         if (cut[i])
//             ans.push_back(i);

//     cout << ans.size() << "\n";
//     for (int x : ans) cout << x << " ";
//     cout << "\n";

//     return 0;
// }


// //每个割点仅标记一次，避免重复加入，解决了重复计数的核心问题。
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=2e4+11;
// vector<int>g[N];
// vector<int>ans;
// int dfn[N],low[N];
// int timer;
// bool cnt[N];
// void tarjan(int u,int p)
// {
//     dfn[u]=low[u]=++timer;
//     int child=0;
//     for(int i=0;i<g[u].size();i++)
//     {
//         int v=g[u][i];
//         if(!dfn[v])
//         {
//             child++;
//             tarjan(v,u);
//             low[u]=min(low[u],low[v]);
            
//             if(p!=0&&low[v]>=dfn[u])
//             {
//                 cnt[u]=1;
//                 //ans.push_back(u);
//             }
//         }
//         //low[v] >= dfn[u] 对根永远成立
//         else if(v!=p)//u 不是根，且存在一个子树 v：v 及其子树无法通过返祖边回到 u 的祖先
//         {
//             low[u]=min(low[u],dfn[v]);
//             //low[u]=min(low[u],low[v]);
//         }
//     }
//     if(p==0&&child>=2)
//     {
//         cnt[u]=1;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     //图不一定联通
//     for(int i=1;i<=n;i++)
//     {
//         if(!dfn[i])
//         {
//             tarjan(i,0);
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(cnt[i])ans.push_back(i);
//     }
//     sort(ans.begin(),ans.end());
//     cout<<ans.size()<<endl;
//     for(int i=0;i<ans.size();i++)
//     {
//         cout<<ans[i]<<" ";
//     }
// }




#include<bits/stdc++.h>
using namespace std;
const int N=2e4+11;
int dfn[N],low[N];
vector<int>g[N];
vector<int>ans;
bool cnt[N];//标记是否是割点
int n,m;
int timer;
void tarjan(int u,int p)
{
    dfn[u]=low[u]=++timer;
    int child=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!dfn[v])
        {
            child++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);

            if(p!=0&&low[v]>=dfn[u])
            {
                cnt[u]=1;
            }
        }
        else if(v!=p)
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(p==0&&child>=2)
    {
        cnt[u]=1;
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
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])tarjan(i,0);
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i])ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}