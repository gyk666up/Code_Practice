#include<bits/stdc++.h>
using namespace std;
const int N=1e3+66;
int g[N][N];//a->b的代价（怪兽的能量）
int w[N][N];//a->b的武器价值
int pre[N];//回溯找出最短路径
bool st[N];//判断是否访问过这个节点了
int n,m;
int dist[N];//距离起点的距离
int price[N];//这一条路径的武器价值总和
int min_dist=0x3f3f3f3f;
int Dijkstra(int u)
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    int res=-0x3f3f3f3f;//记录最长的最近距离
    dist[u]=0;
    for(int i=1;i<=n;i++)
    {
        int chosencity=-1,chosenvalue=0x3f3f3f3f;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&dist[j]<chosenvalue)
            {
                chosencity=j;
                chosenvalue=dist[j];
            }
        }
        if(chosencity==-1)break;//全都访问了一遍
        st[chosencity]=1;
        res=max(res,dist[chosencity]);//!!!
        if(res>min_dist)break;//已经大于了当前的最小值
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&dist[j]>dist[chosencity]+g[chosencity][j])
            {
                dist[j]=dist[chosencity]+g[chosencity][j];
                //pre[j]=chosencity;
            }
        }
    }
    return res;
}
void Dijkstra2(int u)//找到最省力的路径且武器价值最大（有点像天梯赛的那道题）
{
    //初始化上一个Dijkstra
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    
    dist[u]=0;
    for(int i=1;i<=n;i++)
    {
        int chosencity=-1,chosenvalue=0x3f3f3f3f;
        for(int j=1;j<=n;j++)
        {
            if(!(st[j])&&dist[j]<chosenvalue)
            {
                chosencity=j;
                chosenvalue=dist[j];
            }
        }
        if(chosencity==-1)break;
        st[chosencity]=1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&dist[j]>dist[chosencity]+g[chosencity][j])
            {
                dist[j]=dist[chosencity]+g[chosencity][j];
                pre[j]=chosencity;
                price[j]=price[chosencity]+w[chosencity][j];
            }   
            else if(!st[j]&&dist[j]==dist[chosencity]+g[chosencity][j]&& price[j]<price[chosencity]+w[chosencity][j])
            {
                pre[j]=chosencity;
                price[j]=price[chosencity]+w[chosencity][j];
            }
        }
    }
    
}
int best_st=-1;//最好的出发点
void print(int p)
{
	if(p==best_st)
	{
		cout<<p;
		return;
	}
	print(pre[p]);
	cout<<"->"<<p;
	return;
}
int main()
{
    //当cout 和printf混合使用时这两行代码要小心 很容易改变原先的输出顺序
   // ios::sync_with_stdio(0);
    //cin.tie(0),cout.tie(0);
    cin>>n>>m;
    
    memset(g,0x3f,sizeof g);
	
    int temp=m;
    while(temp--)//避免后续用到m时出错
    {
        int x,y,a,b;cin>>x>>y>>a>>b;
        g[x][y]=g[y][x]=a;
        w[x][y]=w[y][x]=b;
    }
   
    for(int i=1;i<=n;i++)
    {
        int dist=Dijkstra(i);
        //这里有个小细节：题目中要求如果路径不唯一选编号小的 这里一个<就解决了问题
        if(dist<min_dist)
        {
            min_dist=dist;
            best_st=i;
        }
    }
    printf("%d\n",best_st);
    Dijkstra2(best_st);

    int k;cin>>k;
    while(k--)
    {
        int x;cin>>x;
		print(x);
        cout<<endl;
		cout<<dist[x]<<" "<<price[x]<<endl;
    }
	return 0;
}