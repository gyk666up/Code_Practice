// // // // //最小二叉树

// // // //尝试一下暴力枚举 每个点都尝试一下建设医院 最后比较距离和最短的
// // // //最短路径问题  距离怎么写？
// // // // #include<bits/stdc++.h>
// // // // using namespace std;    
// // // // int n;
// // // // const int N=110;
// // // // int g[N][N];//两节点之间有路
// // // // int peo[N];//每个结点的人数
// // // // int ans=0x3f3f3f3f;
// // // // bool st[N];//记录这个城市有没有被访问过
// // // // void Dijkstra(int x,int length)
// // // // {
// // // //     memset(st,0,sizeof st);
// // // //     memset(dist,0x3f3f3f3f,sizeof dist);
// // // //     dist[x]=0;

// // // //     queue<int>q;
// // // //     q.push(x);
// // // //     while(q.size())
// // // //     {
// // // //         int chosencity=-1,chosenvalue=0x3f3f3f3f;
// // // //         for(int i=1;i<=n;i++)
// // // //         {
// // // //             int j=g[x][i];
// // // //             if(!st[j]&&dist[j]<chosenvalue)
// // // //             {
// // // //                 chosencity=j;
// // // //                 chosenvalue=dist[j];
// // // //             }
            
// // // //         }
// // // //         if(chosenvalue==-1)break;
// // // //         for(int j=1;j<=n;j++)
// // // //         {
// // // //             if(!st[j]&&dist[j]>dist[chosencity]+g[chosencity][j])
// // // //             {
// // // //                 dist[j]=dist[chosencity]+g[chosencity][i];
// // // //             }
// // // //         }
// // // //     }
    
// // // // }
// // // // int main()
// // // // {
// // // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // // //     cin>>n;
// // // //     for(int i=1;i<=n;i++)
// // // //     {
// // // //         int w,l,r;cin>>w>>l>>r;
// // // //         if(l)
// // // //         {
// // // //             g[i][j]=1;
// // // //             g[j][i]=1;
// // // //         }
// // // //         if(r)
// // // //         {
// // // //             g[i][r]=1;
// // // //             g[r][i]=1;
// // // //         }
// // // //         peo[i]=w;
// // // //     }
// // // //     for(int i=1;i<=n;i++)
// // // //     {
// // // //         Dijkstra(i);    
// // // //         int res=0;
// // // //         for(int i=1;i<=n;i++)
// // // //         {
// // // //             res+=dist[i];
// // // //         } 
// // // //         ans=min(ans,res);
// // // //     }
// // // //     cout<<ans;
// // // //     return 0;
// // // // }

// // // //floyd算法 n不大
// // // #include<cstdio>
// // // using namespace std;
// // // int a[101],g[101][101];
// // // int main()
// // // {
// // // 	int n,l,r,min,total;
// // // 	scanf("%d",&n);
// // // 注意这个很重要！！！初始化为无穷大
// // // 	for(int i=1;i<=n;i++)
// // // 	{
// // // 		for(int j=1;j<=n;j++)
// // // 		{
// // // 			g[i][j]=1000000;
// // // 		}
// // // 	}
// // // 	for(int i=1;i<=n;i++)//读入、初始化
// // // 	{
// // // 		g[i][i]=0;//!!!
// // // 		scanf("%d%d%d",&a[i],&l,&r);
// // // 		if(l>0)g[i][l]=g[l][i]=1;
// // // 		if(r>0)g[i][r]=g[r][i]=1; 
// // // 	}
// // // 	for(int k=1;k<=n;k++)//用Floyed求任意两结点之间的最短路径
// // // 	{
// // // 		for(int i=1;i<=n;i++)
// // // 		{
// // // 			if(i!=k)
// // // 			{
// // // 				for(int j=1;j<=n;j++)
// // // 				{
// // // 					if(i!=j&&k!=j&&g[i][k]+g[k][j]<g[i][j])
// // // 						g[i][j]=g[i][k]+g[k][j];
// // // 				}
// // // 			}
// // // 		}
// // // 	}
// // // 	min=0x7fffffff;
// // // 	for(int i=1;i<=n;i++)//穷举医院建在N个结点，找出最短距离
// // // 	{
// // // 		total=0;
// // // 		for(int j=1;j<=n;j++)
// // // 			total+=g[i][j]*a[j];
// // // 		if(total<min)min=total;
// // // 	}
// // // 	printf("%d",min);
// // // 	return 0;
// // // }


// //正解

// //这个不熟！！！
// //树的重心最多有两个且这两个是相邻的结点！！！结果一样
// #include <cstdio>
// #include <cstring>
// using namespace std;
// #define MAXN 1001  // 最大节点数（略大于题目限制100）
// int n, cnt, tot, ans, sum;
// // head/next/to：邻接表存储树（双向边）
// // val[u]：节点u的人口数
// // size[u]：以u为根的子树的总人数（包括u自身）
// // dis[u]：节点u到医院的距离
// // f[u]：节点u的父节点（避免DFS时回退）
// int head[MAXN], next[MAXN], to[MAXN], val[MAXN], size[MAXN], dis[MAXN], f[MAXN];
// inline void add(int x, int y) {
//     to[cnt] = y;          // 第cnt条边指向y
//     next[cnt] = head[x];  // 链表结构：第cnt条边的下一条是x当前的第一条边
//     head[x] = cnt++;      // x的第一条边更新为第cnt条边
// }
// //计算子树大小并找树的重心
// inline void dfs(int u) {
//     size[u] += val[u];  // 子树大小初始化为自身人口
//     for (int i = head[u]; i != -1; i = next[i]) {  // 遍历u的所有邻接节点
//         int v = to[i];
//         //下面f数组的用法挺绕的
//         if (v != f[u]) {  // 排除父节点（避免循环访问）
//             f[v] = u;     // 记录v的父节点是u
//             dfs(v);       // 递归计算子树v的大小
//             size[u] += size[v];  // u的子树大小 += v的子树大小
//         }
//     }
//     // 找树的重心：第一个满足“子树大小×2 ≥ 总人数”的节点
//     if (2 * size[u] >= tot && !ans) ans = u;
// }

// //计算重心作为医院时的总路程
// inline void dfs1(int u) {
//     //这个也很细节
//     // dis[u]是从医院到u的距离（初始医院节点dis=1，因此实际距离是dis[u]-1）
//     sum += (dis[u] - 1) * val[u];  // 累加“当前节点人口 × 距离”
//     for (int i = head[u]; i != -1; i = next[i]) {  // 遍历邻接节点
//         int v = to[i];
//         if (!dis[v]) {  // 未计算距离的节点（避免重复访问父节点）
//             dis[v] = dis[u] + 1;  // 距离=父节点距离+1
//             dfs1(v);  // 递归计算子节点
//         }
//     }
// }

// int main() {
//     int i, x, y;
//     scanf("%d", &n);
//     memset(head, -1, sizeof(head));  // 初始化邻接表（-1表示无后续边）
//     for (i = 1; i <= n; i++) {
//         scanf("%d %d %d", &val[i], &x, &y);  // 读入人口、左孩子、右孩子
//         // 若有左孩子x，添加双向边（i↔x）
//         if (x) add(i, x), add(x, i);
//         // 若有右孩子y，添加双向边（i↔y）
//         if (y) add(i, y), add(y, i);
//         tot += val[i];  // 累加总人数
//     }
//     dfs(1);  // 从节点1开始DFS，找树的重心ans
//     dis[ans] = 1;  // 医院节点的距离初始化为1（实际距离为0）
//     // printf("%dhhh",ans);
//     dfs1(ans);  // 计算以ans为医院时的总路程
//     printf("%d", sum);  // 输出最小总路程
//     return 0;
// }







#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int head[N],to[N],nex[N];
int siz[N],w[N];
int dist[N];
int fa[N];
int n,ans=0;
int cnt=0;
int total;
void add(int x,int y)
{
    to[cnt]=y;
    nex[cnt]=head[x];
    head[x]=cnt++;
}
void dfs(int x)
{
    siz[x]+=w[x];
    for(int i=head[x];i!=-1;i=nex[i])
    {
        int v=to[i];
        if(v!=fa[x])
        {
            fa[v]=x;
            dfs(v);
            siz[x]+=siz[v];
        }
    }
    if(2*siz[x]>=total&&!ans)ans=x;
}
int sum=0;
void dfs1(int x)
{
    sum+=(dist[x]-1)*w[x];
    for(int i=head[x];i!=-1;i=nex[i])
    {
        int v=to[i];
       if(!dist[v])
        {
            dist[v]=dist[x]+1;
            dfs1(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    memset(head,-1,sizeof head);
    for(int i=1;i<=n;i++)
    {
        int W,u,v;cin>>W>>u>>v;
        w[i]=W;
        if(u)add(i,u),add(u,i);
        if(v)add(i,v),add(v,i);
        total+=w[i];
    }
    dfs(1);
    dist[ans]=1;
    dfs1(ans);
    cout<<sum;
    return 0;
}






























