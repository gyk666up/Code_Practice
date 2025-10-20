// //先求出来每个奶酪到老鼠的距离
// //是不是可以不用bfs
// // #include<bits/stdc++.h>
// // using namespace std;
// // int n;
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     double ans=0x3f3f3f3f;
// //     for(int i=0;i<n;i++)
// //     {
// //         double x,y;cin>>x>>y;
// //         //double w=sqrt(pow(x^2)+pow(y^2));// ^ 不是 “平方” 运算符，而是 “按位异或”
// //         double w=sqrt(pow(x,2)+pow(y,2));
// //         ans=min(ans,w);
// //     }
// //     cout<<fixed<<setprecision(3)<<ans;
// //     return 0;
// // }

// //我的思路
// //题目说的是都吃掉 至少要跑
// //我感觉是dfs 而不是bfs
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=30;
// int g[N][N];
// bool st[N][N];
// double ans=0x3f3f3f3f;
// int dx[]={0,0,1,-1};
// int dy[]={1,-1,0,0};
// //这是一开始的思路 不过有问题
// // void dfs(int x,int y,int sheng,double dist)
// // {
// //     if(sheng==0) //都吃掉了
// //     {
// //         ans=min(ans,dist);
// //         return;
// //     }
// //     for(int i=0;i<4;i++)
// //     {
// //         int xx=x+dx[i];
// //         int yy=y+dy[i];
// //         if(xx<0||yy<0)continue;
// //         if(st[xx][yy])continue;

// //         int before=sheng;
// //         if(g[xx][yy])sheng--;
// //         st[xx][yy]=1;    //这里是+= 就意味着后续要回溯 在减去加上的距离 所以一般写+ 就会方便很多
// //         dfs(xx,yy,sheng,dist+=sqrt(pow(xx-x,2)+pow(yy-y,2)));
// //         //回溯
// //         st[xx][yy]=0;
// //         sheng=before;
        
// //     }
// //     return;
    
// // }
// void dfs(int x,int y,int sheng,double dist)
// {
//     st[x][y]=1;

//     int new_sheng=sheng;
//     if(g[x][y])new_sheng--;

//     if(new_sheng==0)
//     {
//         ans=min(ans,dist);
//         st[x][y]=0;
//         return;
//     }
//     for(int i=0;i<4;i++)
//     {
//         int xx=x+dx[i];
//         int yy=y+dy[i];
//         if(xx<0||xx>=N||yy<0||yy>=N)continue;//防止越界
//         if(st[xx][yy])continue;
//         dfs(xx,yy,new_sheng,dist+sqrt(pow(xx-x,2)+pow(yy-y,2)));
//          // st[x][y]=false;//回溯
//     }
  
//     st[x][y]=0;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x][y]=1;
//     }
//     dfs(0,0,n,0);
//     cout<<fixed<<setprecision(2)<<ans<<endl;
//     return 0;
// }


//上述代码完全是错误的
//老鼠是可以走直线的 不必走网格线
#include