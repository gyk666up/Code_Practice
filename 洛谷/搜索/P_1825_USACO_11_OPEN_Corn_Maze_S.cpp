// // 我自己的思路：大体思路应该是没有什么问题的，就是有点小问题 ->通过AI解决了
// // dfs不适合稠密图
// //仍然有两个点超时 
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=304;
// char g[N][N];
// int dist[N][N];
// bool st[N][N];
// int s1,s2,e1,e2;//标记起点和结束的位置
// int ans=0x3f3f3f3f;
// int dx[]={0,0,1,-1};
// int dy[]={1,-1,0,0};

// //建立一个字母和传送带的一个映射
// typedef pair<int,int>PII;
// map<char,vector<PII>>mp;//一个字母 对应两个坐标
// //传送装置该怎么处理 突然想到上面这样
// void dfs(int x,int y,int time)
// {
//     if(time>=ans)return;
//     if(time>=dist[x][y])return;//剪枝2：如果之前到达过(x,y)且时间更短，无需继续
//     dist[x][y]=time;
//     if(x==e1&&y==e2)
//     {
//         ans=min(ans,time);
//         return;
//     }
    
//     for(int i=0;i<4;i++)
//     {
//         int xx=dx[i]+x;
//         int yy=dy[i]+y;
//         //if(dist[xx][yy]!=0x3f3f3f3f)continue;//说明已经走过了
//         if(xx<1||xx>n||yy<1||yy>m)continue;
//         // if(st[xx][yy])continue;
//         if(g[xx][yy]=='#')continue;//不可以走 障碍物

//         if(isupper(g[xx][yy]))//是传送带 就必须走
//         {
//             int next_x,next_y;
//             for(auto t:mp[g[xx][yy]]) //找到传送带对应的另一个点
//             {
                
//                 if(t.first!=xx||t.second!=yy)//说明是另一个点
//                 {
//                      next_x=t.first;
//                      next_y=t.second;
//                 }
//             }
//             //// 剪枝：如果传送目标点已有更短路径，无需继续
//             if(time+1>=dist[next_x][next_y])continue;
//             dfs(next_x,next_y,time+1);//从一个点到传送带是需要花费1个单位时间的！！！从传送带到另一个传送带才不耗时间
//         }
//         //如果不是传送带 草地
//         else dfs(xx,yy,time+1);

        
//     }
    
//     //st[x][y]=0;

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     memset(dist,0x3f,sizeof dist);
//     //dist[s1][s2]=0;
//     //st[s1][s2]=1; 这个得放到读取地图之后！！！
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             cin>>g[i][j];
//             if(g[i][j]=='=')
//             {
//                 e1=i;e2=j;
//             }
//             else if(g[i][j]=='@')
//             {
//                 s1=i;s2=j;
//             }
//             else if(isupper(g[i][j])) //传送带
//             {
//                 mp[g[i][j]].push_back({i,j});
//             }
//         }
//     }
//     st[s1][s2]=1;
//     dfs(s1,s2,0);
//     cout<<ans;
//     return 0;
// }

//搞啦好久
#include<bits/stdc++.h>
using namespace std;
const int N=302;
char g[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
typedef pair<int,int>PII;
int dist[N][N];
int n,m;
map<char,vector<PII>>mp;
int s1,s2,e1,e2;
int bfs()
{
    dist[s1][s2]=0;
    queue<PII>q;
    q.push({s1,s2});
    while(q.size())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==e1&&y==e2)
        {
           return dist[e1][e2];
        }
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m)continue;
            //if(dist[xx][yy]!=0x3f3f3f3f)continue;
            if(g[xx][yy]=='#')continue;

            int cost=dist[x][y]+1;

            pair<int,int>next={xx,yy};
            if(isupper(g[xx][yy]))
            {
                for(auto t:mp[g[xx][yy]])
                {
                    if(t.first!=xx||t.second!=yy)
                    {
                        next=t;
                        break;
                    }
                }
            }
            //注意这段代码的位置
            if(dist[next.first][next.second]>cost)
            {
                dist[next.first][next.second]=cost;
                q.push(next);
            }
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='=')
            {
                e1=i,e2=j;
            }
            else if(isupper(g[i][j]))
            {
                mp[g[i][j]].push_back({i,j});
            }
            else if(g[i][j]=='@')
            {
                s1=i,s2=j;
            }
        }
    }
    memset(dist,0x3f,sizeof dist);
    cout<<bfs();
    return 0;
}