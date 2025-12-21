//不熟
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e3+66;
// struct node
// {
//     int x,y;
//     bool f=1;
// }edge[N];
// int fa[N];
// int find(int x)
// {
//     if(fa[x]==x)return x;
//     return fa[x]=find(fa[x]);
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)return;
//     fa[yy]=xx;
// }
// int main()
// {
//     //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//     int n,m;cin>>n>>m;
//     for(int i=0;i<n;i++)fa[i]=i;
//     for(int i=0;i<m;i++)
//     {
//         cin>>edge[i].x>>edge[i].y;
//         merge(edge[i].x,edge[i].y);
//     }
//     int land=0;//记录多少连通的区域
//     for(int i=0;i<n;i++)
//     {
//         if(fa[i]==i)land++;
//     }
//     int k;cin>>k;
//     int temp=k;
//     while(temp--)
//     {
//         int nowland=0;
//         int lostcity=-1;cin>>lostcity;
//         for(int i=0;i<m;i++)
//         {
//             if(edge[i].x==lostcity||edge[i].y==lostcity)
//             {
//                 edge[i].f=0;
//             }
//         }
//         for(int i=0;i<n;i++)fa[i]=i;
//         for(int i=0;i<m;i++)
//         {
//             if(edge[i].f)
//             {
//                 merge(edge[i].x,edge[i].y);
//             }

//         }
//         for(int i=0;i<n;i++)
//         {
//             if(fa[i]==i)
//             nowland++;
//         }
//         if(nowland-land>=2)
//         printf("Red Alert: City %d is lost!\n",lostcity);
//         else
//         printf("City %d is lost.\n",lostcity);
//        land= nowland;
//     }
//     if(k==n)cout<<"Game Over.\n";
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
const int N=5e3+66;
int g[N][N];
bool vis[N];
int n,m;
int cnt=0;
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<n;i++)
    {
        if(g[i][x]==1&&!vis[i])
        {
            dfs(i);
        }
    }
}
int sum_()
{
    int cnt=0;
    memset(vis,0,sizeof vis);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        g[x][y]=g[y][x]=1;   
    }
    int k;cin>>k;
    int land=sum_();
    int temp=k;
    while(temp--)
    {
        int lostcity;cin>>lostcity;
        for(int i=0;i<n;i++)
        g[lostcity][i]=g[i][lostcity]=0;

        int nowland=sum_();
        if(nowland-land>=2)
	 	{
	 		cout<<"Red Alert: City "<<lostcity<<" is lost!\n"; 
	 	}
	 	else 
        cout<<"City "<<lostcity<<" is lost.\n";
	 	land=nowland;
	}
	if(k==n)cout<<"Game Over.\n";
	return 0;
}





























