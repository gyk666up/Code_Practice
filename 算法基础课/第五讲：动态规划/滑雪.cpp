//错误思路算法错配：BFS + st 数组会扼杀最长路
// BFS（广度优先搜索）配合 st（访问标记）数组，天生是用来求最短路的。
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=302;
// int dx[]={0,0,-1,1};
// int dy[]={1,-1,0,0};
// bool st[N][N];
// int dist[N][N];
// int a[N][N];
// typedef pair<int,int>PII;
// int r,c;
// int res=-1;//最长的路径
// void bfs(int x,int y)
// {
//     queue<PII>q;
//     q.push({x,y});
//     while(q.size())
//     {
//         int x=q.front().first,y=q.front().second;q.pop();
//         st[x][y]=1;
//         for(int i=0;i<4;i++)
//         {
//             int xx=dx[i]+x;
//             int yy=dy[i]+y;
//             if(st[xx][yy])continue;
//             if(xx<1||xx>r||yy<1||yy>c)continue;
//             if(a[xx][yy]<a[x][y])
//             {
//                 q.push({xx,yy});
//                 dist[xx][yy]=dist[x][y]+1;
//                 res=max(res,dist[xx][yy]);
//             }
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>r>>c;
//     int max_=-1;
//     int I,J;
//     for(int i=1;i<=r;i++)
//     {
//         for(int j=1;j<=c;j++)
//         {
//             cin>>a[i][j];
//             if(a[i][j]>max_)
//             {
//                 I=i,J=j;
//             }
//         }
//     }
//     //从最高处往下滑
//     bfs(I,J);
//     cout<<res<<endl;
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// const int N = 302;
// int a[N][N];
// int f[N][N]; // 备忘录：f[i][j] 记录从 (i, j) 出发的最长路径长度
// int r, c;
// int dx[] = {0, 0, -1, 1};
// int dy[] = {1, -1, 0, 0};

// // 记忆化 DFS 函数
// int dp(int x, int y)
// {
//     // 如果这个点已经被算过了，直接查表返回答案，这是保证不超时的核心！
//     if(f[x][y] != -1) return f[x][y];
    
//     // 任何一个点本身就算长度为 1
//     f[x][y] = 1;
    
//     // 尝试向四个方向滑
//     for(int i = 0; i < 4; i++)
//     {
//         int xx = x + dx[i];
//         int yy = y + dy[i];
        
//         // 边界判断
//         if(xx >= 1 && xx <= r && yy >= 1 && yy <= c)
//         {
//             // 只能往更低的地方滑
//             if(a[xx][yy] < a[x][y])
//             {
//                 // 状态转移：取四个方向中的最大值
//                 f[x][y] = max(f[x][y], dp(xx, yy) + 1);
//             }
//         }
//     }
//     return f[x][y];
// }

// signed main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     cin >> r >> c;
    
//     for(int i = 1; i <= r; i++)
//     {
//         for(int j = 1; j <= c; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
    
//     // 初始化备忘录为 -1，表示所有点都没有被算过
//     memset(f, -1, sizeof f);
    
//     int res = -1;
    
//     // 必须遍历矩阵中的每一个点，把每一个点都当做起点尝试一次
//     for(int i = 1; i <= r; i++)
//     {
//         for(int j = 1; j <= c; j++)
//         {
//             res = max(res, dp(i, j));
//         }
//     }
    
//     cout << res << "\n";
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
const int N=302;
int a[N][N];
int f[N][N];//到 f[i][j]:最短的距离
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r,c;
int dp(int x,int y)
{
    if(f[x][y]!=-1)return f[x][y];
    f[x][y]=1;

    for(int i=0;i<4;i++)
    {
        int xx=dx[i]+x;
        int yy=dy[i]+y;
        // if(xx>=1&&xx<=r&&yy<=c&&yy>=1)
        // {
        //     if(a[xx][yy]<a[x][y])
        //     {
        //         f[xx][yy]=max(f[xx][yy],dp(x,y)+1);
        //     }
        // }

        if(xx>=1&&xx<=r&&yy<=c&&yy>=1)
        {
            if(a[xx][yy]<a[x][y])
            {
                f[x][y]=max(f[x][y],dp(xx,yy)+1);
            }
        }
    }
    return f[x][y];

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>r>>c;
    memset(f,-1,sizeof f);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin>>a[i][j];
        }
    }

    //不一定从最高点往下走,每个点都可能是起点
    int res=1;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            res=max(res,dp(i,j));
        }
    }
    cout<<res<<endl;
    return 0;
}