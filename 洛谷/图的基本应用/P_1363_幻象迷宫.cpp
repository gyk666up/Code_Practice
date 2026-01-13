// // //在无限平铺迷宫中，只要在 BFS 中第二次到达同一个模坐标但真实坐标不同，就一定能走到无限远

// // #include <bits/stdc++.h>
// // using namespace std;

// // const int dx[4] = {1, -1, 0, 0};
// // const int dy[4] = {0, 0, 1, -1};

// // int n, m;
// // vector<string> mp;

// // // 记录：某个 (x mod n, y mod m) 第一次到达时的真实坐标
// // // 若之后再次到达同一模坐标但真实坐标不同 => 可以无限走
// // pair<int,int> vis[1505][1505];//vis[ xm ][ ym ] = 第一次到达这个模坐标时的真实坐标

// // bool used[1505][1505];

// // int mod(int x, int m) {
// //     return (x % m + m) % m;
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     while (cin >> n >> m) {
// //         mp.resize(n);
// //         for (int i = 0; i < n; i++) {
// //             cin >> mp[i];
// //         }

// //         // 找起点 S
// //         int sx = -1, sy = -1;
// //         for (int i = 0; i < n; i++) {
// //             for (int j = 0; j < m; j++) {
// //                 if (mp[i][j] == 'S') {
// //                     sx = i;
// //                     sy = j;
// //                 }
// //             }
// //         }

// //         // 初始化
// //         memset(used, false, sizeof used);

// //         queue<pair<int,int>> q;
// //         q.push({sx, sy});
// //         used[sx][sy] = true;
// //         vis[sx][sy] = {sx, sy};  // 模坐标 (sx,sy) 对应真实坐标 (sx,sy)

// //         bool ok = false;

// //         while (!q.empty() && !ok) {
// //             auto [x, y] = q.front(); q.pop();

// //             for (int d = 0; d < 4; d++) {
// //                 int nx = x + dx[d];
// //                 int ny = y + dy[d];

// //                 int mx = mod(nx, n);
// //                 int my = mod(ny, m);

// //                 if (mp[mx][my] == '#') continue;

// //                 if (!used[mx][my]) {
// //                     used[mx][my] = true;
// //                     vis[mx][my] = {nx, ny};
// //                     q.push({nx, ny});
// //                 } else {
// //                     // 关键判定：同一模坐标，但真实坐标不同
// //                     if (vis[mx][my].first != nx ||
// //                         vis[mx][my].second != ny) {
// //                         ok = true;
// //                         break;
// //                     }
// //                 }
// //             }
// //         }

// //         cout << (ok ? "Yes\n" : "No\n");
// //     }

// //     return 0;
// // }



// #include<bits/stdc++.h>
// using namespace std;
// const int N=1503;
// typedef pair<int,int>PII;
// int dx[]={0,1,0,-1};
// int dy[]={1,0,-1,0};
// PII vis[N][N];//vis[x][y] 第一次模坐标对应的真实坐标
// bool st[N][N];//标记这个模坐标走过没有
// int n,m;
// char s[N][N];
// int mod(int x,int y)
// {
//     return (x%y+y)%y;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     while(cin>>n>>m)
//     {
//         memset(s,0,sizeof s);
//         memset(st,0,sizeof st);
//         int stx,sty;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 cin>>s[i][j];
//                 if(s[i][j]=='S')
//                 {
//                     stx=i,sty=j;
//                 }
//             }
//         }
//         queue<PII>q;//队列存的是：真实坐标
//         q.push({stx,sty});
//         st[stx][sty]=1;
//         vis[stx][sty]={stx,sty};
//         int ok=0;
//         while(q.size()&&!ok)
//         {
//             auto t=q.front();q.pop();
//             int x=t.first,y=t.second;
//             for(int i=0;i<4;i++)
//             {
//                 int nowx=x+dx[i];
//                 int nowy=y+dy[i];

//                 int modx=mod(nowx,n);
//                 int mody=mod(nowy,m);

//                 //障碍物 不能走
//                 //这里容易写错 不是s[nowx][nowy] 会越界
//                 if(s[modx][mody]=='#')continue;
//                 if(!st[modx][mody])
//                 {
//                     st[modx][mody]=1;
//                     vis[modx][mody]={nowx,nowy};
//                     q.push({nowx,nowy});//「第一次到达」才压队列
//                 }
//                 else//不是第一次到达这个模坐标
//                 {
//                     if(nowx!=vis[modx][mody].first||nowy!=vis[modx][mody].second)
//                     {
//                         ok=1;
//                         break;
//                     }
//                 }
//             }
//         }
//         cout<<(ok==1?"Yes\n":"No\n");
//     }
//     return 0;
// }


//思路当走到一个模坐标相同但实际坐标不同的点 就说明可以到达无限远
#include<bits/stdc++.h>
using namespace std;
const int N=2000;
bool st[N][N];
typedef pair<int,int>PII;
PII vis[N][N];
char s[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int mod(int x,int y)
{
    return (x%y+y)%y;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    while(cin>>n>>m){
    memset(s,0,sizeof s);
    memset(st,0,sizeof st);
    int stx=-1,sty=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='S')
            {
                stx=i,sty=j;
            }
        }
    }
    queue<PII>q;
    q.push({stx,sty});
    st[stx][sty]=1;
    vis[stx][sty]={stx,sty};
    bool ok=0;
    while(q.size()&&!ok)
    {
        auto t=q.front();q.pop();
        int x=t.first,y=t.second;
        for(int i=0;i<4;i++)
        {
            int xx=dx[i]+x;
            int yy=dy[i]+y;
            
            int modx=mod(xx,n);
            int mody=mod(yy,m);
            //if(s[xx][yy]=='#')continue;

            if(s[modx][mody]=='#')continue;
            if(!st[modx][mody])
            {
                st[modx][mody]=1;
                vis[modx][mody]={xx,yy};
                //q.push({modx,mody});
                q.push({xx,yy});//压入真实坐标
            }
            else
            {
                if(vis[modx][mody].first!=xx||vis[modx][mody].second!=yy)
                {
                    ok=1;
                    break;
                }
            }
        }
    }
    if(ok)cout<<"Yes\n";
    else cout<<"No\n";
}
    return 0;
}