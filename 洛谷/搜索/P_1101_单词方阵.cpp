// //自己的思路 有问题！！！但我感觉思路没问题->AI 修改完善


// #include<bits/stdc++.h>
// using namespace std;

// const int N = 105;
// char g[N][N];       // 输入的字母方阵
// char s[N][N];       // 输出的方阵（找到的单词保留，其余为'*'）
// bool st[N][N];      // 标记当前找到的单词路径
// int n;
// string target = "yizhong";  // 目标单词
// // 8个可能的方向（上下左右、四个对角线）
// int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
// int dy[] = {-1, 1, -1, 1, 0, 0, -1, 1};

// // 递归函数：从(x,y)出发，沿dir方向检查是否匹配target[id..6]
// // 参数：x,y-当前位置；id-当前需要匹配的target下标；dir-固定方向（0~7）
// void dfs(int x, int y, int id, int dir) {
//     // 若已匹配到最后一个字符（id=6），说明找到完整单词
//     if (id == target.size() - 1) {
//         st[x][y] = true;  // 标记当前位置
//         // 将路径上所有标记的位置复制到输出数组s
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= n; j++) {
//                 if (st[i][j]) {
//                     s[i][j] = g[i][j];
//                 }
//             }
//         }
//         st[x][y] = false;  // 回溯：清除当前位置标记
//         return;
//     }
    
//     // 标记当前位置属于路径
//     st[x][y] = true;
    
//     // 沿固定方向dir继续搜索下一个字符
//     int nx = x + dx[dir];
//     int ny = y + dy[dir];
    
//     // 检查下一个位置是否合法，且字符匹配target[id+1]
//     if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
//         if (g[nx][ny] == target[id + 1]) {
//             dfs(nx, ny, id + 1, dir);  // 沿同一方向继续递归
//         }
//     }
    
//     // 回溯：清除当前位置标记
//     st[x][y] = false;
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     cin >> n;
//     // 读取输入方阵（1-based索引，方便边界处理）
//     for (int i = 1; i <= n; i++) {
//         string row;
//         cin >> row;
//         for (int j = 1; j <= n; j++) {
//             g[i][j] = row[j - 1];
//         }
//     }
    
//     // 初始化输出方阵为'*'（未找到的字符默认显示*）
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             s[i][j] = '*';
//         }
//     }
    
//     // 遍历所有可能的起点（以'y'开头，对应target[0]）
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (g[i][j] == target[0]) {  // 找到起点'y'
//                 // 尝试8个方向
//                 for (int dir = 0; dir < 8; dir++) {
//                     memset(st, 0, sizeof(st));  // 每次新方向重置路径标记
//                     dfs(i, j, 0, dir);  // 从id=0（'y'）开始，沿dir方向搜索
//                 }
//             }
//         }
//     }
    
//     // 输出结果
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             cout << s[i][j];
//         }
//         cout << endl;
//     }
    
//     return 0;
// }




// //这个思路很聪明啊
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 110;
// char g[N][N];
// bool vis[N][N]; // 标记单词位置
// int n;
// string target = "yizhong";
// int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// void check(int x, int y) {
//     //遍历8个可能的方向
//     //思路：从当前位置开始（一直沿着某个方向走，遍历字符长度的次数）如果都满足就标记出来
//     for (int d = 0; d < 8; d++) {
//         int nx = x, ny = y;
//         bool flag = true;
//         for (int i = 0; i < 7; i++) {
//             if (nx < 0 || nx >= n || ny < 0 || ny >= n || g[nx][ny] != target[i]) {
//                 flag = false;
//                 break;
//             }
//             nx += dx[d];
//             ny += dy[d];
//         }
//         if (flag) {
//             nx = x, ny = y;
//             for (int i = 0; i < 7; i++) {
//                 vis[nx][ny] = true;
//                 nx += dx[d];
//                 ny += dy[d];
//             }
//         }
//     }
// }

// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> g[i][j];
//         }
//     }
//     memset(vis, 0, sizeof(vis));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (g[i][j] == 'y') {
//                 check(i, j);
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (vis[i][j]) cout << g[i][j];
//             else cout << '*';
//         }
//         cout << endl;
//     }
//     return 0;
// }


//学习别人的思路-》自己的方法
#include<bits/stdc++.h>
using namespace std;
int n;
const int N=103;
char g[N][N];
string target="yizhong";
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,0,1,-1,0,1,-1};
bool st[N][N];
void bfs(int x,int y)
{
    //一个方向走到底
    for(int i=0;i<8;i++)
    {
        bool flg=1;
        int ddx=dx[i],ddy=dy[i];
        for(int j=0;j<7;j++)
        {
            int xx=x+j*ddx,yy=y+j*ddy;
            if(g[xx][yy]==target[j])continue;
            flg=0;
        }
        if(flg)
        {
            for(int j=0;j<7;j++)
            {
                int xx=x+j*ddx,yy=y+j*ddy;
                st[xx][yy]=1;
            }
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>g[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(g[i][j]=='y')
            bfs(i,j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(st[i][j])cout<<g[i][j];
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}