// //我们刚刚讨论过的“最短编辑距离”的批量应用版。
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// const int N = 1005;
// string s[N];
// // 字符串长度最大为 10，DP 数组开到 15 绰绰有余
// int dp[15][15]; 

// // 封装最短编辑距离的计算过程
// int edit_distance(string a, string b) 
// {
//     int la = a.size() - 1; // 减去占位符的长度
//     int lb = b.size() - 1;
    
//     // 初始化边界
//     for(int i = 0; i <= la; i++) dp[i][0] = i;
//     for(int j = 0; j <= lb; j++) dp[0][j] = j;
    
//     // 状态转移
//     for(int i = 1; i <= la; i++) 
//     {
//         for(int j = 1; j <= lb; j++) 
//         {
//             if(a[i] == b[j]) 
//             {
//                 dp[i][j] = dp[i-1][j-1];
//             } 
//             else 
//             {
//                 dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
//             }
//         }
//     }
//     return dp[la][lb];
// }

// signed main() 
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
//     int n, m;
//     if (!(cin >> n >> m)) return 0;
    
//     // 读入 n 个字符串，并在前面加空格占位
//     for(int i = 1; i <= n; i++) 
//     {
//         cin >> s[i];
//         s[i] = " " + s[i];
//     }
    
//     // 处理 m 次询问
//     while(m--) 
//     {
//         string q;
//         int limit;
//         cin >> q >> limit;
//         q = " " + q;
        
//         int res = 0;
//         // 遍历 n 个原串进行对比
//         for(int i = 1; i <= n; i++) 
//         {
//             if(edit_distance(s[i], q) <= limit) 
//             {
//                 res++;
//             }
//         }
//         cout << res << "\n";
//     }
    
//     return 0;
// }


// //t 了 如果 const int N=1002 开的太大的话

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// // const int N=1002;
// const int N=12;
// int dp[N][N];
// int n,m;
// string s[1002];
// int is_judge(string a,string b)
// {
//     memset(dp,0,sizeof dp);
//     a=" "+a;
//     b=" "+b;
//     int n=a.size();int m=b.size();

//     for(int i=1;i<=n;i++)dp[i][0]=i;//删去
//     for(int i=1;i<=m;i++)dp[0][i]=i;//插入

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             if(a[i]==b[j])
//             {
//                 dp[i][j]=dp[i-1][j-1];
//             }
//             else
//             {
//                 dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
//             }
//         }
//     }
//     return dp[n][m];
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>s[i];
//     while(m--)
//     {
//         string target_;cin>>target_;
//         int x;cin>>x;
//         int res=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(is_judge(s[i],target_)<=x)res++;
//         }
//         cout<<res<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=1002;
string s[N];
int dp[N][N];
int is_judge(string a,string b)
{
    a=" "+a;//注意这两行初始化
    b=" "+b;
    //初始化
    int n=a.size(),m=b.size();
    for(int i=0;i<=n;i++)dp[i][0]=i;//只能删去
    for(int i=0;i<=m;i++)dp[0][i]=i;//只能插入

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }
        }
    }
    return dp[n][m];
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    while(m--)
    {
        string target_;cin>>target_;
        int x;cin>>x;
        int res=0;
        for(int i=1;i<=n;i++)
        if(is_judge(s[i],target_)<=x)res++;
        cout<<res<<endl;
    }
    return 0;
}