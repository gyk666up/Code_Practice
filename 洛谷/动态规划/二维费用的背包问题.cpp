// #include<bits/stdc++.h>
// using namespace std;
// const int Q=1002;
// int v[Q],m[Q],w[Q];
// int N,V,M;
// int dfs(int x,int spv,int spm )
// {
//     if(x>N)return 0;

//     if(spv>=v[x]&&spm>=m[x])return max(dfs(x+1,spv-v[x],spm-m[x])+w[x],dfs(x+1,spv,spm));
//     else return dfs(x+1,spv,spm);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>N>>V>>M;
//     for(int i=1;i<=N;i++)
//     {
//         cin>>v[i]>>m[i]>>w[i];
//     }
//     int res=dfs(1,V,M);
//     cout<<res;
//     return 0;
// }

// //记忆化搜索
// #include<bits/stdc++.h>
// using namespace std;
// int N,V,M;
// int v[1002],m[1025],w[1025];//注意数组的大小问题
// int mem[1002][102][102];
// int dfs(int x,int spv,int spm)
// {
//     if(mem[x][spv][spm]!=-1)return mem[x][spv][spm];
//     if(x>N)return 0;

//     if(spv>=v[x]&&spm>=m[x])
//     return mem[x][spv][spm]=max(dfs(x+1,spv,spm),dfs(x+1,spv-v[x],spm-m[x])+w[x]);
//     else
//     return mem[x][spv][spm]=dfs(x+1,spv,spm);
    
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>N>>V>>M;
//     memset(mem,-1,sizeof mem);
//     for(int i=1;i<=N;i++)cin>>v[i]>>m[i]>>w[i];

//     int res=dfs(1,V,M);
//     cout<<res;
//     return 0;
// }


// //三维dp
// #include<bits/stdc++.h>
// using namespace std;
// int N,V,M;
// int v[1002],m[1025],w[1025];//注意数组的大小问题
// int dp[1002][102][102];

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>N>>V>>M;
//     for(int i=1;i<=N;i++)cin>>v[i]>>m[i]>>w[i];
//     for(int i=1;i<=N;i++)
//     {
//         for(int j=0;j<=V;j++)
//         {
//             for(int k=0;k<=M;k++)
//             {
//                 if(k>=m[i]&&j>=v[i])
//                 dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-v[i]][k-m[i]]+w[i]);
//                 else 
//                 dp[i][j][k]=dp[i-1][j][k];
//             }
//         }
//     }
//     cout<<dp[N][V][M];
//     return 0;
// }

//二维dp
#include<bits/stdc++.h>
using namespace std;
int N,V,M;
int v[1002],m[1025],w[1025];//注意数组的大小问题
int dp[102][102];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>N>>V>>M;
    for(int i=1;i<=N;i++)cin>>v[i]>>m[i]>>w[i];
    for(int i=1;i<=N;i++)
    {
        for(int j=V;j>=0;j--)
        {
            for(int k=M;k>=0;k--)
            {
                if(k>=m[i]&&j>=v[i])
                dp[j][k]=max(dp[j][k],dp[j-v[i]][k-m[i]]+w[i]);
            }
        }
    }
    cout<<dp[V][M];
    return 0;
}