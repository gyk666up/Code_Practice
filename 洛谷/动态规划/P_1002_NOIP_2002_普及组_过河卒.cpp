// //bfs 超时了 过两个点
// #include<bits/stdc++.h>
// using namespace std;
// int n,m,mx,my;
// const int N=30;
// int dx[]={1,1,-1,-1,-2,-2,2,2};
// int dy[]={2,-2,2,-2,1,-1,1,-1};
// bool st[N][N];//不能走的位置或者已经走过的位置
// typedef pair<int,int>PII;
// int ddx[]={1,0};
// int ddy[]={0,1};
// int ans=0;
// bool valid(int x,int y)
// {
//     if(x<0||x>n||y<0||y>m)return false;
//     if(st[x][y])return false;
//     return true;
// }
// void bfs()
// {
//     queue<PII>q;
//     q.push({0,0});
//     while(q.size())
//     {
//         int x=q.front().first,y=q.front().second;
//         q.pop();
//         if(x==n&&y==m)
//         {
//             ans++;
//             continue;
//         }
//         st[x][y]=1;
//         for(int i=0;i<2;i++)
//         {
//             int xx=ddx[i]+x;
//             int yy=ddy[i]+y;
//             if(valid(xx,yy))
//             {
//                 q.push({xx,yy});
//             }
            
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>mx>>my;
//     st[mx][my]=1;
//     for(int i=0;i<8;i++)
//     {
//         st[mx+dx[i]][my+dy[i]]=1;
//     }
    
//     bfs();
//     cout<<ans;
//     return 0;
// }


// //dfs
// #include<bits/stdc++.h>
// using namespace std;
// int n,m,mx,my;
// const int N=30;
// int dx[]={1,1,-1,-1,-2,-2,2,2};
// int dy[]={2,-2,2,-2,1,-1,1,-1};
// bool st[N][N];//不能走的位置或者已经走过的位置
// typedef pair<int,int>PII;
// int ddx[]={1,0};
// int ddy[]={0,1};
// int ans=0;
// bool valid(int x,int y)
// {
//     if(x<0||x>n||y<0||y>m)return false;
//     if(st[x][y])return false;
//     return true;
// }
// void dfs(int x,int y)
// {
//     if(x==n&&y==m)
//     {
//         ans++;
//         return;
//     }
    
//     //st[x][y]=1;
//     for(int i=0;i<2;i++)
//     {
//         int xx=ddx[i]+x;
//         int yy=ddy[i]+y;
//         if(valid(xx,yy))
//         {
//             dfs(xx,yy);
//         }
//     }
//     st[x][y]=0;//我草？！！！ 有点难理解
//     //DFS 里：“标记” 和 “取消标记” 必须成对出现
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>mx>>my;
//     st[mx][my]=1;
//     for(int i=0;i<8;i++)
//     {
//         st[mx+dx[i]][my+dy[i]]=1;
//     }
    
//     dfs(0, 0);
//     cout<<ans;
//     return 0;
// }

//dp

// #include<bits/stdc++.h>
// using namespace std;
// int n,m,mx,my;
// #define int long long
// const int N=30;
// int dx[]={1,1,-1,-1,-2,-2,2,2};
// int dy[]={2,-2,2,-2,1,-1,1,-1};
// bool st[N][N];//不能走的位置或者已经走过的位置
// typedef pair<int,int>PII;
// int ddx[]={1,0};
// int ddy[]={0,1};
// int ans=0;
// bool valid(int x,int y)
// {
//     if(x<0||x>n||y<0||y>m)return false;
//     if(st[x][y])return false;
//     return true;
// }
// int dp[N][N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>mx>>my;
//     st[mx][my]=1;
//     for(int i=0;i<8;i++)
//     {
//         st[mx+dx[i]][my+dy[i]]=1;
//     }
    
//     dp[0][0]=1;
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             if(i==0&&j==0)continue;
//             if(valid(i,j)==0)continue;
//             if(i<1)dp[i][j]=dp[i][j-1];
//             else if(j<1)dp[i][j]=dp[i-1][j];
//             else dp[i][j]=dp[i-1][j]+dp[i][j-1];
//         }
//     }
//     cout<<dp[n][m];
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=30;
// int n,m,mx,my;
// bool st[N][N];
// int dx[]={2,2,-2,-2,1,1,-1,-1};
// int dy[]={1,-1,1,-1,2,-2,2,-2};
// int ddx[]={0,1};
// int ddy[]={1,0};
// typedef pair<int,int>PII;
// int res=0;
// bool vaild(int x,int y)
// {
//     if(x<0||y<0||x>n||y>m)return false;//大于n，m也是不合法的
//     if(st[x][y])return false;

//     return true;
// }
// void bfs()
// {
//     queue<PII>q;
//     q.push({0,0});
//     st[0][0]=1;
//     while(q.size())
//     {
//         int x=q.front().first,y=q.front().second;q.pop();
//         if(x==n&&y==m)
//         {
//             res++;
//             continue;
//         }

//         st[x][y]=1;//只代表当前节点不能走了
//         for(int i=0;i<2;i++)
//         {
//             int xx=ddx[i]+x;
//             int yy=ddy[i]+y;
//             if(vaild(xx,yy))
//             {
//                 //st[xx][yy]=1;//这会导致子节点不能走
//                 q.push({xx,yy});
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>mx>>my;
//     st[mx][my]=1;
//     for(int i=0;i<8;i++)
//     {
//         int x=mx+dx[i],y=my+dy[i];
//         if(x<0||y<0||x>n||y>m)continue;
//         st[x][y]=1;
//     }
//     bfs();
//     cout<<res;
//     return 0;
// }

// //dfs
// #include<bits/stdc++.h>
// using namespace std;
// const int N=30;
// int n,m,mx,my;
// bool st[N][N];
// int dx[]={2,2,-2,-2,1,1,-1,-1};
// int dy[]={1,-1,1,-1,2,-2,2,-2};
// int ddx[]={0,1};
// int ddy[]={1,0};
// typedef pair<int,int>PII;
// int ans=0;
// bool vaild(int x,int y)
// {
//     if(x<0||y<0||x>n||y>m)return false;//大于n，m也是不合法的
//     if(st[x][y])return false;

//     return true;
// }
// void dfs(int x,int y)
// {
//     if(x==n&&y==m)
//     {
//         ans++;
//         return;
//     }

//     st[x][y]=1;
//     for(int i=0;i<2;i++)
//     {
//         int xx=ddx[i]+x;
//         int yy=ddy[i]+y;
//         if(vaild(xx,yy))
//         {
//             dfs(xx,yy);
//         }
//     }
//     st[x][y]=0;

//     return;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>mx>>my;
//     st[mx][my]=1;
//     for(int i=0;i<8;i++)
//     {
//         if(mx+dx[i]<0||mx+dx[i]>n||my+dy[i]<0||my+dy[i]>m)continue;
//         st[mx+dx[i]][my+dy[i]]=1;
//     }

//     dfs(0,0);

//     cout<<ans;
//     return 0;
// }


