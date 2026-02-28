//贪心肯定不行 比如6 4 4 1  V=8
// 贪心结果为1
//dfs+记忆化搜索
// #include<bits/stdc++.h>
// using namespace std;
// int v,n;
// const int N=31;
// int m[N];
// int ans;
// const int M=20001;
// int mem[N][M];
// int dfs(int x,int spv)
// {
//     if(mem[x][spv])return mem[x][spv];
//     if(x<1)
//     {
//         return spv;
//     }
//     //可装可不装
//     if(spv>=m[x])
//     return mem[x][spv]=min(dfs(x-1,spv),dfs(x-1,spv-m[x]));
//     else 
//     return mem[x][spv]=dfs(x-1,spv);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>v>>n;
//     for(int i=1;i<=n;i++)cin>>m[i];
//     int res=dfs(n,v);
//     cout<<res;
//     return 0;
// }

// //dp的方法不会
// #include<bits/stdc++.h>
// using namespace std;
// int v,n;
// const int N=31;
// int m[N];
// int ans;
// const int M=20001;
// //int dp[N][M];
// int dp[M];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>v>>n;
//     for(int i=1;i<=n;i++)cin>>m[i];

//     //这两行代码是错误的
//     // memset(dp,0x3f,sizeof dp);
//     // dp[0][0]=1;


//     // for(int i=1;i<=n;i++)
//     // {
//     //     dp[i][0]=0;//注意这里的初始话 主要是这里出问题了
//     // }
    
//     //看似不能使用 01 背包来做，但我们可以把物品的体积当成重量和价值。这样就转化成了 01 背包问题啦！
//     // for(int i=1;i<=n;i++)
//     // {
//     //     for(int j=0;j<=v;j++)
//     //     {
//     //         if(j<m[i])
//     //         {
//     //             dp[i][j]=dp[i-1][j];
//     //         }
//     //         else
//     //         {
//     //             dp[i][j]=max(dp[i-1][j],dp[i-1][j-m[i]]+m[i]);
//     //         }
//     //     }
//     // }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=v;j>=m[i];j--)
//         {
//             dp[j]=max(dp[j],dp[j-m[i]]+m[i]);
//         }
//     }
//     cout<<v-dp[v];
//     //cout<<v-dp[n][v];
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=200002;
// int m[N],n,v;
// int dp[N];//体积不超过v时的最大价值（体积）
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>v>>n;
//     for(int i=1;i<=n;i++)cin>>m[i];

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=v;j>=0;j--)
//         {
//             if(j>=m[i])
//             dp[j]=max(dp[j],dp[j-m[i]]+m[i]);
//         }
//     }
//     cout<<v-dp[v];
//     return 0;
// }



//dfs,上面的那个dfs更聪明点
// #include<bits/stdc++.h>
// using namespace std;
// const int N=40;
// int v,n;
// int a[N];
// bool st[N];
// int ans=0x3f3f3f3f;
// //可以加上记忆化搜索
// void dfs(int x,int val)
// {
//     if(x>n)
//     {
//         ans=min(ans,v-val);
//         return;
//     }

//     if(val+a[x]<=v)
//     {
//         dfs(x+1,val+a[x]);


//         dfs(x+1,val);
//     }
//     else
//     {
//         dfs(x+1,val);
//     }
//     return;

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>v>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     dfs(1,0);
//     cout<<ans;
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int v,n;
// const int N=20003;
// int dp[N];//dp[i]：不超过v的最大体积
// //0-1背包问题，代价是体积，价值也是体积
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>v>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=v;j>=0;j--)
//         {
//             if(j>=a[i])
//             {
//                 dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
//             }
//         }
//     }
//     cout<<v-dp[v];
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=2e4+66;
int v,n;
int a[N],dp[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>v>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=0;j--)
        {
            if(j>=a[i])
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    cout<<v-dp[v];
    return 0;
}