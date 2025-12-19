// //感觉应该是可以做出来的啊

// //这是排列问题并非组合问题 两者的区别在于是否有顺序
// #include<bits/stdc++.h>
// using namespace std;

// int n;
// const int N = 1e3 + 11;
// bool st[N];          // 扩大数组避免越界
// int ans = 0;
// vector<int> v[N];
// // 参数说明：
// // start：当前可选择的最小数字（确保下一个数字≥当前，避免顺序冗余）
// // sum：当前已选数字的总和
// // path：临时存储当前组合
// void dfs(int start, int sum, vector<int>& path) {
//     // 找到合法组合：和为n，加入方案列表
//     if (sum == n) {
//         ans++;
//         v[ans]=path;
//         return;
//     }
//     // 剪枝：和超过n，无需继续
//     if (sum > n) {
//         return;
//     }
//     // 关键：从start开始选择数字，而非从1开始
//     for (int i = start; i <= n-1; i++) {
//         // 额外剪枝：若当前数字+sum已超n，后续更大数字也超，直接break（因i递增）
//         if (sum + i > n) {
//             break;
//         }
//         path.push_back(i);          // 选择数字i
//         dfs(i, sum + i, path);      // 递归：下一次最小可选数字为i（允许重复选i，但不允许选更小的）
//         path.pop_back();            // 回溯：撤销选择
//     }
// }

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     cin >> n;
//     vector<int> path;  // 临时存储当前方案
//     dfs(1, 0, path);
    
//     // 输出所有方案
//     for (int i = 1; i <= ans; i++) {
//         for (int j = 0; j < v[i].size(); j++) {
//             if (j != 0) cout << "+";
//             cout << v[i][j];
//         }
//         cout << endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e3;
int ans=0;
vector<int>v[N];
void dfs(int sum,int start,vector<int>&path)
{
    if(sum==n)
    {
        ans++;
        v[ans]=(path);
        return;
    }

    if(sum>n)return;

    for(int i=start;i<=n-1;i++)
    {
        path.push_back(i);
        dfs(sum+i,i,path);
        path.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    //vector<int>path(n+1);
    vector<int>path;
    dfs(0,1,path);
     // 输出所有方案
    for (int i = 1; i <= ans; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (j != 0) cout << "+";
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}