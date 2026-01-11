// //没太大问题，就是最后的小细节注意一下
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m;
// const int N=5e3+66;
// vector<int>g[N];
// const int p=80112002;
// int dp[N];//到dp【i】的条数
// int in_degree[N];
// int out_degree[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     //我这里的建的边正好和题目是相反的，不会影响最后的结果
//     for(int i=0;i<m;i++)
//     {
//         int u,v;cin>>u>>v;
//         g[v].push_back(u);//u生产者，v消费者
//         out_degree[v]++;
//         in_degree[u]++;
//     }
//     queue<int>q;
//     for(int i=1;i<=n;i++)
//     {
//         if(in_degree[i]==0)
//         {
//             dp[i]=1;
//             q.push(i);
//         }
//     }
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         for(int i=0;i<g[x].size();i++)
//         {
//             int y=g[x][i];
//             dp[y]=(dp[x]+dp[y])%p;
//             in_degree[y]--;

//             if(in_degree[y]==0)
//             {
//                 q.push(y);
//             }
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         //生产者
//         //注意这里 ans+=dp[i]❎ 有可能会超过p，因此要记得%p
//         if(out_degree[i]==0)ans=(ans+dp[i])%p;
//     }
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=5e3+11;
vector<int>g[N];
const int p=80112002;
int n,m;
int in_degree[N];
int out_degree[N];
int ans=0;
int dp[N];//到i得路径条数
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        g[v].push_back(u);
        in_degree[u]++;
        out_degree[v]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in_degree[i]==0)
        {
            dp[i]=1;//!!!
            q.push(i);
        }
    }
    //bfs需不需要使用标记数组关键在于一个点是否允许被多次访问
    //在这道题中很明显一点可以被多次访问，所以就不用标记数组
    while(q.size())
    {
        int x=q.front();q.pop();
        for(int i=0;i<g[x].size();i++)
        {
            int y=g[x][i];
            dp[y]=(dp[y]+dp[x])%p;

            in_degree[y]--;
            if(in_degree[y]==0)
            {
                q.push(y);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(out_degree[i]==0)ans=(ans+dp[i])%p;
    }
    cout<<ans;
    return 0;
}