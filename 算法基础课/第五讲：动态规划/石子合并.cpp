//只能合并相邻的
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     priority_queue<int,vector<int>,greater<int>>q;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         q.push(x);
//     }
//     int ans=0;
//     while(q.size()>1)
//     {
//         int x=q.top();q.pop();
//         int y=q.top();q.pop();
//         ans+=(x+y);
//         q.push(x+y);
//     }
//     cout<<ans;
//     return 0;
// }

//状态怎么定义呢
//f[i[[k]代表合成[i~k]这个区间的最小代价，f[k+1][j]代表合成[k+1,j]区间的最小代价
// f[i][k] + f[k+1][j]代表的是合成[i~k]这一堆石子和合成[k+1~j]这一堆石子代价
// s[j]-s[i-1]代表的合并[i~k] [k+1~j] 这两堆石子的代价
// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 307;

// int a[N], s[N];
// int f[N][N];

// int main() {
//     int n;
//     cin >> n;

//     for (int i = 1; i <= n; i ++) {
//         cin >> a[i];
//         s[i] += s[i - 1] + a[i];
//     }

//     memset(f, 0x3f, sizeof f);
//     // 区间 DP 枚举套路：长度+左端点 
//     for (int len = 1; len <= n; len ++) { // len表示[i, j]的元素个数
//         for (int i = 1; i + len - 1 <= n; i ++) {
//             int j = i + len - 1; // 自动得到右端点
//             if (len == 1) {
//                 f[i][j] = 0;  // 边界初始化
//                 continue;
//             }

//             for (int k = i; k <= j - 1; k ++) { // 必须满足k + 1 <= j
//                 f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
//             }
//         }
//     }

//     cout << f[1][n] << endl;


//     return 0;
// }

//方法 2：记忆化搜索
// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 307;

// int a[N], s[N];
// int f[N][N];

// // 记忆化搜索：dp的记忆化递归实现
// int dp(int i, int j) {
//     if (i == j) return 0; // 判断边界
//     int &v = f[i][j];

//     if (v != -1) return v;

//     v = 1e8;
//     for (int k = i; k <= j - 1; k ++)
//         v = min(v, dp(i, k) + dp(k + 1, j) + s[j] - s[i - 1]);

//     return v;
// }

// int main() {
//     int n;
//     cin >> n;

//     for (int i = 1; i <= n; i ++) {
//         cin >> a[i];
//         s[i] += s[i - 1] + a[i];
//     }

//     memset(f, -1, sizeof f);

//     cout << dp(1, n) << endl;


//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=302;
// int f[N][N];//f[i][j]=f[i][k]+f[k+1][j]//i~j区间内最小的代价
// int n;
// int a[N];
// int prefix[N];//快速得到某一区间内的和
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     memset(f,0x3f,sizeof f);
//     for(int i=1;i<=n;i++)f[i][i]=0;//不用合并
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         prefix[i]=prefix[i-1]+a[i];
//     }

//     //区间 DP 的核心物理法则是：大区间的答案，依赖于小区间的答案。所以我们绝对不能按坐标的“行”和“列”去遍历，而是必须按区间的长度 (len) 从小到大进行遍历！你要先算出所有长度为 2 的区间，再算所有长度为 3 的区间……直到算出长度为 $n$ 的终极区间。
//     // for(int i=1;i<=n;i++)
//     // {
//     //     for(int j=i;j<=n;j++)
//     //     {
//     //         for(int k=i;k<=j-1;k++)
//     //         {
//     //             f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+prefix[j]-prefix[i-1]);
//     //         }
//     //     }
//     // }

//     //必须这样写 记住区间 DP 大区间的更新需要小区间
//     for(int len=1;len<=n;len++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             int j=i+len-1;
//             for(int k=i;k<=j-1;k++)
//             {
//                 f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+prefix[j]-prefix[i-1]);
//             }
//         }
//     }
//     cout<<f[1][n];
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
int a[N],prefix[N];
int mem[N][N];//备忘录数组，记录区间l 到r的最小代价
int n;
int dp(int l,int r)
{
    if(l==r)return 0;
    if(mem[l][r]!=-1)return mem[l][r];
    int min_val=1e18;
    for(int k=l;k<=r-1;k++)
    {
        int cost=dp(l,k)+dp(k+1,r)+prefix[r]-prefix[l-1];
        min_val=min(cost,min_val);
    }
    return mem[l][r]=min_val;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    memset(mem,-1,sizeof mem);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }
    int res=dp(1,n);
    cout<<res;
    return 0;
}