//这道题还可以  秒了！！

#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=102;
char g[N][N];
int land=0;
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,-1,1,0,1,-1,0};
bool st[N][N];//地图染色问题：遍历，将相邻的水糖看成一个颜色
void dfs(int x,int y)
{
    //不用回溯
    st[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int xx=dx[i]+x;
        int yy=dy[i]+y;
        if(xx<1||xx>n||yy<1||yy>m)continue;
        if(!st[xx][yy]&&g[xx][yy]=='W')
        dfs(xx,yy);
    }

    //不用写 st[x][y]=0
    return;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cin>>g[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!st[i][j]&&g[i][j]=='W')
            {
                land++;
                dfs(i,j);
            }
        }
    }
    cout<<land;
    return 0;
}