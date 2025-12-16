// //嘿嘿 it is easy for me
// #include<bits/stdc++.h>
// using namespace std;
// //点太多 用邻接表
// int n,d;
// const int N=1e5+33;
// vector<int>g[N];
// int dist[N];//记录每个点到1点距离

// void bfs(int x)
// {
//     queue<int>q;
//     q.push(x);
//     memset(dist,0x3f,sizeof dist);
//     dist[x]=0;
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         for(int i=0;i<g[x].size();i++)
//         {
//             int y=g[x][i];
//             dist[y]=dist[x]+1;
//             if(dist[y]<d)q.push(y);
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>d;
//     for(int i=1;i<=n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     //怎么感觉像bfs呢
//     bfs(1);


//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(dist[i]<=d)ans++;
//         // cout<<dist[i]<<" "<<endl;
//     }
//     //排除自己
//     cout<<ans-1;
//     return 0;
// }


// //dfs
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+55;
// vector<int>g[N];
// int n,d;
// bool vis[N];//标记是否走过
// int ans=0;
// void dfs(int x,int dist)
// {
//     vis[x]=1;
//     for(int i=0;i<g[x].size();i++)
//     {
//         int y=g[x][i];
//         if(!vis[y]&&dist<d)
//         {
//             ans++;
//             dfs(y,dist+1);
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>d;
//     for(int i=1;i<=n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     dfs(1,0);
//     cout<<ans;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
vector<int>g[N];
int ans=0;
bool vis[N];
int n,m;
void dfs(int x,int dist)
{
    vis[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(!vis[y]&&dist<m)
        {
            ans++;
            dfs(y,dist+1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}