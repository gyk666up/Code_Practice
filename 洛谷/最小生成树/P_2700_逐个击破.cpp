// // //并查集反过来 有点方向 但还是不对
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1e5+11;
// // struct Edge
// // {
// //     int x,y,w;
// //     bool operator<(const Edge&u)
// //     {
// //         return w<u.w;
// //     }
// // };
// // int fa[N];
// // int n,k;
// // int find(int x)
// // {
// //     if(x==fa[x])return x;
// //     return fa[x]=find(fa[x]);
// // }
// // void merge(int x,int y)
// // {
// //     int xx=find(x),yy=find(y);
// //     if(xx==yy)return;
// //     fa[yy]=xx;
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>k;
// //     for(int i=1;i<=n;i++)fa[i]=i;
    
// //     bool first=1;
// //     int zu=-1;
// //     for(int i=0;i<k;i++)
// //     {
// //         int x;cin>>x;
// //         if(first)
// //         {
// //             first=0;
// //             zu=x;
// //             continue;
// //         }
// //         merge(zu,x);
// //     }
// //     vector<Edge>edge(n-1);
// //     for(int i=0;i<n-1;i++)
// //     {
// //         cin>>edge[i].x>>edge[i].y>>edge[i].w;
// //     }

// //     sort(edge.begin(),edge.end());

// //     int block=n-k+1;
// //     int ans=0;
// //     for(int i=0;i<edge.size();i++)
// //     {
// //         int x=edge[i].x,y=edge[i].y,w=edge[i].w;
// //         if(find(x)==find(y))//要破坏
// //         {
// //             fa[x]=x;
// //             fa[y]=y;
// //             ans+=w;
// //             block++;
// //         }
// //         if(block==n)break;
// //     }
// //     cout<<ans;
// //     return 0;
// // }


// // 正常 Kruskal 是：
// // 边从小到大
// // 能连就连
// // 目标：尽量连成一棵树
// // 本题是反过来：
// // 敌军所在城市一开始就必须“互相隔离”
// // 所以：
// // 👉 我们从“全不连”慢慢往“能连”走
// // 如果某条边 一旦连通了两个敌军集合
// // 👉 那这条边 必须切掉
// //让所有路都尽量保留，只有在“会让敌军连通”的那一刻，才被迫炸掉这条路，而且炸最便宜的。
// //这道题理解的还不是很好，并查集部分也很容易写错
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 100000 + 5;

// struct Edge {
//     int u, v, w;
//     bool operator < (const Edge& e) const {
//         return w >e.w;//!!!让它先挑贵的保，剩下的便宜路该炸就炸，
//     }
// };

// int n, k;
// int fa[N];
// bool hasEnemy[N];   // 该连通块是否包含敌军

// int find(int x) {
//     if (fa[x] == x) return x;
//     return fa[x] = find(fa[x]);
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> k;

//     // 初始化并查集
//     for (int i = 0; i < n; i++) {
//         fa[i] = i;
//         hasEnemy[i] = false;
//     }

//     // 标记敌军所在城市
//     for (int i = 0; i < k; i++) {
//         int x;
//         cin >> x;
//         hasEnemy[x] = true;
//     }

//     vector<Edge> edges(n - 1);
//     for (int i = 0; i < n - 1; i++) {
//         cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     }

//     // 按代价从小到大
//     sort(edges.begin(), edges.end());

//     long long ans = 0;

//     for (auto &e : edges) {
//         int fu = find(e.u);
//         int fv = find(e.v);

//         if (fu == fv) continue;

//         // 如果两个连通块都有敌军，则必须切断
//         if (hasEnemy[fu] && hasEnemy[fv]) {
//             ans += e.w;
//         } else {
//             // 否则可以合并
//             fa[fu] = fv;
//             hasEnemy[fv] |= hasEnemy[fu];//只要原来任意一个集合有敌军,合并后的集合就有敌军
//         }
//     }

//     cout << ans << '\n';
//     return 0;
// }


// // //注意城市的编号从0开始
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int fa[N];
// int hasEnemy[N];
// struct Edge
// {
//     int x,y,w;
//     bool operator<(const Edge&u)
//     {
//         return w>u.w;
//     }
// };
// int find(int x)
// {
//     if(fa[x]==x)return x;
//     return fa[x]=find(fa[x]);
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)return ;
//     fa[yy]=xx;
// }
// int n,k;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     vector<Edge>edge(n-1);
//     for(int i=0;i<n;i++)fa[i]=i;
//     for(int i=0;i<k;i++)
//     {
//         int x;cin>>x;
//         hasEnemy[x]=1;
//     }
//     for(int i=0;i<n-1;i++)
//     {
//         cin>>edge[i].x>>edge[i].y>>edge[i].w;
//     }
//     sort(edge.begin(),edge.end());

//     int ans=0;
// //     、、凡是集合属性（大小、颜色、敌军、权值）
// // —       —只存根，只看根，只改根
//     for(int i=0;i<n-1;i++)
//     {
//         int x=edge[i].x,y=edge[i].y,w=edge[i].w;
//         int xx=find(x),yy=find(y);
//         //这里很容易写错
//         // if(find(x)!=find(y))
//         // {
//         //     //两个联通块都有敌军->肯定不能让他们连一块
//         //     if(hasEnemy[x]&&hasEnemy[y])
//         //     {
//         //         ans+=w;
//         //     }
//         //     else
//         //     {
//         //         merge(x,y);
//         //         hasEnemy[x]|=hasEnemy[y];//x和y对应关系不要搞错了
//         //     }
//         // }
//         if(xx!=yy)
//         {
//             if(hasEnemy[xx]&&hasEnemy[yy])
//             {
//                 ans+=w;
//             }
//             else
//             {
//                 merge(xx,yy);
//                 hasEnemy[xx]|=hasEnemy[yy];
//             }
//         }
//     }
//     cout<<ans;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int fa[N];
struct Edge
{
    int x,y,w;
    bool operator<(const Edge&u)
    {
        return w>u.w;
    }
};
bool hasEnemy[N];
vector<Edge>edge;
int n,k;
int find(int x)
{
    if(fa[x]==x)return fa[x];
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy)return;
    fa[yy]=xx;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<=n;i++)fa[i]=i;
    for(int i=0;i<k;i++)
    {
        int x;cin>>x;
        hasEnemy[x]=1;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        edge.push_back({a,b,c});
    }
    sort(edge.begin(),edge.end());
    int ans=0;
    for(int i=0;i<edge.size();i++)
    {
        int u=find(edge[i].x),v=find(edge[i].y),w=edge[i].w;
        if(u!=v)
        {
            if(hasEnemy[u]&&hasEnemy[v])
            {
                ans+=w;
            }
            else
            {
                merge(u,v);
                //👉 hasEnemy 用在「并查集的根」上 只有根节点的hasEnemy才有意义
                hasEnemy[u]|=hasEnemy[v];
            }
        }
    }
    cout<<ans;
    return 0;
}