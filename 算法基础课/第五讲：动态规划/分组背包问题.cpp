// #include<bits/stdc++.h>
// using namespace std;

// const int MAX_V = 105;
// int dp[MAX_V]; 

// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
//     int N, V;
//     cin >> N >> V;
    
//     for(int i = 1; i <= N; i++) // 遍历每一组
//     {
//         int S;
//         cin >> S;
        
//         // 临时存储当前组内所有物品的体积和价值
//         vector<int> v(S + 1), w(S + 1);
//         for(int k = 1; k <= S; k++)
//         {
//             cin >> v[k] >> w[k];
//         }
        
//         // 分组背包核心逻辑
//         // 1. 倒序遍历背包容量 j
//         for(int j = V; j >= 0; j--) 
//         {
//             // 2. 遍历组内每一个物品 k (尝试在这个容量下选谁最划算)
//             for(int k = 1; k <= S; k++) 
//             {
//                 if(j >= v[k]) 
//                 {
//                     dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
//                 }
//             }
//         }
//     }
    
//     cout << dp[V] << "\n";
    
//     return 0;
// }

//分组背包的核心特征是：物品被划分为若干组，每组中的物品互相冲突，你最多只能从每一组中挑选一件物品放入背包。
//每组看出一个 01 背包
#include<bits/stdc++.h>
using namespace std;
const int M=1e4+11;
const int N= 102;
int w[N],v[N];
int dp[M];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,V;cin>>n>>V;
    for(int i=1;i<=n;i++)//遍历组
    {
        int s;cin>>s;
        for(int j=1;j<=s;j++)
        {
            cin>>v[j]>>w[j];
        }

        //每组挑一个
        for(int j=V;j>=0;j--)
        {
            for(int k=1;k<=s;k++)
            {
                if(j>=v[k])
                {
                    dp[j]=max(dp[j],dp[j-v[k]]+w[k]);
                }
            }
        }
    }
    cout<<dp[V];
    return 0;
}