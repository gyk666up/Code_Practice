// #include<bits/stdc++.h>
// using namespace std;
// const int N=1003;
// bool vis[N];//标记牧场是否被访问过
// vector<int>g[N];
// int times[N];//标记每个牧场的访问次数 当牧场的访问次数等于奶牛的人数时所吗这个牧场满足条件
// int milk[N];//记录奶牛所在牧场的编号
// void bfs(int x)//x是牧场编号
// {
//     vis[x]=1;
//     times[x]++;
//     queue<int>q;
//     q.push(x);
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         for(int i=0;i<g[x].size();i++)
//         {
//             int v=g[x][i];
//             if(!vis[v])
//             {
//                 vis[v]=1;
//                 times[v]++;
//                 q.push(v);
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int k,n,m;cin>>k>>n>>m;
//     for(int i=1;i<=k;i++)
//     {
//         int x;cin>>x;
//         milk[i]=x;
//     }
//     for(int j=1;j<=m;j++)
//     {
//         int u,v;cin>>u>>v;
//         g[u].push_back(v);
//     }
//     for(int i=1;i<=k;i++)
//     {
//         memset(vis,0,sizeof vis);
//         bfs(milk[i]);
//     }
//     int cnt=0;
//     //// 错误：遍历的是“奶牛数量k”，且只检查奶牛的起点牧场
//     //有的牧场可能一开始也没有奶牛但不妨碍所有奶牛都可以到达
//     //这样会导致大量符合条件的牧场被遗漏
//     // for(int i=1;i<=k;i++)
//     // {
//     //     if(times[milk[i]]==k)cnt++;
//     // }

//     for(int i=1;i<=n;i++)
//     {
//         if(times[i]==k)cnt++;
//     }
//     cout<<cnt<<endl;
//     return 0;
// }


// //不是对所有的农场进行bfs
// //思路：每一个奶牛所在的农场bfs 当一个农场可以到达的次数达到k时就符合
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1002;
// vector<int>g[N];
// int k,n,m;
// int times[N];
// int milk[N];//每个奶牛所在农场的编号
// bool vis[N];
// void bfs(int x)
// {
//     vis[x]=1;
//     queue<int>q;
//     q.push(x);
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         times[x]++;
//         for(int i=0;i<g[x].size();i++)
//         {
//             int y=g[x][i];
//             if(!vis[y])
//             {
//                 vis[y]=1;
//                 q.push(y);
//             }
//         }
//     }
    
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>k>>n>>m;
//     for(int i=1;i<=k;i++)
//     {
//         int c;cin>>c;
//         milk[i]=c;
//     }
//     for(int i=0;i<m;i++)
//     {
//         int a,b;cin>>a>>b;
//         g[a].push_back(b);
//     }
//     for(int i=1;i<=k;i++)
//     {
//         memset(vis,0,sizeof vis);
//         bfs(milk[i]);//注意这里是milk[i]而不是i 
//         //只找所有奶牛可以到达的位置就行了
//     }
//     int cnt=0;
//     //注意这里很容易写错
//     for(int i=1;i<=n;i++)
//     {
//         //不是times[milk[i]]==k 有可能一个农场没有奶牛，但所有的奶牛都可以到达
//         if(times[i]==k)cnt++;
//     }
//     cout<<cnt;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int k,n,m;
int milk[N];
bool vis[N];
int times[N];//统计每个农场可以到达的次数
vector<int>g[N];
void bfs(int x)
{
    vis[x]=1;
    times[x]++;
    queue<int>q;
    q.push(x);
    while(q.size())
    {
        int x=q.front();q.pop();
        for(int i=0;i<g[x].size();i++)
        {
            int y=g[x][i];
            if(vis[y]==0)
            {
                vis[y]=1;
                times[y]++;
                q.push(y);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++)
    {
       cin>>milk[i];
    }
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=k;i++)
    {
        memset(vis,0,sizeof vis);
        bfs(milk[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(times[i]==k)ans++;
    }
    cout<<ans;
    return 0;
}