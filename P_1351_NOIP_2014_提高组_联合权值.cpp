//完全自己的思路 是正确的 不过会超时
// #include<bits/stdc++.h>
// using namespace std;
// //统计每个点距离2的其他点有哪些
// const int N=2e5+11;
// const int p=10007;
// vector<int>g[N];
// vector<int>v[N];//v[i]记录距离i点为2的点
// int dist[N];
// int w[N];
// bool st[N];
// int n;
// void bfs(int x)
// {
//     dist[x]=0;
//     st[x]=1;
//     queue<int>q;
//     q.push(x);
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         for(int i=0;i<g[x].size();i++)
//         {
//             int y=g[x][i];
//             if(!st[y])
//             {
//                 dist[y]=dist[x]+1;
//                 st[y]=1;
//                 q.push(y);
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     for(int i=1;i<=n;i++)cin>>w[i];
//     for(int i=1;i<=n;i++)
//     {
//         memset(dist,0,sizeof dist);
//         memset(st,0,sizeof st);
//         bfs(i);
//         for(int j=1;j<=n;j++)
//         {
//              if(dist[j]==2)v[i].push_back(j);
//             //cout<<dist[j]<<" ";
//         }
//         //cout<<endl;
//     }
//     int max_ans=0,ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j:v[i])
//         {
//             int temp=w[i]*w[j];
//             max_ans=max(max_ans,temp);
//             ans+=temp;
//             ans%=p;
//             //cout<<<<" ";
//         }//cout<<endl;
//     }
//     cout<<max_ans<<" "<<ans;
//     return 0;
// }



// u 和 v 是同一个点 x 的两个不同邻居
// 所以问题就变成了：
// 👉 枚举每个点 x，把它的所有邻居两两配对

#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
const int N = 200000 + 5;

vector<int> g[N];
int w[N];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        cin >> w[i];

    long long ans_sum = 0;
    long long ans_max = 0;

    for(int x = 1; x <= n; x++)
    {
        long long sum = 0, sum2 = 0;
        int mx1 = 0, mx2 = 0;

        for(int v : g[x])
        {
            int val = w[v];
            sum += val;
            //最大权值 mx1、次大权值 mx2
            sum2 += 1LL * val * val;

            if(val > mx1)
            {
                mx2 = mx1;
                mx1 = val;
            }
            else if(val > mx2)
            {
                mx2 = val;
            }
        }

        数学化简（重点）
        // 更新总和（有序点对）
        ans_sum = (ans_sum + (sum * sum - sum2) % MOD) % MOD;

        // 更新最大值
        if(mx2 > 0)
            ans_max = max(ans_max, 1LL * mx1 * mx2);
    }

    cout << ans_max << " " << ans_sum % MOD << "\n";
    return 0;
}
