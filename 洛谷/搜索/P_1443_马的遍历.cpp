#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
int ans[402][403];
typedef pair<int,int>PII;
void bfs(int x,int y)
{
    ans[x][y]=0;
    queue<PII>q;
    q.push({x,y});
    while(q.size())
    {
        int a=q.front().first,b=q.front().second;q.pop();
        for(int i=0;i<8;i++)
        {
            int xx=a+dx[i];
            int yy=b+dy[i];
            if(xx<1||xx>n||yy<1||yy>m)continue;
            if(ans[xx][yy]>0)continue;
            ans[xx][yy]=ans[a][b]+1;
            q.push({xx,yy});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>x>>y;
    bfs(x,y);
    
    //注意这个起点位置
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==x&&y==j)
            {
                cout<<0<<" ";
                continue;
            }
            if(ans[i][j])cout<<ans[i][j]<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;
    }
    return 0;
}