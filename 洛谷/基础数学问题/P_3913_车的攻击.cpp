// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int n,k;
// // //一开始本来想开数组的但是范围N太大了 开不了 遂用map来代替
// // map<int,bool>row;
// // map<int,bool>col;
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>k;
// //     int ans=0;
// //     for(int i=0;i<k;i++)
// //     {
// //         int x,y;cin>>x>>y;
// //         if(row.count(x)==0&&col.count(y)==0)
// //         {
// //             row[x]=col[y]=1;
// //             ans+=2*n;
// //             ans--;
// //         }
// //         if(row.count(x)==0&&col.count(y)!=0)
// //         {
// //             //没被标记过
// //             row[x]=1;
// //             ans+=n-1;
// //         }
// //         if(col.count(x)==0&&row.count(x)!=0)
// //         {
// //             col[x]=1;
// //             ans+=n-1;
// //         }
        
// //     }
// //     cout<<ans;
// //     return 0;
// // }


// //思路：记录有车的行和列
// //交叉点的个数=（有车的行）*有车的列
// //总共被攻击点数量=（被攻击点行）*n+（被攻击点列）*n-交叉点的个数
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,k;
// const int N=1e6+11;
// int x[N];//记录有车的行
// int y[N];//记录有车的列
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=0;i<k;i++)
//     {
//         int x1,y1;cin>>x1>>y1;
//         x[i]=x1;
//         y[i]=y1;
//     }
//     sort(x,x+k);
//     sort(y,y+k);
//     int size_x=unique(x,x+k)-x;
//     int size_y=unique(y,y+k)-y;//指针相减 使用unique之前要保证数组有序
//     int ans=0;
//     cout<<size_x*n+size_y*n-size_x*size_y;
//     return 0;
// }


