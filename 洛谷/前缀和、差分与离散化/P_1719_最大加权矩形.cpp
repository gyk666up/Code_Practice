// //二维前缀和
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=200;
// int a[N][N];
// int prefix[N][N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)cin>>a[i][j];
//     }

//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
//         }
//     }
//     //左上角的坐标为（x1，y1）右下角的坐标（x2，y2）
//     //求所有的矩形的可能行
//     for(int x1=1;x1<=n;x1++)
//     {
//         for(int y1=1;y1<=n;y1++)
//         {
//             for(int x2=x1;x2<=n;x2++)
//             {
//                 for(int y2=y1;y2<=n;y2++)
//                 {
//                     //这里容易写错！
//                     //int temp=prefix[x2][y2]-(prefix[x1][y2]+prefix[x2][y1]-prefix[x1][y1]);
//                     //坐标指的是小方格的坐标，而不是线的坐标
//                     int temp=prefix[x2][y2]-(prefix[x1-1][y2]+prefix[x2][y1-1]-prefix[x1-1][y1-1]);
//                     ans=max(ans,temp);
//                 }
//             }
//         }
//     }
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=122;
int n;
int a[N][N];
int prefix[N][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
        }
    }

    int ans=0;
    //枚举矩形
    for(int x1=1;x1<=n;x1++)
    {
        for(int y1=1;y1<=n;y1++)
        {
            for(int x2=x1;x2<=n;x2++)
            {
                for(int y2=y1;y2<=n;y2++)
                {
                    int temp=prefix[x2][y2]+prefix[x1-1][y1-1]-prefix[x2][y1-1]-prefix[x1-1][y2];
                    ans=max(ans,temp);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

