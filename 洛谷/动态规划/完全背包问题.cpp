// //暴力dfs
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1002;
// int n,v;
// int m[N],w[N];
// int dfs(int x,int spv)
// {
//     if(x>n)return 0;

//     if(spv<m[x])
//     return dfs(x+1,spv);
//     else 
//     {
//         return max(dfs(x+1,spv),dfs(x,spv-m[x])+w[x]);//下一次还可以选
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>v;
//     for(int i=1;i<=n;i++)cin>>m[i]>>w[i];

//     int res=dfs(1,v);
//     cout<<res;
//     return 0;
// }

// //记忆化搜索
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1002;
// int n,v;
// int m[N],w[N];
// int mem[N][N];
// int dfs(int x,int spv)
// {
//     if(mem[x][spv])return mem[x][spv];
//     if(x>n)return 0;

//     //注意返回值是int 得有return
//     if(spv<m[x]) return mem[x][spv]=dfs(x+1,spv);
//     else return mem[x][spv]=max(dfs(x+1,spv),dfs(x,spv-m[x])+w[x]);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>v;
//     for(int i=1;i<=n;i++)cin>>m[i]>>w[i];

//     int res=dfs(1,v);
//     cout<<res;
//     return 0; 
// }

//二维dp
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+11;
// int m[N],w[N];
// int dp[N][N];
// int n,v;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>v;
//     for(int i=1;i<=n;i++)cin>>m[i]>>w[i];

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=v;j++)
//         {
//             if(j<m[i])dp[i][j]=dp[i-1][j];
//             //// 再选一个第 i 种
//             else dp[i][j]=max(dp[i][j-m[i]]+w[i],dp[i-1][j]);
//         }
//     }
//     cout<<dp[n][v];
//     return 0;
// }


//一维
// 一维 DP 中：
// 想「重复使用当前物品」 → j 正序
// 想「当前物品只能用一次」 → j 倒序
#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int m[N],w[N];
int n,v;
int dp[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>v;
    for(int i=1;i<=n;i++)cin>>m[i]>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=v;j++)
        {
            if(j>=m[i])
            dp[j]=max(dp[j],dp[j-m[i]]+w[i]);
        }
    }
    cout<<dp[v];
    return 0;
}