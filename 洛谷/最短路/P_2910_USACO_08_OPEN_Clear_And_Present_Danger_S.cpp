// // //不一定相邻，该怎么通过代码来表示 想复杂了
// // #include<bits/stdc++.h>
// // using namespace std;
// // int n,m;
// // const int N=
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     return 0;
// // }

// //Floyd 做最短路的题先看范围，通过范围选择合适的算法
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1e4+11;
// int dist[102][102];
// int a[N];
// int ans=0;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=m;i++)cin>>a[i];

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)cin>>dist[i][j];
//     }
//     for(int k=1;k<=n;k++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
//             }
//         }
//     }
//     for(int i=1;i+1<=m;i++)
//     ans+=dist[a[i]][a[i+1]];
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=10002;
int dist[102][102];
int a[N];
int ans;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>dist[i][j];
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
    for(int i=1;i+1<=m;i++)ans+=dist[a[i]][a[i+1]];
    cout<<ans;
    return 0;
}