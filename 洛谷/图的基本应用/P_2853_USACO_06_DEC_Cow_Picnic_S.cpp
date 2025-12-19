#include<bits/stdc++.h>
using namespace std;
const int N=1003;
bool vis[N];//标记牧场是否被访问过
vector<int>g[N];
int times[N];//标记每个牧场的访问次数 当牧场的访问次数等于奶牛的人数时所吗这个牧场满足条件
int milk[N];//记录奶牛所在牧场的编号
void bfs(int x)//x是牧场编号
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
            int v=g[x][i];
            if(!vis[v])
            {
                vis[v]=1;
                times[v]++;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int k,n,m;cin>>k>>n>>m;
    for(int i=1;i<=k;i++)
    {
        int x;cin>>x;
        milk[i]=x;
    }
    for(int j=1;j<=m;j++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=k;i++)
    {
        memset(vis,0,sizeof vis);
        bfs(milk[i]);
    }
    int cnt=0;
    //// 错误：遍历的是“奶牛数量k”，且只检查奶牛的起点牧场
    //有的牧场可能一开始也没有奶牛但不妨碍所有奶牛都可以到达
    //这样会导致大量符合条件的牧场被遗漏
    // for(int i=1;i<=k;i++)
    // {
    //     if(times[milk[i]]==k)cnt++;
    // }

    for(int i=1;i<=n;i++)
    {
        if(times[i]==k)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}