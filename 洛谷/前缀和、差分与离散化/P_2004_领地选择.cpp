// #include<bits/stdc++.h>
// using namespace std;
// //数据得开到long long
// #define int long long
// const int N=1e3+11;
// int a[N][N];
// int prefix[N][N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m,c;cin>>n>>m>>c;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             cin>>a[i][j];
//             prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]+a[i][j]-prefix[i-1][j-1];
//         }
//     }
//     //枚举左上角的坐标
//     int best_i=-1,best_j=-1;//记录最好的左上角坐标
//     int ans=0;

//     //这个四重循环并不是枚举所有可能的正方形 对于一个正方形只要左上角的坐标确定了 右下角的坐标也确定的
//     // for(int x1=1;x1<=n;x1++)
//     // {
//     //     for(int y1=1;y1<=m;y1++)
//     //     {
//     //         for(int x2=x1+c;x2<=n;x2++)
//     //         {
//     //             for(int y2=y1+c;y2<=n;y2++)
//     //             {
//     //                 int temp=prefix[x2][y2]+prefix[x1-1][y1-1]-prefix[x2][y1-1]-prefix[x1-1][y2];
//     //                 if(temp>ans)
//     //                 {
//     //                     ans=temp;
//     //                     best_i=x1;
//     //                     best_j=y1;
//     //                 }
//     //             }
//     //         }
//     //     }
//         for(int x1=1;x1<=n;x1++)
//         {
//             int x2=x1+c-1;//注意这个的x2的值
//             if(x2>n)break;
//             for(int y1=1;y1<=m;y1++)
//             {
//                 int y2=y1+c-1;
//                 if(y2>m)break;
//                 int temp=prefix[x2][y2]+prefix[x1-1][y1-1]-prefix[x2][y1-1]-prefix[x1-1][y2];
//                 if(temp>ans)
//                 {
//                     ans=temp;
//                     best_i=x1;
//                     best_j=y1;
//                 }
//             }

//         }
//     cout<<best_i<<" "<<best_j;
//     return 0;
// }



//问题不大
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m,c;
// const int N=1e3+11;
// int a[N][N];
// int prefix[N][N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>c;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cin>>a[i][j];
//             prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
//         }
//     }

//     int ans=0;
//     int I=-1,J=-1;
//     for(int x1=1;x1<=n;x1++)
//     {
//         for(int y1=1;y1<=n;y1++)
//         {
//             int x2=x1+c-1;
//             int y2=y1+c-1;
//             if(x2>n||y2>n)break;//这行代码很重要
//             int temp=prefix[x2][y2]+prefix[x1-1][y1-1]-prefix[x1-1][y2]-prefix[x2][y1-1];
//             if(ans<temp)
//             {
//                 ans=temp;
//                 I=x1;
//                 J=y1;
//             }
//         }
//     }
//     cout<<I<<" "<<J;

//     return 0;
// }





// //注意下面的那一行代码很关键，很重要
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e3+22;
// int prefix[N][N];
// int a[N][N];
// int n,m,c;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>c;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             cin>>a[i][j];
//             prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
//         }
//     }
    
//     int ans=0;
//     int I=-1,J=-1;
//     for(int x1=1;x1<=n;x1++)
//     {
//         for(int y1=1;y1<=m;y1++)
//         {
//             int x2=x1+c-1;int y2=y1+c-1;
//             int temp=prefix[x2][y2]+prefix[x1-1][y1-1]-prefix[x2][y1-1]-prefix[x1-1][y2];
//             if(x2>n||y2>m)break;
//             if(temp>ans)
//             {
//                 ans=temp;
//                 I=x1;
//                 J=y1;
//             }
//         }
//     }
//     cout<<I<<" "<<J;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+66;
int a[N][N],prefix[N][N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,c;cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
        }
    }
    int best_i=-1,best_j=-1;
    int ans=0;
    for(int x1=1;x1<=n;x1++)
    {
        for(int y1=1;y1<=n;y1++)
        {
            int x2=x1+c-1,y2=y1+c-1;
            if(x2>n||y2>m)break;//注意这行代码
            int temp=prefix[x2][y2]+prefix[x1-1][y1-1]-prefix[x2][y1-1]-prefix[x1-1][y2];
            
            if(ans<temp)
            {
                ans=temp;
                best_i=x1,best_j=y1;
            }
        }
    }
    cout<<best_i<<" "<<best_j;
    return 0;
}