// #include<bits/stdc++.h>
// using namespace std;
// const int N=1002;
// int m[N],w[N];
// int n,v;
// int dfs(int x,int cost)
// {
//     // if(x>n)
//     // {
//     //     return 0; 
//     // }
//     // if(spv<m[x])return dfs(x+1,spv);
//     // else return max(dfs(x+1,spv-m[x])+w[x],dfs(x+1,spv));

//     if(x>n)
//     {
//         return 0;
//     }
//     if(cost+m[x]<=v)return max(dfs(x+1,cost+m[x])+w[x],dfs(x+1,cost));
//     else return dfs(x+1,cost);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>v;
//     for(int i=1;i<=n;i++)cin>>m[i]>>w[i];

//     两张暴力dfs的方式
//     //int res=dfs(1,m);
//     int res=dfs(1,0);
//     cout<<res;
//     return 0;
// }

// //上面的纯暴力t了-》记忆化搜索
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1002;
// int m[N],w[N];
// int mem[N][N];//mem[i][j]当进行到第i个物品 剩余体积为j时的价值
// int n,v;
// int dfs(int x,int spv)
// {
//     if(mem[x][spv])return mem[x][spv];
//     if(x>n)
//     {
//         return 0;
//     }
    
//     if(spv<m[x])return mem[x][spv]=dfs(x+1,spv);
//     else return mem[x][spv]=max(dfs(x+1,spv-m[x])+w[x],dfs(x+1,spv));

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
// const int N=1002;
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
//         for(int j=1;j<=v;j++)
//         {
//             if(j<m[i])dp[i][j]=dp[i-1][j];
//             else
//             {
//                 dp[i][j]=max(dp[i-1][j],dp[i-1][j-m[i]]+w[i]);
//             }
//         }
//     }
//     cout<<dp[n][v];
//     return 0;
// }

//一维dp
#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int m[N],w[N];
int dp[N];
int n,v;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>v;
    for(int i=1;i<=n;i++)cin>>m[i]>>w[i];

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=v;j>=m[i];j--)
    //     {
    //         dp[j]=max(dp[j],dp[j-m[i]]+w[i]);
    //     }
    // }

    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=0;j--)
        {
            if(j>=m[i])
            dp[j]=max(dp[j],dp[j-m[i]]+w[i]);
        }
    }
    cout<<dp[v];
    return 0;
}