// // #include<bits/stdc++.h>
// // using namespace std;
// // int distx,disty,Mx,My;
// // //不能走的位置
// // bool mark(int x,int y)
// // {
// //     if(x==Mx&&y==My)return false;
// //     if(x==Mx+2&&y==My+1||x==Mx-2&&y==My-1)return false;
// //     else if(x==Mx+1&&y==My+2||x==Mx-1&&y==My-2)return false;
// //     else if(x==Mx-1&&y==My+2||x==Mx+1&&y==My-2)return false;
// //     else if(x==Mx-2&&y==My+1||x==Mx+2&&y==My-1)return false;

// //     return true;
// // }
// // const int N=40;
// // bool st[N][N];
// // int dx[]={1,0};
// // int dy[]={0,1};
// // int ans=0;
// // bool isvalid(int x,int y)
// // {
    
// //     if(!mark(x,y))return false;
// //     if(x<0||x>distx||y<0||y>disty||st[x][y])return false;
// //     return 1;
// // }
// // void dfs(int x,int y)
// // {
// //     if(x==distx&&y==disty)
// //     {
// //         ans++;
// //         return;
// //     }
// //     st[x][y]=1;
// //     for(int i=0;i<2;i++)
// //     {
// //         int xx=x+dx[i],yy=y+dy[i];
// //         if(isvalid(xx,yy))
// //         {
// //             dfs(xx,yy);
// //         }
// //     }
// //     st[x][y]=0;
    
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>distx>>disty>>Mx>>My;
// //     dfs(0,0);    
// //     cout<<ans<<endl;
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=3000;
// bool st[N][N];//标记不能走的位置
// int dp[N][N];
// int dx[8]={-1,-2,-2,-1,1,2,2,1},dy[8]={-2,-1,1,2,2,1,-1,-2};
// int main()
// {
//     int n,m,x,y;cin>>n>>m>>x>>y;
//     st[x][y]=1;//马的位置
//     for(int i=0;i<8;i++)
//     {
//         if(x+dx[i]>=0&&x+dx[i]<=n&&y+dy[i]>=0&&y+dy[i]<=m)
//         st[x+dx[i]][y+dy[i]]=1;
//     }
    
//     dp[0][0]=1;
//     //到达i，j有两种方式 向右移动 向下移动
//     //dp[i][j]=dp[i-1][j]+dp[i][j-1]
//     //但是要注意不要越界
//     //

//     //到底哪里还有问题！！！ int太小 溢出加上 #define int long long
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             if(st[i][j])continue;
//             if(i==0&&j==0)continue;//!!!起点不能在转移了
//             if(i-1<0)dp[i][j]=dp[i][j-1];
//             else if(j-1<0)dp[i][j]=dp[i-1][j];
//             else 
//             {
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//         }
//     }
//     cout<<dp[n][m];
//     return 0;
// }




//2025/8/19
#include<bits/stdc++.h>
using namespace std;
int n,m,mx,my;
int dx[]={2,2,1,1,-2,-2,-1,-1};
int dy[]={-1,1,2,-2,-1,1,2,-2};
int dp[30][30];
bool isvalid(int x,int y)
{
    if(x==mx&&y==my)return false;
    else{
        for(int i=0;i<8;i++)
        {
            if(x==mx+dx[i]&&y==my+dy[i])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>mx>>my;
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            if(isvalid(i,j))
            {
                if(i==0&&j==0)continue;
                if(i-1<0)dp[i][j]=dp[i][j-1];
                else if(j-1<0)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
    }
    cout<<dp[n][m];
    return 0;
}