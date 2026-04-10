// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1502;
// vector<pair<int,int>>g[N];
// int dp[N];//记录1到其它点的距离

// #define INF -0x3f3f3f3f
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }
    
//     fill(dp+1,dp+1+n,INF);
//     dp[1]=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(dp[i]==INF)continue;//从1到不了这个点
//         for(auto [v,w]:g[i])
//         {
//             if(dp[v]<dp[i]+w)
//             {
//                 dp[v]=dp[i]+w;
//             }
//         }
//     }
//     cout<<(dp[n]==INF?-1:dp[n]);
//     return 0;
// }



// //这道题看着简单，但卡了挺久的还 注意两种方法的区别
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1502;
// struct edge
// {
//     int to,w;
// };
// vector<edge>g[N];
// int dist[N];//记录1到i点的距离
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     //注意这里初始化为负无穷，求最长边 
//     //初始化为正无穷，求最短边 
//     memset(dist,-0x3f,sizeof dist);
//     dist[1]=0;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }   
//     queue<int>q;
//     q.push(1);
//     // //这样求的是最短路径
//     // while(q.size())
//     // {
//     //     int x=q.front();q.pop();
//     //     for(auto [v,w]:g[x])
//     //     {
//     //         if(dist[v]>dist[x]+w)
//     //         {
//     //             dist[v]=dist[x]+w;
//     //             //cout<<"dist[v]"<<"="<<dist[v];
//     //             q.push(v);
//     //         }
//     //     }
//     // }
//     dist[1]=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(dist[i]<-1e9)continue;
//         for(auto[v,w]:g[i])
//         {
//             if(dist[v]<dist[i]+w)
//             {
//                 dist[v]=dist[i]+w;
//             }
//         }
//     }
//     //注意这个表达式的顺序，要想正确的表达需要加上括号来限制
//     cout<<((dist[n]<-1e9)?-1:dist[n]);//这里是小于-1e9!!!
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+666;
// int dist[N];
// struct edge
// {
//     int to,w;
// };
// vector<edge>g[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }
//     memset(dist,-0x3f,sizeof dist);
//     dist[1]=0;
//     queue<int>q;
//     q.push(1);
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         for(auto[v,w]:g[x])
//         {
//             if(dist[v]<dist[x]+w)
//             {
//                 dist[v]=dist[x]+w;
//                 q.push(v);
//             }
//         }
//     }
//     if(dist[n]<-1e9)cout<<-1;
//     else cout<<dist[n];
//     return 0;
// }


//以后在图论里，如果不是用来找连通块或者拓扑排序，千万不要轻易用 DFS 配合条件去更新距离。改用 queue（队列）可以帮你省去 99% 的超时烦恼！这下这个逻辑彻底理顺了吧？

// 你这句“为啥啊”问得非常精髓！我猜你大概率是对这两种情况中的某一个（或者两个）感到难以置信：
// 1. **为什么 `memset` 填进去一个数，最后会变成一个风马牛不相及的乱码数字？**
// 2. **为什么 BFS 只是去掉了 `in_queue`（门卫），队列就会发生“核爆炸”？**

// 我都给你掰开揉碎了讲清楚！这俩可是 C++ 和图论里极其经典的底层原理。

// ---

// ### 🧐 第一问：`memset` 到底在底层干了什么见不得人的事？

// 很多初学者以为 `memset(dist, -0x3f, sizeof dist)` 的意思是：“把 `dist` 数组里的每一个 `int` 都变成 `-0x3f`（也就是 -63）”。
// **错！大错特错！**

// `memset` 是 C 语言时代留下来的底层老古董，它的工作方式是**按字节（Byte）**来填写的。
// 1. **你的数组是 `int` 型的。** 在 C++ 里，一个 `int` 占 **4 个字节**。
// 2. **你传入的 `-0x3f`（-63）。** 计算机把它转成 8 位的二进制补码，刚好是 `11000001`，也就是十六进制的 **`C1`**。
// 3. **`memset` 开始无脑填装：** 它根本不管你这是一个整体的 `int`，它像个机器人一样，把这个 `C1` 强行塞进 `int` 的 4 个字节里。
// 4. **拼装成怪物：** 一个原本纯洁的 `int`，它的 4 个字节全被塞满了 `C1`。拼在一起就变成了十六进制的 **`0xC1C1C1C1`**。

// 在 32 位有符号整数里，`0xC1C1C1C1` 代表的十进制数字是多少呢？
// **答案是：-1044266559**。

// 你看，你原本只想要一个 -63，结果 `memset` 经过一顿底层字节拼接，给你造出了一个 -10.4 亿的怪物。

// **再看看你代码里的 `if` 判断：**
// 你要比较的对手是 `-0x3f3f3f3f`，它在十进制里等于 **-1061109567**（-10.6 亿）。
// 因为 **-10.4 亿 > -10.6 亿**，条件成立，所以哪怕这个点没走到，它也会把你这个怪物数字给打印出来！

// > **黄金法则：** 在 C++ 里，除了填 `0`、`-1`（因为 -1 的所有字节都是 11111111）和极其特殊的 `0x3f`，**绝对不要用 `memset` 填任何其他数字！** 否则填出来的全是无法预测的拼接怪。

// ---

// ### 🤯 第二问：为什么没有 `in_queue`，队列会“核爆炸”？

// 你可以把 BFS 队列想象成一个**“传播好消息的排队窗口”**。

// **如果不加 `in_queue`（你的错误写法）：**
// 1. 节点 5 发现一条新路，距离变长了（比如变成了 10）！它很高兴，跑去排队，准备等会儿告诉它的邻居。
// 2. **此时节点 5 还在队伍里排着队呢。**
// 3. 突然，又有一条新路走到了节点 5，发现距离更长了（变成了 20）！节点 5 的数据被更新成了 20。
// 4. 按照你的代码，只要数据更新，就无脑 `push` 进队列。**于是，节点 5 又跑去队尾排了一个分身！**
// 5. 现在队列里有两个“节点 5”。
// 6. 等到这两个“节点 5”出队时，它们都会把自己的邻居重新更新一遍，导致邻居们也产生无数个分身跑去排队……
// 7. **后果：** 队伍越来越长，呈指数级裂变，内存瞬间被撑爆（MLE），或者永远处理不完（TLE）。

// **加了 `in_queue`（正确的 SPFA 写法）：**
// 1. 节点 5 发现距离变成 10，跑去排队（`in_queue[5] = true`）。
// 2. 在它排队等待的期间，距离又被更新成了 20。
// 3. 此时一看 `in_queue[5]` 是 `true`！**系统说：“你人已经在队伍里了，不用再排一个分身了！你只要把你口袋里的记分牌改成 20 就行，等会儿轮到你，你照样能把最新的 20 告诉你的邻居。”**
// 4. **后果：** 队列里永远保证每个节点最多只有 1 个，绝不会有分身。完美避免了指数级爆炸！

// 这下是不是把底层玄学和算法逻辑全都打通了？
#include<bits/stdc++.h>
using namespace std;
const int N=1600;
int dist[N];//到起点的距离
struct edge
{
    int to,w;
};

vector<edge>g[N];
int n,m;
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    while(q.size())
    {
        int x=q.front();q.pop();
        for(auto[y,w]:g[x])
        {
            if(dist[y]<dist[x]+w)
            {
                dist[y]=dist[x]+w;
                q.push(y);
            }
        }
    }
}
int main()
{
    memset(dist,-0x3f,sizeof dist);
    dist[1]=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    bfs(1);
    if(dist[n]>-1e9)cout<<dist[n];
    else cout<<-1;
    return 0;
}





























