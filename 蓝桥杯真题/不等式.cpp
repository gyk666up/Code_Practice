// #include <iostream>
// using namespace std;

// // 初始棋盘，0表示未填写的空格
// int grid[5][5] = {
//     {0, 0, 0, 0, 0},
//     {0, 3, 0, 0, 0},
//     {3, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0},
//     {0, 0, 0, 4, 1}
// };

// // 记录某行、某列是否已经用过了数字 1~5
// bool row_used[5][6] = {false};
// bool col_used[5][6] = {false};

// // 检查在 (r, c) 填入 val 是否合法
// bool check(int r, int c, int val) {
//     // 1. 检查行和列是否冲突
//     if (row_used[r][val] || col_used[c][val]) return false;

//     // 先暂时填入该数字，方便后续判断不等式
//     grid[r][c] = val;
//     bool ok = true;

//     // 2. 检查所有的不等式限制 (只有当不等式两边的格子都有数字时才进行比较)
    
//     // 第一行的三个 <
//     if (grid[0][1] && grid[0][2] && grid[0][1] >= grid[0][2]) ok = false;
//     if (grid[0][2] && grid[0][3] && grid[0][2] >= grid[0][3]) ok = false;
//     if (grid[0][3] && grid[0][4] && grid[0][3] >= grid[0][4]) ok = false;
    
//     // 纵向：第一行第5列 < 第二行第5列
//     if (grid[0][4] && grid[1][4] && grid[0][4] >= grid[1][4]) ok = false;
    
//     // 第二行的 >
//     if (grid[1][2] && grid[1][3] && grid[1][2] <= grid[1][3]) ok = false;
    
//     // 第三行的 >
//     if (grid[2][3] && grid[2][4] && grid[2][3] <= grid[2][4]) ok = false;
    
//     // 纵向：第三行第2列 > 第四行第2列
//     if (grid[2][1] && grid[3][1] && grid[2][1] <= grid[3][1]) ok = false;

//     // 恢复现场
//     grid[r][c] = 0;
//     return ok;
// }

// void dfs(int r, int c) {
//     // 如果搜到了最后一行之后，说明成功填满了
//     if (r == 5) {
//         // 直接打印最终拼接成的字符串结果
//         for (int i = 0; i < 5; i++) {
//             for (int j = 0; j < 5; j++) {
//                 cout << grid[i][j];
//             }
//         }
//         cout << endl;
//         return;
//     }

//     // 计算下一个需要填写的格子坐标
//     int next_r = (c == 4) ? r + 1 : r;
//     int next_c = (c == 4) ? 0 : c + 1;

//     // 如果当前格子已经有初始数字，直接跳过填下一个
//     if (grid[r][c] != 0) {
//         dfs(next_r, next_c);
//         return;
//     }

//     // 尝试填入 1~5
//     for (int i = 1; i <= 5; i++) {
//         if (check(r, c, i)) {
//             // 标记占用并填入
//             grid[r][c] = i;
//             row_used[r][i] = true;
//             col_used[c][i] = true;
            
//             // 继续搜下一个格子
//             dfs(next_r, next_c);
            
//             // 搜完后回溯，取消标记
//             grid[r][c] = 0;
//             row_used[r][i] = false;
//             col_used[c][i] = false;
//         }
//     }
// }

// int main() {
//     // 初始化已知数字的占用状态
//     row_used[1][3] = col_used[1][3] = true;
//     row_used[2][3] = col_used[0][3] = true;
//     row_used[4][4] = col_used[3][4] = true;
//     row_used[4][1] = col_used[4][1] = true;

//     // 从 (0, 0) 开始搜索
//     dfs(0, 0);

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int grid[5][5]=
{
    {0,0,0,0,0},
    {0,3,0,0,0},
    {3,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,4,1}
};
bool row[5][6];
bool col[5][6];
bool check(int x,int y,int val)
{

    if(row[x][val]||col[y][val])return false;

    bool ok=1;
    grid[x][y]=val;

    if (grid[0][1] && grid[0][2] && grid[0][1] >= grid[0][2]) ok = false;
    if (grid[0][2] && grid[0][3] && grid[0][2] >= grid[0][3]) ok = false;
    if (grid[0][3] && grid[0][4] && grid[0][3] >= grid[0][4]) ok = false;
    
    // 纵向：第一行第5列 < 第二行第5列
    if (grid[0][4] && grid[1][4] && grid[0][4] >= grid[1][4]) ok = false;
    
    // 第二行的 >
    if (grid[1][2] && grid[1][3] && grid[1][2] <= grid[1][3]) ok = false;
    
    // 第三行的 >
    if (grid[2][3] && grid[2][4] && grid[2][3] <= grid[2][4]) ok = false;
    
    // 纵向：第三行第2列 > 第四行第2列
    if (grid[2][1] && grid[3][1] && grid[2][1] <= grid[3][1]) ok = false;

    grid[x][y]=0;
    return ok;
}
void dfs(int x,int y)
{
    if(x>4)
    {
        for(int i=0;i<=4;i++)
        {
            for(int j=0;j<=4;j++)cout<<grid[i][j];
        }
        return;
    }

    int next_x,next_y;

    if(y==4)next_x=x+1,next_y=0;
    else next_x=x,next_y=y+1;

    if(grid[x][y])//当前位置已经放置好数字了
    {
        dfs(next_x,next_y);
        return ;
    }

    //放数字
    for(int i=1;i<=5;i++)
    {
        if(check(x,y,i))
        {
            grid[x][y]=i;
            row[x][i]=1;
            col[y][i]=1;

            dfs(next_x,next_y);

            grid[x][y]=0;
            row[x][i]=0;
            col[y][i]=0;
        }
    }
}
int main()
{
    row[2][3]=col[0][3]=1;
    row[1][3]=col[1][3]=1;
    row[4][4]=col[3][4]=1;
    row[4][1]=col[4][1]=1;

    dfs(0,0);
    return 0;
}