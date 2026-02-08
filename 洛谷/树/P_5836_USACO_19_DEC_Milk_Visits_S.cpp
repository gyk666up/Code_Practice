//隐隐约约感觉是lca
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// vector<int>g[N];
// int n,m;
// char milk[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     cin>>milk+1;
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     return 0;
// }



//方法一
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 100000 + 5;
// vector<int> g[N];
// int n, m;
// string s;
// int comp[N];        // 每个点所属的连通块编号
// int cnt = 0;        // 连通块数量
// bool vis[N];

// void dfs(int u, int id) {
//     vis[u] = true;
//     comp[u] = id;
//     for (int v : g[u]) {
//         if (!vis[v] && s[v] == s[u]) {
//             dfs(v, id);
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> m;
//     cin >> s;
//     s = " " + s; // 1-index

//     for (int i = 1; i < n; i++) {
//         int x, y;
//         cin >> x >> y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }

//     // 建立同色连通块
//     for (int i = 1; i <= n; i++) {
//         if (!vis[i]) {
//             dfs(i, ++cnt);
//         }
//     }

//     // 处理查询
//     while (m--) {
//         int a, b;
//         char c;
//         cin >> a >> b >> c;

//         if (s[a] == c) {
//             cout << '1';
//         } else if (comp[a] != comp[b]) {
//             cout << '1';
//         } else {
//             cout << '0';
//         }
//     }

//     cout << '\n';
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1e5+44;
// vector<int>g[N];
// int comp[N];//联通块 相同的牛一个联通块
// bool vis[N];
// string s;
// int cnt;
// //一个联通块中颜色一定是相同的，但相同颜色的牛不一定在同一个联通块内（因为不一定连着）
// //同一个连通块（编号相同）里的所有节点，颜色不仅必须一样，而且它们之间连在一起的路径上，全是这个颜色的。
// void dfs(int x,int cnt)
// {
//     comp[x]=cnt;
//     vis[x]=1;
//     for(int i=0;i<g[x].size();i++)
//     {
//         int y=g[x][i];
//         if(!vis[y]&&s[y]==s[x])
//         {
//             dfs(y,cnt);
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     cin>>s;
//     s=" "+s;//1_based
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!vis[i])
//         {
//             dfs(i,++cnt);//不同的联通块不同的编号
//         }
//     }
// // 如果 $x$ 和 $y$ 还能穿一条裤子（编号相同），说明它俩中间没有任何障碍（异色牛）。
// // 只要中间敢有一个异色牛，它俩的裤子立马就得撕开（编号不同）！
//     while(m--)
//     {
//         int x,y;char c;cin>>x>>y>>c;
//         //if(s[x]=='c')cout<<'1';
//         if(s[x]==c)cout<<'1';
//         else if(comp[x]!=comp[y])cout<<'1';//情况 B：s[x] != c 但是 comp[x] != comp[y]
//         else cout<<'0';//情况 C：else (即 s[x] != c 且 comp[x] == comp[y])
//     }
//     return 0;
// }










// // //方法二
// // // 这一棵树只有两种颜色，故我们只要记录树上一个个颜色相同的连通块，
// // // 只有当所查询两点是同一连通块且连通块颜色与目标颜色不同时输出0。
// #include<bits/stdc++.h>
// using namespace std;
// int fa[100010],ans[100010],M,N;
// char col[100010];
// int find(int x)
// {
// 	if(x==fa[x])	return x;
// 	return fa[x]=find(fa[x]);
// }
// void merge(int x,int y)
// {
// 	fa[find(x)]=find(y);
// }
// int main()
// {
// 	int cnt=0;
// 	cin>>N>>M;
// 	for(int i=1;i<=N;i++)
// 	{
// 		fa[i]=i;
// 		cin>>col[i];
// 	}	
// 	for(int i=1;i<=N-1;i++)
// 	{
// 		int u,v;cin>>u>>v;
// 		if(col[u]==col[v])	merge(u,v);
// 	}
// 	for(int i=1;i<=M;i++)
// 	{
// 		int a,b;	cin>>a>>b;
// 		char c;		cin>>c;

//      这里的判断条件比上面的更加简洁一点 正难则反
// 		if(find(a)==find(b)&&col[a]!=c)		ans[++cnt]=0;//判断路径上是否有偏好的牛奶
// 		else	ans[++cnt]=1;
// 	}
// 	for(int i=1;i<=cnt;i++)	cout<<ans[i];
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+66;
int fa[N];
char s[N];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy)return ;
    fa[yy]=xx;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)fa[i]=i;

    for(int i=0;i<n-1;i++)
    {
        int x,y;cin>>x>>y;
        if(s[x]==s[y])merge(x,y);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;char c;cin>>a>>b>>c;
        if(find(a)==find(b)&&s[a]!=c)cout<<0;
        else cout<<1;
    }
    return 0;
}