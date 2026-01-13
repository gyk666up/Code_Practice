// // //不会！组合的代码不会写

// // //最简单的写法：不过只能得到很少一部分分数
// // #include<bits/stdc++.h>
// // using namespace std;
// // int t,k;
// // #define int long long
// // int ans=0;
// // int n,m;
// // // inline int ck(int x)
// // // {
// // //     if(x==0)return 1;
// // //     int sum=1;
// // //     for(int i=1;i<=x;i++)sum*=i;
// // //     return sum;
// // // }
// // // inline int C(int n,int m)
// // // {
// // //     return ck(n)/(ck(m)*ck(n-m));//组合数公式
// // // }

// // //优化版组合数计算 比之前好点 但仍存在溢出的问题
// // inline int C(int n,int m)
// // {
// //     if(m==n||m==0)return 1;
// //     if(n<m)return 0;
// //     if(n-m<m)m=n-m;

// //     long long res=1;
// //     for(int i=1;i<=m;i++)
// //     res=res*(n-m+i)/i;
// //     return res;
// // }

// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>t>>k;
// //     while(t--)
// //     {
// //         ans=0;
// //         cin>>n>>m;
// //         for(int i=0;i<=n;i++)
// //         {
// //             for(int j=0;j<=min(i,m);j++)
// //             {
// //                 if(C(i,j)%k==0)ans++;
// //             }
// //         }
// //         cout<<ans<<endl;
// //     }
// //     return 0;
// // }



// // //有两个点t了 得用二维前缀和优化
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int MAXN=2001;
// // int t,n,m;
// // long long k;
// // int C[2003][2003];//存C(n,m)模k的余数
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>t>>k;
// //     for(int i=0;i<=MAXN;i++)
// //     {
// //         for(int j=0;j<=i;j++)
// //         {
// //             if(j==0||j==i)C[i][j]=1;
// //             else C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
// //         }
// //     }
// //     while(t--)
// //     {
// //         int ans=0;
// //         cin>>n>>m;
// //         for(int i=0;i<=n;i++)
// //         {
// //             int mn=min(i,m);//避免C(i,j) i<j
// //             for(int j=0;j<=mn;j++)
// //             ans+=(C[i][j]%k==0);
// //         }cout<<ans<<'\n';
// //     }
    
// //     return 0;
// // }


// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=2000;
// // int t,n,m,k;
// // int C[2003][2003];
// // int d[2003][2003];//二维前缀和
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>t>>k;
// //     for(int i=0;i<=N;i++)
// //     {
// //         for(int j=0;j<=i;j++)
// //         {
// //             if(j==0||j==i)C[i][j]=1;
// //             else C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
// //         }
// //     }

// //     for(int i=0;i<=N;i++){
// //     for(int j=0;j<=N;j++){
// //         int curr = (j <= i && C[i][j] == 0) ? 1 : 0; // 当前位置的贡献（C[i][j]已模k，无需再模）
// //         if(i == 0 && j == 0){
// //             d[i][j] = curr; // 左上角起点，直接等于当前值
// //         } else if(i == 0){
// //             // i=0时，没有i-1行，前缀和=左边的前缀和 + 当前值
// //             d[i][j] = d[i][j-1] + curr;
// //         } else if(j == 0){
// //             // j=0时，没有j-1列，前缀和=上边的前缀和 + 当前值
// //             d[i][j] = d[i-1][j] + curr;
// //         } else {
// //             // 正常情况，套用前缀和公式
// //             if(j <= i){
// //                 d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + curr;
// //             } 
// //             else {
// //                 d[i][j] = d[i][i]; // j>i时，等同于d[i][i]
// //             }
// //         }
// //     }
// // }
// //     while(t--)
// //     {
// //         cin>>n>>m;
// //         cout<<d[n][m]<<endl;
// //     }
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// int t,k;
// const int N=2002;
// int C[2003][2003];
// int pre[2003][2003];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>t>>k;
//     for(int i=0;i<N;i++)
//     {
//         for(int j=0;j<=i;j++)
//         {
//             if(i==j||j==0)C[i][j]=1;
//             else
//             {
//                 C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
//             }
//         }
//     }
//     for(int i=0;i<N;i++)
//     {
//         for(int j=0;j<N;j++)
//         {
//             int curr=(j<=i&&C[i][j]==0?1:0);
//             if(i==0&&j==0)
//             pre[i][j]=curr;
//             else if(i==0)
//             pre[i][j]=pre[i][j-1]+curr;
//             else if(j==0)
//             pre[i][j]=pre[i-1][j]+curr;
//             else 
//             {
//                 if(j<=i)
//                 pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+curr;
//                 else
//                 {
//                     pre[i][j]=pre[i][i];
//                 }
//             }

//         }
//     }
//     while(t--)
//     {
//         int n,m;cin>>n>>m;
//         cout<<pre[n][min(n,m)]<<endl;
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=2005;
// int c[N][N];//C(i,j)%k的余数
// int pre[N][N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t,k;cin>>t>>k;
//     for(int i=0;i<=2000;i++)
//     {
//         for(int j=0;j<=i;j++)
//         {
//             if(i==j||j==0)c[i][j]=1;
//             else c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
//         }
//     }
//     for(int i=0;i<=2000;i++)
//     {
//         for(int j=0;j<=2000;j++)
//         {
//             // int curr=((i==j||j==0)&&j<=i);
//             // if(i==j||j==0&&j<=i)curr=((c[i][j]==0)?1:0);
//             //着重看一下这一行代码 ，上面的这两行代码不对
//             int curr=(j<=i&&c[i][j]==0)?1:0;
//             if(i==0&&j==0)pre[i][j]=curr;
//             else if(i==0)pre[i][j]=pre[i][j-1]+curr;
//             else if(j==0)pre[i][j]=pre[i-1][j]+curr;
//             else 
//             {
//                 pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+curr;
//             }
//             if(i<=j)
//             pre[i][j]=pre[i][i];
//         }
//     }
//     while(t--)
//     {
//         int n,m;cin>>n>>m;
//         cout<<pre[n][min(n,m)]<<endl;
//     }
//     return 0;
// }











#include<bits/stdc++.h>
using namespace std;
const int N=2002;
int c[N][N];
int b[N][N];
int prefix[N][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,k;cin>>t>>k;
    for(int i=0;i<=2000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)//这里别写错了是j==0
            {
                c[i][j]=1%k;
                if(c[i][j]==0)b[i][j]=1;
            }
            else
            {
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
                if(c[i][j]==0)b[i][j]=1;
            }
            // if(c[i][j]==0)b[i][j]=1;
            // else b[i][j]=0;
        }
    }
    for(int i=0;i<=2000;i++)
    {
        for(int j=0;j<=2000;j++)
        {
            prefix[i][j]=b[i][j];
            if(i)prefix[i][j]+=prefix[i-1][j];
            if(j)prefix[i][j]+=prefix[i][j-1];
            if(i&&j)prefix[i][j]-=prefix[i-1][j-1];
        }
    }
    while(t--)
    {
        int n,m;cin>>n>>m;
        cout<<prefix[n][m]<<endl;;
    }
    return 0;
}