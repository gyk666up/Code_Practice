// //Flyod变形
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=105;
// int a[N][N],dist[N][N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
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
//                 //dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                 dist[i][j] |= (dist[i][k] && dist[k][j]);//只要能到达就行
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)cout<<dist[i][j]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }
