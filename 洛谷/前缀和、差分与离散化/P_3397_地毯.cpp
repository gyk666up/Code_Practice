<<<<<<< HEAD
// // // //二维差分
// // // //没掌握好！
// // // // #include<bits/stdc++.h>
// // // // using namespace std;
// // // // const int N=1e3+11;
// // // // int a[N][N];
// // // // int diff[N][N];
// // // // int main()
// // // // {
// // // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // // //     int n,m;cin>>n>>m;
// // // //     for(int i=1;i<=n;i++)
// // // //     {
// // // //         for(int j=1;j<=n;j++)
// // // //         {
// // // //             cin>>a[i][j];
// // // //         }
// // // //     }
// // // //     return 0;
// // // // }


// // // //我去 这道题的数据有点水 思维千万不要固化
=======
// // //二维差分
// // //没掌握好！
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // const int N=1e3+11;
// // // int a[N][N];
<<<<<<< HEAD
// // // int n,m;
// // // int main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     cin>>n>>m;
// // //     for(int i=1;i<=m;i++)
// // //     {
// // //         int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
// // //         for(int j=x1;j<=x2;j++)
// // //         {
// // //             for(int k=y1;k<=y2;k++)a[j][k]++;
// // //         }
// // //     }

// // //     for(int i=1;i<=n;i++)
// // //     {
// // //         for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
// // //         cout<<endl;
// // //     }

=======
// // // int diff[N][N];
// // // int main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     int n,m;cin>>n>>m;
// // //     for(int i=1;i<=n;i++)
// // //     {
// // //         for(int j=1;j<=n;j++)
// // //         {
// // //             cin>>a[i][j];
// // //         }
// // //     }
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
// // //     return 0;
// // // }


<<<<<<< HEAD

// // //差分的做法
// // //原矩阵是差分矩阵的前缀和
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1e3+100;
// // int diff[N][N];
// // int a[N][N];
// // int n,m;
// // void insert(int x1,int y1,int x2,int y2)
// // {
// //     diff[x1][y1]++;
// //     diff[x1][y2+1]--;
// //     diff[x2+1][y1]--;
// //     diff[x2+1][y2+1]++;
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

=======
// // //我去 这道题的数据有点水 思维千万不要固化
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1e3+11;
// // int a[N][N];
// // int n,m;
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
// //     cin>>n>>m;
// //     for(int i=1;i<=m;i++)
// //     {
// //         int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
<<<<<<< HEAD
// //         insert(x1,y1,x2,y2);
// //     }
// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=1;j<=n;j++)
// //         {
// //             a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+diff[i][j];
// //             cout<<a[i][j]<<" ";
// //         }
// //         cout<<endl;
// //     }
    
=======
// //         for(int j=x1;j<=x2;j++)
// //         {
// //             for(int k=y1;k<=y2;k++)a[j][k]++;
// //         }
// //     }

// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
// //         cout<<endl;
// //     }

>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
// //     return 0;
// // }



<<<<<<< HEAD

// #include<bits/stdc++.h>
// using namespace std;
// const int N=1002;
// int a[N][N];
// int diff[N][N];
// void insert(int x1,int y1,int x2,int y2)
// {
//     diff[x1][y1]++;
//     diff[x2+1][y2+1]++;
//     diff[x2+1][y1]--;
//     diff[x1][y2+1]--;

=======
// //差分的做法
// //原矩阵是差分矩阵的前缀和
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+100;
// int diff[N][N];
// int a[N][N];
// int n,m;
// void insert(int x1,int y1,int x2,int y2)
// {
//     diff[x1][y1]++;
//     diff[x1][y2+1]--;
//     diff[x2+1][y1]--;
//     diff[x2+1][y2+1]++;
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
<<<<<<< HEAD
//     int n,m;cin>>n>>m;
//     // while(m--)
//     // {
//     //     int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
//     //     for(int i=x1;i<=x2;i++)
//     //     {
//     //         for(int j=y1;j<=y2;j++)a[i][j]++;
//     //     }
//     // }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
//     //     cout<<endl;
//     // }

//     while(m--)
=======

//     cin>>n>>m;
//     for(int i=1;i<=m;i++)
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
//     {
//         int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
//         insert(x1,y1,x2,y2);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
<<<<<<< HEAD
//             //看出prefix[i][j]
=======
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
//             a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+diff[i][j];
//             cout<<a[i][j]<<" ";
//         }
//         cout<<endl;
//     }
<<<<<<< HEAD
=======
    
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
//     return 0;
// }



<<<<<<< HEAD
//2025/12/19  二维差分不太熟
=======

>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int a[N][N];
int diff[N][N];
void insert(int x1,int y1,int x2,int y2)
{
    diff[x1][y1]++;
    diff[x2+1][y2+1]++;
    diff[x2+1][y1]--;
    diff[x1][y2+1]--;
<<<<<<< HEAD
=======

>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
<<<<<<< HEAD
=======
    // while(m--)
    // {
    //     int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    //     for(int i=x1;i<=x2;i++)
    //     {
    //         for(int j=y1;j<=y2;j++)a[i][j]++;
    //     }
    // }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }

>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
    while(m--)
    {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        insert(x1,y1,x2,y2);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
<<<<<<< HEAD
=======
            //看出prefix[i][j]
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+diff[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
<<<<<<< HEAD

=======
>>>>>>> 910700d7e6c08f10eaba22dc51f3fd35dfed6e15
    return 0;
}