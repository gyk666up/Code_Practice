// #include<bits/stdc++.h>
// using namespace std;
// int e[205];//每层楼对应的按键
// int n,a,b;
// int ans=0x3f3f3f3f;
// bool st[205];//要想最快到达肯定是不走重复的楼梯
// void dfs(int x,int cnt) //x是当前的楼梯层数
// {
//     if(cnt>ans)return ;//肯定不是最佳的 
//     if(x==b)
//     {
//         ans=min(ans,cnt);
//         return ;
//     }

//     // //注意这里容易写成x+e[x]<=b
//     //这里有问题 本来想巧妙一点
//     //这会导致后续 “下跳” 的计算逻辑出错 —— 因为 “下跳” 需要基于原始楼层 x 计算（即 原始x - e[原始x]），但此时 x 已经被改为 “上跳后的楼层”，导致下跳的计算变成了 
//     //上跳后的x - e[上跳后的x]（使用了错误的楼层和错误的 e 值）。
//     //通过这样的操作回不到原来的x
//     //x+e[x]=3+3;
//     //x-=e[x]=6-e[6]=!=x(不一定等于原来的x 3)
//     // if(x+e[x]<=n&&!st[x+e[x]])//可以上
//     // {
//     //     x+=e[x];
//     //     st[x]=1;
//     //     dfs(x,cnt+1);
//     //     st[x]=0;
//     //     x-=e[x];
//     // }
//     // if(x-e[x]>=1&&!st[x-e[x]])
//     // {
//     //     x-=e[x];
//     //     st[x]=1;
//     //     dfs(x,cnt+1);
//     //     st[x]=0;
//     //     x+=e[x];
//     // }

//     int y_up = x + e[x];
//     if(y_up <=n && !st[y_up])//新楼层合法且未访问
//     {
//         st[y_up] = 1;       // 标记新楼层
//         dfs(y_up, cnt+1);   // 递归处理新楼层
//         st[y_up] = 0;       // 回溯：取消标记
//     }

//     // 2. 处理下跳：计算新楼层y_down，不修改原x
//     int y_down = x - e[x];
//     if(y_down >=1 && !st[y_down])//新楼层合法且未访问
//     {
//         st[y_down] = 1;     // 标记新楼层
//         dfs(y_down, cnt+1); // 递归处理新楼层
//         st[y_down] = 0;     // 回溯：取消标记
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>a>>b;
//     st[a]=1;//注意这个 很关键 没有这个第一个楼层就永远不会标记 会走重复的位置
//     for(int i=1;i<=n;i++)cin>>e[i];
//     dfs(a,0);
//     if(ans==0x3f3f3f3f)cout<<-1;
//     else cout<<ans;
//     return 0;
// }


// //一般找最短距离用bfs
// #include<bits/stdc++.h>
// using namespace std;
// int n,a,b;
// const int N=1000;
// bool st[N];
// int e[N];
// int ans[N];//记录结果
// int dy[]={-1,1};//只有上和下两个选项
// void bfs(int y)
// {
//     st[y]=1;
//     ans[y]=0;
//     queue<int>q;
//     q.push(y);
//     bool flg=0;
//     while(q.size())
//     {   
//         int y=q.front();q.pop();
//         for(int i=0;i<2;i++)
//         {
//             int yy=y+dy[i]*e[y];
//             //不是y是yy！！
//             if(yy<1||yy>n)continue;//这个需要先判断！！！
//             if(st[yy])continue;
//             st[yy]=1;//这行代码别忘记
//             ans[yy]=ans[y]+1;
//             //提前判断时间更快
//             if(yy==b){
//                 flg=1;
//             }
//             q.push(yy);
//         }
//         if(flg)break;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>a>>b;
//     for(int i=1;i<=n;i++)cin>>e[i];
//     bfs(a);
//     //如果a==b 应该输出0
//     if(!ans[b]&&a!=b)cout<<-1;
//     else cout<<ans[b];
//     return 0;
// }



//2025/12/19 还可以
//一、暴力枚举+剪枝 卡了几个点
// #include<bits/stdc++.h>
// using namespace std;
// const int N=300;
// int n,a,b;
// int env[N];
// bool st[N];
// int ans=0x3f3f3f3f;
// void dfs(int x,int cnt)
// {
//     if(cnt>=ans)return;
//     if(x==b)
//     {
//         ans=min(ans,cnt);
//         return;
//     }

//     //对应这个枚举
//     if(x+env[x]<=n)//注意这里是<=n
//     {
//         if(!st[x+env[x]])
//         {
//             st[x+env[x]]=1;
//             dfs(x+env[x],cnt+1);
//             st[x+env[x]]=0;
//         }
//     }
//     if(x-env[x]>=1)
//     {
//         if(!st[x-env[x]])
//         {
//             st[x-env[x]]=1;
//             dfs(x-env[x],cnt+1);
//             st[x-env[x]]=0;
//         }
//     }
//     return ;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>a>>b;
//     for(int i=1;i<=n;i++)cin>>env[i];
//     dfs(a,0);
//     if(ans>1e9)cout<<-1;
//     else cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n,a,b;
const int N=300;
int env[N];
int dx[]={1,-1};
int dist[N];
bool st[N];
#define INF 0x3f3f3f3f
int bfs(int x)
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);

    dist[x]=0;
    st[x]=1;
    queue<int>q;
    q.push(x);
    while(q.size())
    {
        int x=q.front();q.pop();
        for(int i=0;i<2;i++)
        {
            int xx=x+dx[i]*env[x];
            if(xx<1||xx>n)continue;
            if(st[xx])continue;
            
            st[xx]=1;
            dist[xx]=dist[x]+1;
            if(xx==b)return dist[xx];
            q.push(xx);
        }
    }
    //注意这个return 容易不写忽略
    return INF;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)cin>>env[i];
    int ans=bfs(a);
    if(b==a)cout<<0;//我靠这个点真是坑
    else if(ans>1e9)cout<<-1;
    else cout<<ans;
    return 0;
}