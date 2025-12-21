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





#include<bits/stdc++.h>
using namespace std;
const int N=1e5+66;
vector<int>g[N];
int n,m;
string s;
int comp[N];//每个点的联通块编号
int cnt;
bool vis[N];
void dfs(int u,int id)
{
    vis[u]=1;
    comp[u]=id;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!vis[v]&&s[v]==s[u])
        {
            dfs(v,id);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=0;i<n-1;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    //按照不同的牛奶分成不同的联通块
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,++cnt);
        }
    }

    while(m--)
    {
        int a,b;
        char c;cin>>a>>b>>c;
        if(s[a]==c)cout<<'1';
        else if(comp[a]!=comp[b])//跨块了，说明有不同类型的牛奶，那么就一定能满足朋友，因为一共就两种牛奶
        {
            cout<<'1';
        }
        else cout<<'0';
    }
    return 0;
}








// //方法二
// // 这一棵树只有两种颜色，故我们只要记录树上一个个颜色相同的连通块，
// // 只有当所查询两点是同一连通块且连通块颜色与目标颜色不同时输出0。
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
// 		if(find(a)==find(b)&&col[a]!=c)		ans[++cnt]=0;//判断路径上是否有偏好的牛奶
// 		else	ans[++cnt]=1;
// 	}
// 	for(int i=1;i<=cnt;i++)	cout<<ans[i];
// 	return 0;
// }
