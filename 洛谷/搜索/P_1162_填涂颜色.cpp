//以前做过这道题 这道题做的也还可以
//思路：将地图扩展一圈 标记0的位置 因为扩展后的地图最外面都是0 0就分成两部分 1闭合圈外 和1闭合圈内的
#include<bits/stdc++.h>
using namespace std;
int n;
const int N=32;
int g[N][N];
bool st[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int x,int y)
{
    st[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int xx=dx[i]+x;
        int yy=dy[i]+y;
        //注意这个范围
        if(xx<0||xx>n+1||yy<0||yy>n+1)continue;
        if(st[xx][yy])continue;
        if(g[xx][yy]==0)dfs(xx,yy);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>g[i][j];
    }
    //我们把地图看出n+2,n+2
    dfs(0,0);
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        {
            if(st[i][j])g[i][j]=0;
            else if(!st[i][j]&&g[i][j]==0)g[i][j]=2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// //将地图扩展一圈 外面的0肯定是联通的将外面的0标记
// //遍历原来的地图 如果该位置是0且没有被标记则将该位置设置成1 
// //bfs
// #include<bits/stdc++.h>
// using namespace std;
// const int N=40;
// int g[N][N];
// int n;
// int st[N][N];//将外面联通的0标记出来
// typedef pair<int,int>PII; 
// int dx[]={0,0,1,-1};
// int dy[]={1,-1,0,0};
// void bfs(int x,int y)
// {
// 	st[x][y]=1;
// 	queue<PII>q;
// 	q.push({x,y});
// 	while(q.size())
// 	{
// 		auto t=q.front();q.pop();
// 		for(int i=0;i<4;i++)
// 		{
// 			int a=t.first+dx[i];
// 			int b=t.second+dy[i];
// 			if(a<0||a>n+1||b<0||b>n+1)continue;
// 			if(g[a][b]!=0)continue;//此路不通
// 			if(st[a][b])continue;//已经走过了 
// 			//上面这行代码经常忘记 
			
// 			st[a][b]=1; 
// 			q.push({a,b});
// 		}
// 	}
//  } 
// int main()
// {
// 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// 	cin>>n;
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=n;j++)
// 		{
// 			cin>>g[i][j];
// 		}
// 	}
// 	bfs(0,0);//!!!将地图扩展一下 
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=n;j++)
// 		{
// 			if(g[i][j]==0&&!st[i][j])
// 			cout<<2<<" ";
// 			else cout<<g[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	return 0;
// }
