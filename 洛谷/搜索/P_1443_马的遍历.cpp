// #include<bits/stdc++.h>
// using namespace std;
// int n,m,x,y;
// int dx[]={2,2,-2,-2,1,1,-1,-1};
// int dy[]={1,-1,1,-1,2,-2,2,-2};
// int ans[402][403];
// typedef pair<int,int>PII;
// void bfs(int x,int y)
// {
//     ans[x][y]=0;
//     queue<PII>q;
//     q.push({x,y});
//     while(q.size())
//     {
//         int a=q.front().first,b=q.front().second;q.pop();
//         for(int i=0;i<8;i++)
//         {
//             int xx=a+dx[i];
//             int yy=b+dy[i];
//             if(xx<1||xx>n||yy<1||yy>m)continue;
//             if(ans[xx][yy]>0)continue;
//             ans[xx][yy]=ans[a][b]+1;
//             q.push({xx,yy});
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>x>>y;
//     bfs(x,y);
    
//     //注意这个起点位置
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             if(i==x&&y==j)
//             {
//                 cout<<0<<" ";
//                 continue;
//             }
//             if(ans[i][j])cout<<ans[i][j]<<" ";
//             else cout<<-1<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


//NB 秒了 2025/12/19
#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
typedef pair<int,int>PII;
const int N=402;
int ans[N][N];
void bfs(int x,int y)
{
    //memset(ans,-1,sizeof ans);
    ans[x][y]=0;
    queue<PII>q;
    q.push({x,y});
    while(q.size())
    {
        int x=q.front().first;
        int y=q.front().second;q.pop();
        for(int i=0;i<8;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m)continue;
            if(ans[xx][yy]!=0)continue;

            ans[xx][yy]=ans[x][y]+1;
            q.push({xx,yy});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>x>>y;
    bfs(x,y);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        if(!ans[i][j])ans[i][j]=-1;
    }
    ans[x][y]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}