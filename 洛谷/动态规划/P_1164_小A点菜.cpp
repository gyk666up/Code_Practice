// // //0,1背包
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long 
// // const int N=200;
// // int a[N];
// // int n,m;
// // int ans=0;
// // void dfs(int x,int cost)
// // {
// //     if(x>n)
// //     {
// //         if(cost==m)ans++;
// //         return;
// //     }

// //     //吃 不吃
// //     dfs(x+1,cost);

// //     dfs(x+1,cost+a[x]);
// // }
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)cin>>a[i];
// //     dfs(1,0);
// //     cout<<ans;
// //     return 0;
// // }



// // //记忆化搜索
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long 
// // const int N=200;
// // const int Maxm=10001;
// // int a[N];
// // int n,m;
// // int ans=0;
// // int mem[N][Maxm];
// // int dfs(int x,int cost)
// // {
// //     if(cost>m)return 0;//剪枝 必须 否则mem[x][cost]会访问非法下标
// //     if(mem[x][cost]!=-1)return mem[x][cost];
// //     if(x>n)
// //     {
// //         if(cost==m)
// //         return 1;
// //         else return 0;//!!!
// //     }

// //     mem[x][cost]=dfs(x+1,cost)+dfs(x+1,cost+a[x]);

// //     return mem[x][cost];
// // }
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)cin>>a[i];
// //     memset(mem,-1,sizeof mem);
// //     cout<<dfs(1,0);
    
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 
// const int N=200;
// const int Maxm=10002;
// int a[N];
// int n,m;
// int ans;
// int dp[Maxm];//凑够i元 有多少种方法
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dp[0]=1;
//     //纸币2
//     //int n,m; 跟顺序有关
//     // for(int i=0;i<=m;i++)
//     // {
//     //     for(int j=1;j<=n;j++)
//     //     {
//     //         if(i>=a[j])
//     //         dp[i]+=dp[i-a[j]];
//     //     }
//     // }

//     dp[0] = 1;
//     for (int j = 1; j <= n; j++)        // 枚举物品
//     {
//         for (int i = m; i >= a[j]; i--) // 倒序
//         {
//             dp[i] += dp[i - a[j]];
//         }
//     }

//     cout<<dp[m];
//     return 0;
// }

//0-1背包
#include<bits/stdc++.h>
using namespace std;
const int N=10002;
#define int long long
int n,m;
int dp[N];
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=a[i];j--)
        dp[j]+=dp[j-a[i]];
    }
    cout<<dp[m];
    return 0;
}