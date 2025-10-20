#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int s1,s2,f1,f2;
const int N=20;
bool st[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
typedef pair<int,int>PII;
int ans=0;
//st[]有两种放的位置 ~！！！
void dfs(int x,int y)
{
    if(x==f1&&y==f2)
    {
        ans++;
        return ;
    }
    //st[x][y]=1;//1
    for(int i=0;i<4;i++)
    {
        int xx=dx[i]+x;
        int yy=dy[i]+y;
        if(xx<1||xx>n||yy<1||yy>m)continue;
        if(st[xx][yy])continue;
        st[xx][yy]=1;//2
        dfs(xx,yy);
        st[xx][yy]=0;//注意这行代码 //1 2
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>t;
    cin>>s1>>s2>>f1>>f2;
    //将障碍物点直接标记成已经访问过了
    for(int i=1;i<=t;i++)
    {
        int x,y;cin>>x>>y;
        st[x][y]=1;
    }
    st[s1][s2]=1;//2
    dfs(s1,s2);
    cout<<ans;
    return 0;
}