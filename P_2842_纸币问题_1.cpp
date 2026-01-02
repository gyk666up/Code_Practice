// //第一想法是暴力dfs
//t了几个点
// #include<bits/stdc++.h>
// using namespace std;
// int n,w;
// const int N=1e3+11;
// int a[N];
// int ans=0x3f3f3f3f;
// bool st[N];
// void dfs(int x,int cnt,int sum)
// {
//     if(sum>w||cnt>ans)return;
//     if(x>n)
//     {
//         if(sum==w)
//         {
//             ans=min(ans,cnt);
//         }
//         return ;
//     }

//     st[x]=1;
//     dfs(x,cnt+1,sum+a[x]);//注意这里，题目中说的是每一张纸币有无限张，因此下一次还可以选

//     st[x]=0;
//     dfs(x+1,cnt,sum);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];
    
//     dfs(1,0,0);
//     cout<<ans;
//     return 0;
// }


//不会写
// #include<bits/stdc++.h>
// using namespace std;
// int n,w;
// const int N=1e4+11;
// const int M=1e3+11;
// int a[N];
// int dp[M][N];//dp[i][j]选i个j元的方案树
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     return 0;
// }


//经典的完全背包（最少硬币数）问题
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+11;
int dp[N];//dp[j]=凑出金额j所需的最少纸币数
int a[N];
int n,w;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>w;
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i];j<=w;j++)
        dp[j]=min(dp[j],dp[j-a[i]]+1);
        //dp[j - a[i]]：先凑出 j - a[i],再用一张 a[i] 的纸币,所以张数 +1
    }
    cout<<dp[w]<<"\n";
    return 0;
}