// //思路是正确的，不过超时了
// //找最长链 
// //可以想象成 一层一层的 每一层需要的最短时间是这一层活动所消耗的最长时间
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=10002;
// // struct edge
// // {
// //     int to,w;
// // };
// vector<int>g[N];
// int t[N];//每项工作完成的时间
// int ans,res;//ans 全局最短 res 一条最短时间
// bool st[N];
// bool vis[N];
// void dfs(int x,int cost)
// {
//     //vis[x]=1;
//     if(g[x].size()==0)
//     {
//         res=max(res,cost);
//         return ;
//     }
//     for(int i=0;i<g[x].size();i++)
//     {
//         int y=g[x][i];
//         if(vis[y]==0)
//         {
//             // cout<<y<<" ";
//             vis[y]=1;
//             dfs(y,cost+t[y]);//找bug找了半天 
//             vis[y]=0;//得回溯啊！！！这里经常写错！！！
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int id,len;cin>>id>>len;
//         t[id]=len;
//         int x;
//         while(cin>>x)
//         {
//             if(x==0)break;
//             g[x].push_back(id);//前置工作指向当前工作
//             st[id]=1;//为了找根节点也就是没有前置工作的节点
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!st[i])
//         {
//             memset(vis,0,sizeof vis);
//             res=0;
//             dfs(i,t[i]);
//             ans+=res;
//         }
//     }
//     cout<<ans;
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+11;
// int dp[N];//dp[i] 杂物i完成的最早时间
// int n;
// int t[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int id,len;cin>>id>>len;
//         int x;
//         int max_pre_time=0;//最长的前序工作
//         int max_pre_id=0;
//         while(cin>>x)
//         {
//             if(x==0)break;
//             //注意这里是dp[x]不是t[x]
//             if(dp[x]>max_pre_time)
//             {
//                 max_pre_time=dp[x];
//                 max_pre_id=x;
//             }
//         }
//         //写的有些冗余了 dp[max_pre_id]不就是max_pre_time吗
//         dp[i]=dp[max_pre_id]+len;
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     ans=max(ans,dp[i]);
//     cout<<ans;
//     return 0;
// }






//方法二：拓扑排序
// #include<bits/stdc++.h>
// using namespace std;

// const int N = 10010;  // 杂务最大数量为10000
// vector<int> adj[N];   // 邻接表：adj[v]存储所有依赖v的杂务u（即v→u）
// int in_degree[N];     // 入度：每个杂务的准备工作数量
// int time_cost[N];     // 每个杂务的耗时
// int earliest[N];      // 每个杂务的最早完成时间

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0);
//     int n;
//     cin >> n;

//     // 读入每个杂务的信息，构建图
//     for (int i = 1; i <= n; ++i) {
//         int task_id, len, pre;
//         cin >> task_id >> len;  // 读杂务编号和耗时
//         time_cost[task_id] = len;

//         // 读准备工作（依赖），直到遇到0
//         while (cin >> pre && pre != 0) {
//             adj[pre].push_back(task_id);  // 建立边：pre→task_id
//             in_degree[task_id]++;         // 增加task_id的入度
//         }
//     }

//     // 拓扑排序：初始化队列（入度为0的节点）
//     queue<int> q;
//     for (int i = 1; i <= n; ++i) {
//         if (in_degree[i] == 0) {
//             q.push(i);
//             earliest[i] = time_cost[i];  // 无依赖，最早完成时间=自身耗时
//         }
//     }

//     // 执行拓扑排序
//     while (!q.empty()) {
//         int v = q.front();  // 取出一个已完成所有依赖的杂务v
//         q.pop();

//         // 遍历所有依赖v的杂务u
//         for (int u : adj[v]) {
//             // 更新u的最早开始时间（取v的完成时间与u当前最早开始时间的最大值）
//             earliest[u] = max(earliest[u], earliest[v]);
//             in_degree[u]--;  // u的一个依赖已完成，入度减1

//             // 若u的所有依赖都已完成，计算其最早完成时间并加入队列
//             if (in_degree[u] == 0) {
//                 earliest[u] += time_cost[u];  // 最早完成时间=最早开始时间+自身耗时
//                 q.push(u);
//             }
//         }
//     }

//     // 总最短时间是所有杂务最早完成时间的最大值
//     int ans = 0;
//     for (int i = 1; i <= n; ++i) {
//         ans = max(ans, earliest[i]);
//     }

//     cout << ans << endl;
//     return 0;
// }
    

#include<bits/stdc++.h>
using namespace std;
int n;
const int N=10002;
int dp[N];
int t[N];
int earliest[N];//每项杂物最早的完成时间=最早开始时间+当前任务所需的时间
int in_degree[N];
vector<int>g[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int id,len;cin>>id>>len;
        int pre;
        t[id]=len;
        while(cin>>pre)
        {
            if(pre==0)break;
            in_degree[id]++;
            g[pre].push_back(id);
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in_degree[i]==0)
        {
            earliest[i]=t[i];
            q.push(i);
        }
    }
    while(q.size())
    {
        int x=q.front();q.pop();
        for(int i=0;i<g[x].size();i++)
        {
            int y=g[x][i];
            earliest[y]=max(earliest[x],earliest[y]);

            in_degree[y]--;
            if(in_degree[y]==0)
            {
                earliest[y]+=t[y];
                q.push(y);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,earliest[i]);
    cout<<ans;
    return 0;
}